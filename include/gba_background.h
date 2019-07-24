#ifndef __GBA_BACKGROUND_H__
#define __GBA_BACKGROUND_H__

#include "gba_gfx.h"
#include "gba_types.h"
#include "string.h"

struct GBA_Background
{
	u16* titleMemBlock;
	u16* tileMapMemLoc;

	u16 tileMemLocation;
	u16 tileMapLocation;

	GBA_Background()
	{
	}

	GBA_Background(const void* a_palette, size_t a_paletteSize,
				   u16 a_tileBlockMem, const void* a_tiles, size_t a_tilesSize,
				   u16 a_mapMem, const void* a_map, size_t a_mapSize,
				   u16 a_backgroundController)
	{
		//set the palette
		memcpy(pal_bg_mem, a_palette, a_paletteSize);
	
		//Set the tiles
		titleMemBlock = tile_block_address(a_tileBlockMem);
		tileMemLocation = a_tileBlockMem;
		memcpy(titleMemBlock, a_tiles, a_tilesSize);

		//Set the map
		tileMapMemLoc = tileMap_block_address(a_mapMem);
		tileMapLocation = a_mapMem;
		memcpy(tileMapMemLoc, a_map, a_mapSize);

		//Defualt settings
		SetBackgroundController(a_backgroundController, 0, a_tileBlockMem, 0, A0_4BPP, a_mapMem, 0, BG_REG_SIZE_32x32);
	}

	void SetBackgroundController(u8 a_regNum, u8 a_priority, u8 a_tileBlockID, u8 a_mosaic, u8 a_colourMode, u8 a_mapBlockID, u8 a_affineWrap, u8 a_bgSize)
	{
		setBG_Control_Register(a_regNum, a_priority, a_tileBlockID, a_mosaic, a_colourMode, a_mapBlockID, a_affineWrap, a_bgSize);
	}
};

#endif //__GBA_BACKGROUND_H__