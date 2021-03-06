#include "..\inc\swilib.h"
//#include "main.h"
#include "strings.h"
//-----------------------Edit chat---------------------------
extern int total_symb;
typedef struct
{
  unsigned short u;
  char dos;
  char win;
  char koi8;
} TUNICODE2CHAR;

const TUNICODE2CHAR unicode2char[]=
{
  // CAPITAL Cyrillic letters (base)
  0x410,0x80,0xC0,0xE1, // �
  0x411,0x81,0xC1,0xE2, // �
  0x412,0x82,0xC2,0xF7, // �
  0x413,0x83,0xC3,0xE7, // �
  0x414,0x84,0xC4,0xE4, // �
  0x415,0x85,0xC5,0xE5, // �
  0x416,0x86,0xC6,0xF6, // �
  0x417,0x87,0xC7,0xFA, // �
  0x418,0x88,0xC8,0xE9, // �
  0x419,0x89,0xC9,0xEA, // �
  0x41A,0x8A,0xCA,0xEB, // �
  0x41B,0x8B,0xCB,0xEC, // �
  0x41C,0x8C,0xCC,0xED, // �
  0x41D,0x8D,0xCD,0xEE, // �
  0x41E,0x8E,0xCE,0xEF, // �
  0x41F,0x8F,0xCF,0xF0, // �
  0x420,0x90,0xD0,0xF2, // �
  0x421,0x91,0xD1,0xF3, // �
  0x422,0x92,0xD2,0xF4, // �
  0x423,0x93,0xD3,0xF5, // �
  0x424,0x94,0xD4,0xE6, // �
  0x425,0x95,0xD5,0xE8, // �
  0x426,0x96,0xD6,0xE3, // �
  0x427,0x97,0xD7,0xFE, // �
  0x428,0x98,0xD8,0xFB, // �
  0x429,0x99,0xD9,0xFD, // �
  0x42A,0x9A,0xDA,0xFF, // �
  0x42B,0x9B,0xDB,0xF9, // �
  0x42C,0x9C,0xDC,0xF8, // �
  0x42D,0x9D,0xDD,0xFC, // �
  0x42E,0x9E,0xDE,0xE0, // �
  0x42F,0x9F,0xDF,0xF1, // �
  // CAPITAL Cyrillic letters (additional)
  0x402,'_',0x80,'_', // _ .*.*
  0x403,'_',0x81,'_', // _ .*.*
  0x409,'_',0x8A,'_', // _ .*.*
  0x40A,'_',0x8C,'_', // _ .*.*
  0x40C,'_',0x8D,'_', // _ .*.*
  0x40B,'_',0x8E,'_', // _ .*.*
  0x40F,'_',0x8F,'_', // _ .*.*
  0x40E,0xF6,0xA1,'_', // � ...*
  0x408,0x4A,0xA3,0x4A, // _ .*.*
  0x409,0x83,0xA5,0xBD, // _ .*..
  0x401,0xF0,0xA8,0xB3, // �
  0x404,0xF2,0xAA,0xB4, // �
  0x407,0xF4,0xAF,0xB7, // �
  0x406,0x49,0xB2,0xB6, // _ .*..
  0x405,0x53,0xBD,0x53, // _ .*.*
  // SMALL Cyrillic letters (base)
  0x430,0xA0,0xE0,0xC1, // �
  0x431,0xA1,0xE1,0xC2, // �
  0x432,0xA2,0xE2,0xD7, // �
  0x433,0xA3,0xE3,0xC7, // �
  0x434,0xA4,0xE4,0xC4, // �
  0x435,0xA5,0xE5,0xC5, // �
  0x436,0xA6,0xE6,0xD6, // �
  0x437,0xA7,0xE7,0xDA, // �
  0x438,0xA8,0xE8,0xC9, // �
  0x439,0xA9,0xE9,0xCA, // �
  0x43A,0xAA,0xEA,0xCB, // �
  0x43B,0xAB,0xEB,0xCC, // �
  0x43C,0xAC,0xEC,0xCD, // �
  0x43D,0xAD,0xED,0xCE, // �
  0x43E,0xAE,0xEE,0xCF, // �
  0x43F,0xAF,0xEF,0xD0, // �
  0x440,0xE0,0xF0,0xD2, // �
  0x441,0xE1,0xF1,0xD3, // �
  0x442,0xE2,0xF2,0xD4, // �
  0x443,0xE3,0xF3,0xD5, // �
  0x444,0xE4,0xF4,0xC6, // �
  0x445,0xE5,0xF5,0xC8, // �
  0x446,0xE6,0xF6,0xC3, // �
  0x447,0xE7,0xF7,0xDE, // �
  0x448,0xE8,0xF8,0xDB, // �
  0x449,0xE9,0xF9,0xDD, // �
  0x44A,0xEA,0xFA,0xDF, // �
  0x44B,0xEB,0xFB,0xD9, // �
  0x44C,0xEC,0xFC,0xD8, // �
  0x44D,0xED,0xFD,0xDC, // �
  0x44E,0xEE,0xFE,0xC0, // �
  0x44F,0xEF,0xFF,0xD1, // �
  // SMALL Cyrillic letters (additional)
  0x452,'_',0x90,'_', // _ .*.*
  0x453,'_',0x83,'_', // _ .*.*
  0x459,'_',0x9A,'_', // _ .*.*
  0x45A,'_',0x9C,'_', // _ .*.*
  0x45C,'_',0x9D,'_', // _ .*.*
  0x45B,'_',0x9E,'_', // _ .*.*
  0x45F,'_',0x9F,'_', // _ .*.*
  0x45E,0xF7,0xA2,'_', // � ...*
  0x458,0x6A,0xBC,0x6A, // _ .*.*
  0x491,0xA3,0xB4,0xAD, // _ .*..
  0x451,0xF1,0xB8,0xA3, // �
  0x454,0xF3,0xBA,0xA4, // �
  0x457,0xF5,0xBF,0xA7, // �
  0x456,0x69,0xB3,0xA6, // _ .*..
  0x455,0x73,0xBE,0x73, // _ .*.*
  0x0A0,'_',0xA0,0x20, // space .*..
  0x0A4,'_',0xA4,0xFD, // �   .*..
  0x0A6,'_',0xA6,'_', // �   .*.*
  0x0B0,0xF8,0xB0,0x9C, // �
  0x0B7,0xFA,0xB7,0x9E, // �
  // 0x2022,,0x95,0x95, //    .*..
  // 0x2116,0xFC,0xB9,0x23, // �   ...*
  // 0x2219,,0xF9,0x9E, //    .*..
  // 0x221A,0xFB,,0x96, // v   ..*.
  // 0x25A0,0xFE,,0x94, // �
  0x0000,0,0,0
};

