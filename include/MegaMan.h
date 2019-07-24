#ifndef __MEGA_MAN_H__
#define __MEGA_MAN_H__

#include "gba_types.h"
#include "gba_math.h"
#include "gba_gfx.h"
#include "gba_input.h"

#include "MegaManSprites.h"
#include "MegaManSpritesv2.h"

class MegaMan
{
public:
	MegaMan();
	~MegaMan();

	void LoadResources();

	void Update();

private:

	//Define the tile size for each animation tile
	const int m_animationTileSize = 32;

	enum Animation
	{
		Walkleft,
		WalkRight,
		Jump,
		Shoot,
		Stand
	};

	enum AnimationStartTile
	{
		WalkStart = 4,
		JumpStart = 0,
		ShootStart = 0,
		StandStart = 1
	};
	enum AnimationFrameCount
	{
		WalkMax = 3,
		JumpMax = 1,
		ShootMax = 0,
		StandMax = 2,
		Max = 12
	};

	void UpdateAnimation(Animation a_animation);
	void UpdateAnimationFrame(Animation a_animation, AnimationStartTile a_animationStartTile, AnimationFrameCount a_animationFrameCount);



	Animation m_currentAnimationState = Animation::Stand;
	bool m_animationFirstLoop = true;
	int m_animationIndex = 0;


	//TESTING
public:
	//pos
	fixed m_xPos = int2fix(0);
	fixed m_yPos = int2fix(160 - 32);

	//dir
	fixed m_xDir = int2fix(0);
	fixed m_yDir = int2fix(0);

	fixed m_jumpCooldown = int2fix(2);
	bool m_isJumping = false;

	u8 m_animStep = 32;
	u16 m_animMaxValue = 128;
	u32 m_currentAnim = 0;

private:
	//sprite
	ObjectAttribute* mSprite;


};

extern void UpdateMegaMan(MegaMan* aMegaMan);

#endif //__MEGA_MAN_H__

