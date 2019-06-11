if exist "x64/Debug/src" (
	rd /s /Q "x64/Debug/src"
)
md "x64/Debug/src/shader"
copy "src\shader" "x64/Debug/src/shader" /y