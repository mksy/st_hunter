if exist %2\FF.bin %1\postbuild\elf2vkp.exe %2\drawhook.elf %2\temp.vkp %2\FF.bin
if not exist %2\FF.bin %1\postbuild\elf2vkp.exe %2\drawhook.elf %2\temp.vkp

if exist %2\drawhook.vkp del %2\drawhook.vkp

if exist %1\postbuild\header.txt copy /b %1\postbuild\header.txt+%2\temp.vkp %2\temp2.vkp
if exist %1\postbuild\header.txt if exist %3 copy /b %3+%2\temp2.vkp %2\drawhook.vkp
if exist %1\postbuild\header.txt if not exist %3 rename %2\temp2.vkp drawhook.vkp
if not exist %1\postbuild\header.txt rename %2\temp.vkp drawhook.vkp

del %2\temp.vkp
del %2\temp2.vkp
del %2\drawhook.elf