const char wintranslation[128]=
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
const unsigned short dos2unicode[128]=
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
const char koi8translation[128]=
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

//#pragma inline
unsigned int char16to8(unsigned int c)
{
  const TUNICODE2CHAR *p=unicode2char;
  unsigned int i;
  if (c<128) return(c);
  while((i=p->u))
  {
    if (c==i)
    {
      return(p->win);
    }
    p++;
  }
  c&=0xFF;
  if (c<32) return(' ');
  return(c);
}

unsigned int char8to16(int c, int type)
{
  if (c>=128)
  {
    switch(type)
    {
    case 1:
      //Win->Dos
      c=wintranslation[c-128];
      break;
    case 2:
      //Koi8->Dos
      c=koi8translation[c-128];
      break;
    }
    if (c<128) return(c);
    return(dos2unicode[c-128]);
  }
  return(c);
}


void ascii2ws(WSHDR *ws, const char *s)
{
  char c;
  CutWSTR(ws,0);
  while((c=*s++))
  {
    total_symb++;
    wsAppendChar(ws,char8to16(c,1));
  }
}

void koi2ws(WSHDR *ws, const char *s)
{
  char c;
  CutWSTR(ws,0);
  while((c=*s++))
  {
    total_symb++;
    wsAppendChar(ws,char8to16(c,2));
  }
}
void win1251_2ws(WSHDR *ws, const char *s)
{
  char c;
  CutWSTR(ws,0);
  while((c=*s++))
  {
    total_symb++;
    wsAppendChar(ws,char16to8(c));
  }
}

/* ----------------------------- char16to8 CZ------------------------------------ */


typedef struct
{
unsigned short u;
char dos;
} TUNICODE2CHAR_CZ;

