@echo on

if "%1" == "" goto END
if "%2" == "" goto END

if NOT "%LIBSKYRIM_LIB%" == "" (
  if not exist "%LIBSKYRIM_LIB%" (
    mkdir "%LIBSKYRIM_LIB%"
  )
  xcopy /Y /Q %2 "%LIBSKYRIM_LIB%"
)


if NOT "%LIBSKYRIM_INCLUDE%" == "" (
  if not exist "%LIBSKYRIM_INCLUDE%" (
    mkdir "%LIBSKYRIM_INCLUDE%"
  )
  xcopy /Y /S /Q %1 "%LIBSKYRIM_INCLUDE%"
)

:END
