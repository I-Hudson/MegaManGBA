#pragma once

#include "gba_types.h"
#include "gba_math.h"
#include "gba_gfx.h"

class Level
{
public:
	Level();
	~Level();

	void LoadResources(const unsigned short* a_tiles, const short a_palette);

private:


};