for /d /r "%1" %%d in (.svn) do @if exist "%%d" rd /s/q "%%d" pause
pause