const TUNICODE2CHAR_CZ unicode2char_CZ[]=
{
0x0A4, 0xA4, // 164 � - // CZ/SK part
0x0A6, 0xA6, // 166 � -
0x0A7, 0xA7, // 167 � -
0x0A8, 0xA8, // 168 � -
0x0A9, 0xA9, // 169 � -
0x0AB, 0xAB, // 171 
0x0AC, 0xAC, // 172 � -
0x0AD, 0x96, // 150 � 
0x0AE, 0xAE, // 174 � -
0x0B0, 0xB0, // 176 � 
0x0B1, 0xB1, // 177 � -
0x0B4, 0xB4, // 180 � 
0x0B5, 0xB5, // 181 � // 0 32 64 96 128 160 192 224 - tema zacina
0x0B6, 0xB6, // 182 � 
0x0B7, 0xB7, // 183 � 
0x0B8, 0xB8, // 184 � 
0x0BB, 0xBB, // 187 � 
0x0C1, 0xC1, // 193 � -
0x0C2, 0xC2, // 194 � 
0x0C4, 0xC4, // 196 � 
0x0C7, 0xC7, // 199 � 
0x0C9, 0xC9, // 201 � -
0x0CB, 0xCB, // 203 � 
0x0CE, 0xCD, // 205 � -
0x0CF, 0xCE, // 206 � 
0x0D3, 0xD3, // 211 � -
0x0D4, 0xD4, // 212 � 
0x0D5, 0xD5, // 213 � 
0x0D6, 0xD6, // 214 � 
0x0D7, 0xD7, // 215 � -
0x0DA, 0xDA, // 218 � -
0x0DC, 0xDC, // 220 � 
0x0DD, 0xDD, // 221 � -
0x0DF, 0xDF, // 223 � 
0x0E1, 0xE1, // 225 � -
0x0E2, 0xE2, // 226 � 
0x0E4, 0xE4, // 228 � 
0x0E7, 0xE7, // 231 � 
0x0E9, 0xE9, // 233 � -
0x0EB, 0xEB, // 235 � 
0x0ED, 0xED, // 237 � -
0x0EE, 0xEE, // 238 � 
0x0F3, 0xF3, // 243 � -
0x0F4, 0xF4, // 244 � 
0x0F5, 0xF5, // 245 � 
0x0F6, 0xF6, // 246 � 
0x0F7, 0xF7, // 247 � -
0x0FA, 0xFA, // 250 � -
0x0FB, 0xFB, // 186 ^u 
0x0FC, 0xFC, // 252 � 
0x0FD, 0xFD, // 253 � -
0x102, 0xC3, // 195 � 
0x103, 0xE3, // 227 � 
0x104, 0xA5, // 165 � 
0x105, 0xB9, // 185 � 
0x106, 0xC6, // 198 � 
0x107, 0xE6, // 230 � 
0x10C, 0xC8, // 200 � -
0x10D, 0xE8, // 232 � -
0x10E, 0xCF, // 207 � -
0x10F, 0xEF, // 239 � -
0x110, 0xD0, // 208 � 
0x111, 0xF0, // 240 � 
0x118, 0xCA, // 202 � 
0x119, 0xEA, // 234 � // 
0x11A, 0xCC, // 204 � -
0x11B, 0xEC, // 236 � -
0x139, 0xC5, // 197 � 
0x13A, 0xE5, // 229 � 
0x13D, 0xBC, // 188 � 
0x13E, 0xBE, // 190 � 
0x141, 0xA3, // 163 � 
0x142, 0xB3, // 179 � 
0x143, 0xD1, // 209 � 
0x144, 0xF1, // 241 � 
0x147, 0xD2, // 210 � -
0x148, 0xF2, // 242 � -
0x154, 0xC0, // 192 � 
0x155, 0xE0, // 224 � 
0x158, 0xD8, // 216 � -
0x15A, 0x8C, // 140 � 
0x15B, 0x9C, // 156 � 
0x15E, 0xAA, // 170 � 
0x160, 0x8A, // 138 � -
0x161, 0x9A, // 154 � -
0x162, 0xDE, // 222 � 
0x163, 0xFE, // 254 � 
0x164, 0x8D, // 141 � -
0x165, 0x9D, // 157 � -
0x168, 0xDB, // 219 � 
0x169, 0xFB, // 251 � 
0x16E, 0xD9, // 217 � -
0x16F, 0xF9, // 249 � -
0x179, 0x8F, // 143 � 
0x17A, 0x9F, // 159 � 
0x17B, 0xAF, // 175 � 
0x17C, 0xBF, // 191 � 
0x17D, 0x8E, // 142 � -
0x17E, 0x9E, // 158 � -
0x000,0

};
#pragma inline
unsigned int char16to8_CZ(unsigned int c)
{
  const TUNICODE2CHAR_CZ *p=unicode2char_CZ;
  unsigned int i;
  if (c<12) return(c);
  while((i=p->u))
    {
      if (c==i)
      {
        return(p->dos);
      }
      p++;
    }
// c&=0xFF;
if (c<32) return(' ');
return(c);
}
void win1250_2ws(WSHDR *ws, const char *s)
{
  char c;
  CutWSTR(ws,0);
  while((c=*s++))
  {
    total_symb++;
    wsAppendChar(ws,char16to8_CZ(c));
  }
}
