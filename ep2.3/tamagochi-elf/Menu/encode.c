#include "..\inc\swilib.h"

const char wintranslation[128] =
{
	0x5F,0x5F,0x27,0x5F,0x22,0x3A,0xC5,0xD8,0x5F,0x25,0x5F,0x3C,0x5F,0x5F,0x5F,0x5F,
	0x5F,0x27,0x27,0x22,0x22,0x07,0x2D,0x2D,0x5F,0x54,0x5F,0x3E,0x5F,0x5F,0x5F,0x5F,
	0xFF,0xF6,0xF7,0x5F,0xFD,0x83,0xB3,0x15,0xF0,0x63,0xF2,0x3C,0xBF,0x2D,0x52,0xF4,
	0xF8,0x2B,'I' ,'i' ,0xA3,0xE7,0x14,0xFA,0xF1,0xFC,0xF3,0x3E,0x5F,0x5F,0x5F,0xF5,
	0x80,0x81,0x82,0x83,0x84,0x85,0x86,0x87,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,0x8F,
	0x90,0x91,0x92,0x93,0x94,0x95,0x96,0x97,0x98,0x99,0x9A,0x9B,0x9C,0x9D,0x9E,0x9F,
	0xA0,0xA1,0xA2,0xA3,0xA4,0xA5,0xA6,0xA7,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,0xAF,
	0xE0,0xE1,0xE2,0xE3,0xE4,0xE5,0xE6,0xE7,0xE8,0xE9,0xEA,0xEB,0xEC,0xED,0xEE,0xEF
};

const char koi8translation[128] =
{
	0x5F,0x5F,0x27,0x5F,0x22,0x3A,0xC5,0xD8,0x5F,0x25,0x5F,0x3C,0x5F,0x5F,0x5F,0x5F,
	0x5F,0x27,0x27,0x22,0x22,0x07,0x2D,0x2D,0x5F,0x54,0x5F,0x3E,0x5F,0x5F,0x5F,0x5F,
	0xFF,0xF6,0xF7,0xF1,0xF3,0x5F,'i' ,0xF5,0xF0,0x63,0xF2,0x3C,0xBF,0xA3,0x52,0xF4,
	0xF8,0x2B,0x5F,0xF0,0xF2,0xE7,'I' ,0xF4,0xF1,0xFC,0xF3,0x3E,0x5F,0x83,0x5F,0xF5,

	0xEE,0xA0,0xA1,0xE6,0xA4,0xA5,0xE4,0xA3,0xE5,0xA8,0xA9,0xAA,0xAB,0xAC,0xAD,0xAE,
	0xAF,0xEF,0xE0,0xE1,0xE2,0xE3,0xA6,0xA2,0xEC,0xEB,0xA7,0xE8,0xED,0xE9,0xE7,0xEA,
	0x9E,0x80,0x81,0x96,0x84,0x85,0x94,0x83,0x95,0x88,0x89,0x8A,0x8B,0x8C,0x8D,0x8E,
	0x8F,0x9F,0x90,0x91,0x92,0x93,0x86,0x82,0x9C,0x9B,0x87,0x98,0x9D,0x99,0x97,0x9A
};

const unsigned short dos2unicode[128] =
{
	0x0410,0x0411,0x0412,0x0413,0x0414,0x0415,0x0416,0x0417,
	0x0418,0x0419,0x041A,0x041B,0x041C,0x041D,0x041E,0x041F,
	0x0420,0x0421,0x0422,0x0423,0x0424,0x0425,0x0426,0x0427,
	0x0428,0x0429,0x042A,0x042B,0x042C,0x042D,0x042E,0x042F,
	0x0430,0x0431,0x0432,0x0433,0x0434,0x0435,0x0436,0x0437,
	0x0438,0x0439,0x043A,0x043B,0x043C,0x043D,0x043E,0x043F,
	0x002D,0x002D,0x002D,0x00A6,0x002B,0x00A6,0x00A6,0x00AC,
	0x00AC,0x00A6,0x00A6,0x00AC,0x002D,0x002D,0x002D,0x00AC,
	0x004C,0x002B,0x0054,0x002B,0x002D,0x002B,0x00A6,0x00A6,
	0x004C,0x0433,0x00A6,0x0054,0x00A6,0x003D,0x002B,0x00A6,
	0x00A6,0x0054,0x0054,0x004C,0x004C,0x002D,0x0433,0x002B,
	0x002B,0x002D,0x002D,0x002D,0x002D,0x00A6,0x00A6,0x002D,
	0x0440,0x0441,0x0442,0x0443,0x0444,0x0445,0x0446,0x0447,
	0x0448,0x0449,0x044A,0x044B,0x044C,0x044D,0x044E,0x044F,
	0x0401,0x0451,0x0404,0x0454,0x0407,0x0457,0x040E,0x045E,
	0x00B0,0x2022,0x00B7,0x0076,0x2116,0x00A4,0x00A6,0x00A0
};


