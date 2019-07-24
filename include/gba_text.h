#ifndef __GBA_TEXT_H__
#define __GBA_TEXT_H__

#include "Intellisense.h"
#include "gba_types.h"
#include "gba_math.h"

//extern unsigned short textMap[];
/*
typedef struct sTextMap
{
	unsigned short* map;

}sTextMap;

void Init(sTextMap a_textMap)
{
	a_textMap.map = new unsigned short[4096];

	for (s32 i = 0; i < 4096; ++i)
	{
		*a_textMap.map += i = 0x0001;
	}
}
*/
/*
#define TEXT_MAP_SIZE 4096

typedef struct TextObj
{
	u16 palBlockAddress;
	u16 tileBlockAddress;
	u16 mapBlockAddress;

	unsigned short map[4096];
}TextObj;

extern void TextInit(TextObj a_textObj);

extern void TextSetPal(TextObj a_textObj, const unsigned short* a_pal, const unsigned short a_palLen);
extern void TextSetTiles(TextObj a_textObj, const unsigned short* a_tiles, const unsigned short a_tilesLen);
extern void TextSetMap(TextObj a_textObj);

extern void TextPrint(TextObj a_textObj,  fixed a_x, fixed a_y, char* a_string);
*/
#endif // __GBA_TEXT_H__