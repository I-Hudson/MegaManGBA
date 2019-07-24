#ifndef __GBA_STRUCTS_H__
#define __GBA_STRUCTS_H__

#include "gba_types.h"
#include "gba_input.h"
#include "gba_gfx.h"
#include "gba_drawing.h"

#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <cmath>

// TODO:
// Emitter:
//		Have the particles move in the oposite direction from the rokcket forwrad
//		vector witht he same randomness
//
// Bullet:
//		Make collision
///

struct TextMap
{
#define MAP_SIZE 8192
	u32 mapSize = MAP_SIZE;
	unsigned short map[MAP_SIZE];
	u8 w, h;

	void Init(unsigned short a_bgSize)
	{
		//map = new unsigned short[4096];

		if(a_bgSize == 0x0)
		{
			w = 32;
			h = 32;
		}
		else if (a_bgSize == 0x1)
		{
			w = 64;
			h = 32;
		}
		else if (a_bgSize == 0x2)
		{
			w = 32;
			h = 64;
		}
		else if (a_bgSize == 0x3)
		{
			w = 64;
			h = 64;
		}

		for (s32 i = 0; i < h; i++)
		{
			for (s32 j = 0; j < w; j++)
			{
				map[i] = 0x0;
			}
		}
	}

	void SetText(u8 a_x, u8 a_y, char* a_string)
	{
		s32 index = 0;
		for (char c = *a_string; c; c=*++a_string)
		{
			map[((a_y * 32) + a_x) + index] = LookUp(c);
			index++;
		}
	}

	unsigned short LookUp(char a_letter)
	{
		unsigned short returnValue = 0x0;
		switch (putchar (toupper(a_letter)))
		{
		case 'A':
			returnValue = 0x01;
			break;
		case 'B':
			returnValue = 0x02;
			break;		
		case 'C':
			returnValue = 0x03;
			break;		
		case 'D':
			returnValue = 0x04;
			break;
		case 'E':
			returnValue = 0x05;
			break;
		case 'F':
			returnValue = 0x06;
			break;
		case 'G':
			returnValue = 0x07;
			break;
		case 'H':
			returnValue = 0x08;
			break;
		case 'I':
			returnValue = 0x09;
			break;
		case 'J':
			returnValue = 0x0A;
			break;
		case 'K':
			returnValue = 0x0B;
			break;
		case 'L':
			returnValue = 0x0C;
			break;
		case 'M':
			returnValue = 0x0D;
			break;
		case 'N':
			returnValue = 0x0E;
			break;
		case 'O':
			returnValue = 0x0F;
			break;
		case 'P':
			returnValue = 0x10;
			break;
		case 'Q':
			returnValue = 0x11;
			break;
		case 'R':
			returnValue = 0x12;
			break;
		case 'S':
			returnValue = 0x13;
			break;
		case 'T':
			returnValue = 0x14;
			break;
		case 'U':
			returnValue = 0x15;
			break;
		case 'V':
			returnValue = 0x16;
			break;
		case 'W':
			returnValue = 0x17;
			break;
		case 'X':
			returnValue = 0x18;
			break;
		case 'Y':
			returnValue = 0x19;
			break;
		case 'Z':
			returnValue = 0x1A;
			break;
		case '0':
			returnValue = 0x1B;
			break;
		case '1':
			returnValue = 0x1C;
			break;
		case '2':
			returnValue = 0x1D;
			break;
		case '3':
			returnValue = 0x1E;
			break;
		case '4':
			returnValue = 0x1F;
			break;
		case '5':
			returnValue = 0x20;
			break;
		case '6':
			returnValue = 0x21;
			break;
		case '7':
			returnValue = 0x22;
			break;
		case '8':
			returnValue = 0x23;
			break;
		case '9':
			returnValue = 0x24;
			break;
		default:
			returnValue = 0x00;
			break;
		}

		return returnValue;
	}
};



#endif // __GBA_STRUCTS_H__