unsigned int char8to16(int c, int type)
{
	if (c>=128)
	{
		switch(type)
		{
		case 1:
			//Win->Dos
			c = wintranslation[c-128];
			break;
		case 2:
			//Koi8->Dos
			c = koi8translation[c-128];
			break;
		case 3:
			break;
			//Dos
		}
		if (c < 128) return(c);
		return(dos2unicode[c - 128]);
	}
	return(c);
}

int char16to8(int c)
{
	if (c < 0x400) return (c);
	c -= 0x400;
	if (c < 16)
	{
		if (c == 1) c = 0;  //big_yo
		else if (c == 4) c = 2;  //big_ye
		else if (c == 6) c = 10; //big_i
		else return (c);
	}
	else if (c > 79)
	{
		if (c == 0x51) c = 16; //small_yo
		else if (c == 0x54) c = 18; //small_ye
		else if (c == 0x56) c = 11; //small_i
		else if (c == 0x57) c = 23; //small_yi
		else return (c);
	}
	else c += 8;
	c += 168;
	return (c);
}

void ascii2ws(WSHDR* ws, const char* s)
{
	char c;
	CutWSTR(ws, 0);
	while((c = *s++))
		wsAppendChar(ws, char8to16(c, 1));
}

void koi2ws(WSHDR* ws, const char* s)
{
	char c;
	CutWSTR(ws, 0);
	while((c = *s++))
		wsAppendChar(ws, char8to16(c, 2));
}

void dos2ws(WSHDR* ws, const char* s)
{
	int c;
	CutWSTR(ws, 0);
	while((c = *s++))
		wsAppendChar(ws, char8to16(c, 3));
}  

void dos2utf8(const char* s)
{
	int len = strlen(s);
	WSHDR* ws = AllocWS(len);
	dos2ws(ws, s);
	char* utf8 = malloc(len*2 + 1);
	ws_2str(ws, utf8, len*2);
	mfree(utf8);
	FreeWS(ws);
	strcpy((char*)s, utf8);
	
}

int utf82win(char* utf8)
{
	// ������������ ������ UTF8 ��� �������, ���������� � �����
	if (!utf8) return NULL;
	int st_len = strlen(utf8);

	// �������� ������ - ��-���������
	int lastchar = 0;
	char* tmp_out = utf8;
	char chr, chr2, chr3;
	for(int i = 0; i < st_len; i++)
	{
		chr = (*(utf8 + i));

		if (chr < 0x80)
		{
			*(tmp_out + lastchar++) = chr;
			continue;
		}
		
		if (chr < 0xc0)
			return 0;

		chr2 = *(utf8 + i + 1);

		if (chr2 < 0x80)
			return 0;

		if (chr < 0xe0)
		{
			// cx, dx
			char test1 = (chr & 0x1f)<<6;
			char test2 = chr2 & 0x3f;
			*(tmp_out + lastchar++) = test1 | test2 + 127 + 0x31;
			i++;
			continue;
		}
		
		if (chr < 0xf0)
		{
			// cx, dx
			chr3 = *(utf8 + i + 2);

			if (chr3 < 0x80)
				return 0;

			*(tmp_out + lastchar) = ((chr & 0x0f) << 12) | ((chr2 & 0x3f) << 6) | (chr3 & 0x3f);
			i = i + 2;
		}
	}
	
	*(tmp_out + lastchar) = '\0';
	return 1;
}
