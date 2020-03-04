#include <wchar.h>
#include <alib\img.h>


const unsigned short cp1251_UTF16_table[]=
{
  0x0402,0x0403,0x201A,0x0453,0x201E,0x2026,0x2020,0x2021,
  0x20AC,0x2030,0x0409,0x2039,0x040A,0x040C,0x040B,0x040F,
  0x0452,0x2018,0x2019,0x201C,0x201D,0x2022,0x2013,0x2014,
  0x0020,0x2122,0x0459,0x203A,0x045A,0x045C,0x045B,0x045F,
  0x00A0,0x040E,0x045E,0x0408,0x00A4,0x0490,0x00A6,0x00A7,
  0x0401,0x00A9,0x0404,0x00AB,0x00AC,0x00AD,0x00AE,0x0407,
  0x00B0,0x00B1,0x0406,0x0456,0x0491,0x00B5,0x00B6,0x00B7,
  0x0451,0x2116,0x0454,0x00BB,0x0458,0x0405,0x0455,0x0457,

  0x0410,0x0411,0x0412,0x0413,0x0414,0x0415,0x0416,0x0417,
  0x0418,0x0419,0x041A,0x041B,0x041C,0x041D,0x041E,0x041F,
  0x0420,0x0421,0x0422,0x0423,0x0424,0x0425,0x0426,0x0427,
  0x0428,0x0429,0x042A,0x042B,0x042C,0x042D,0x042E,0x042F,

  0x0430,0x0431,0x0432,0x0433,0x0434,0x0435,0x0436,0x0437,
  0x0438,0x0439,0x043A,0x043B,0x043C,0x043D,0x043E,0x043F,
  0x0440,0x0441,0x0442,0x0443,0x0444,0x0445,0x0446,0x0447,
  0x0448,0x0449,0x044A,0x044B,0x044C,0x044D,0x044E,0x044F
};



//0x0410-0x044F - Unicode
//0xD090-0xD18F - UTF-8

unsigned int cp1251_utf16 (int c)
{
  if (c>=128)
  {
    return(cp1251_UTF16_table[c-128]);
  }
  return(c);
}
/*
int utf8_utf16 (int c){
    if (c<128)
    {
        return c;
    }

    int uc='?';
    if (c>=0xD090 && c<=0xD0AF) uc=c-0xD090+0x0410; //capital cyrilic
    else{
        if (c>=0xD0B0 && c<=0xD0BF) uc=c-0xD0B0+0x0430; //cyrilic from a
        else{
            if (c>=0xD180 && c<=0xD18F) uc=c-0xD180+0x0440; //CYRILLIC SMALL LETTER ER
            else{
                if (c==0xD081) uc=0x0415; //capital yo
                else if (c==0xD191) uc=0x0435; //capital yo
            }
        }
    }
    return uc;
}
*/
size_t conv_utf8_unicode (char *_src, wchar_t *_out)
{
	wchar_t *out_start = _out;
	for ( ; *_src; )
	{
		if ( (unsigned)(*_src) < 0x80 )
		{
			*_out++ = (wchar_t)*_src++;
			continue;
		}

		wchar_t c;
		unsigned len = 1;
		unsigned char test = (*_src) << 1;
		unsigned char mask = 0x1F;

		// 3-byte (or more) UTF8 sequence?
		while ( 0xC0 == (test & 0xC0) )
		{
			++len;
			test <<= 1;
			mask >>= 1;
		}

		c = (*_src) & mask;
		++_src;
		do {
			c <<= 6;
			c |= ((*_src) & 0x3f);
			++_src;
			--len;
		} while( len && *_src );

		*_out++ = c;
	}
	*_out = 0;
	return _out - out_start;
}


void DecodeString (wchar_t *wstr, char *str, int charmap){
    switch (charmap){
        case UTF16: {
            int i=0;
            unsigned short *ptr=(unsigned short*)str;
            while (ptr[i]!='\0'){
                wstr[i]=ptr[i];
                i++;
            }
            wstr[i]='\0';
        }break;

        case UTF8: {
            conv_utf8_unicode (str, wstr);
        }break;

        case ASCII: {
            int i=0;
            while (str[i]!='\0'){
                wstr[i]=cp1251_utf16 (str[i]);
                i++;
            }
            wstr[i]='\0';
        }break;
    }

}

