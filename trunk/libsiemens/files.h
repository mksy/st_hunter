#ifndef _LIBS_FILES_H_
	#define _LIBS_FILES_H_

unsigned int FindFiles(DIR_ENTRY ***DE, const char *dir, const char *mask);
void DE_Free(DIR_ENTRY ***DE);
//-------сортировка----------//
void DE_Sort1(DIR_ENTRY ***DE);  //пузырьком
void DE_Sort1_With_Dirs(DIR_ENTRY ***DE); //пузырьком, но папки наверху

int GetExtByPath(char *dest, const char *path);
int GetFNameWithoutExt(char *dest, const char *fname);
void utf8_2fname(char *dest, const char *source);
	
#endif
