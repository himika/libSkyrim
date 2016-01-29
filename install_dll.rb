#
# Skyrimのインストール先を特定し、DLLをインストールするスクリプト
#

require 'fileutils'

if !ARGV[0] or !File.exist? ARGV[0]
	exit 1
end

def check(dir)
	path = dir + '/steamapps/appmanifest_72850.acf'
	
	return nil if !File.exist? path
	
	File.open(path) do |f|
		r = /^\s*"(app)?installdir"\s*("[^"]+")/
		f.each_line do |line|
			return dir + '/steamapps/common/' + eval($2) if r.match line
		end
	end
	nil
end


# レジストリからSteamのインストールフォルダを取得
steam_path =  `powershell -Command "return (Get-ItemProperty 'HKCU:\\SOFTWARE\\Valve\\Steam').SteamPath"`.chomp

# Skyrimがインストールされているフォルダを特定
skyrim_path = check(steam_path)
if skyrim_path.nil?
	vdf = steam_path + '/steamapps/libraryfolders.vdf'
	if File.exist? vdf
		File.open(vdf) do |f|
			r = /^\s*"\d+"\s*("[^"]+")/
			f.each_line do |line|
				if r.match line
					libdir = eval($1).gsub('\\', '/')
					skyrim_path = check(libdir)
					break if !path.nil?
				end
			end
		end
	end
end


# Skyrimが見つかればDLLをコピーする
if !skyrim_path.nil?
	skse_path = skyrim_path + '/Data/SKSE/Plugins'
	FileUtils.cp(ARGV[0], skse_path)
end
