if exist "Debug/src" (
	rd /s /Q "Debug/src"
)
md "Debug/src"
copy "src\shader" "Debug/src" /y