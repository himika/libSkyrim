@echo off
cd %~dp0

for %%I in (ruby ruby.com ruby.exe) do (
  if exist %%~$path:I if exist install_dll.rb (
    %%~$path:I install_dll.rb %1
    goto END
  )
)

for %%I in (perl perl.com perl.exe) do (
  if exist %%~$path:I if exist install_dll.pl (
    rem %%~$path:I install_dll.pl %1
    goto END
  )
)

for %%I in (python python.com python.exe) do (
  if exist %%~$path:I if exist install_dll.py (
    rem %%~$path:I install_dll.py %1
    goto END
  )
)


:END
