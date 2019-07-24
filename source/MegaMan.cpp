#include "MegaMan.h"

#include <cstring>

MegaMan::MegaMan()
{
	mSprite = getNextObj_bufferPos();
	mSprite->attr0 = SetAttrib0(fix2int(m_yPos), 0, 0, 0, A0_8BPP, A0_SQUARE);
	mSprite->attr1 = SetAttrib1(fix2int(m_xPos), 0, A1_SIZE_2);
	mSprite->attr2 = SetAttrib2(0, 0, 0);
}

MegaMan::~MegaMan()
{
}

void MegaMan::LoadResources()
{
	memcpy(sprite_tile_block_address(0), MegaManSpritesv2Tiles, MegaManSpritesv2TilesLen);
	memcpy(palette_sp_block_address(0), MegaManSpritesv2Pal, MegaManSpritesv2PalLen);
}

void MegaMan::Update()
{
	Animation animation = Animation::Stand;
	bool input = false;

	if (keyHeld(KEYS::LEFT))
	{
		m_xDir = int2fix(-1);
		animation = Animation::Walkleft;
		input = true;
	}
	if (keyDown(KEYS::RIGHT))
	{
		m_xDir = int2fix(1);
		animation = Animation::WalkRight;
		input = true;
	}
	if (m_isJumping == false && keyDown(KEYS::UP))
	{
		m_isJumping = true;
		m_yDir = int2fix(-1);
		animation = Animation::Jump;
	}
	if (keyDown(KEYS::DOWN))
	{
		m_isJumping = false;

		animation = Animation::Stand;
	}

	if(input == false)
	{
		//m_yDir = int2fix(0);
		m_xDir = int2fix(0);
		animation = Animation::Stand;
	}

	if (m_isJumping)
	{
		animation = Animation::Jump;


		if (m_yPos < int2fix(96))
		{
			m_yDir = int2fix(1);
		}
		if (m_yPos > int2fix(160 - 32))
		{
			m_yDir = int2fix(0);
			m_yPos = int2fix(160 - 32);
			m_isJumping = false;
		}
	}

	if (m_xDir != 0 || m_yDir != 0)
	{
		m_xPos = fixAdd(m_xPos, m_xDir);
		m_yPos = fixAdd(m_yPos, m_yDir);
		mSprite->attr0 = SetAttrib0(fix2int(m_yPos), A0_MODE_REG, 0, 0, A0_8BPP, A0_SQUARE);
		mSprite->attr1 = SetAttrib1(fix2int(m_xPos), (fix2int(m_xDir) == 1) ? 0 : 1, A1_SIZE_2);
	}

	if (m_animationIndex >= 16)
	{
		UpdateAnimation(animation);
		m_animationIndex = 0;
	}
	m_animationIndex++;
}

void MegaMan::UpdateAnimation(Animation a_animation)
{
	if (m_currentAnimationState != a_animation)
	{
		m_animationFirstLoop = true;
	}

	if (a_animation == Animation::Walkleft)
	{
		m_currentAnimationState = Animation::Walkleft;
		
		UpdateAnimationFrame(m_currentAnimationState, AnimationStartTile::WalkStart, AnimationFrameCount::WalkMax);
	}
	else if (a_animation == Animation::WalkRight)
	{
		m_currentAnimationState = Animation::WalkRight;

		UpdateAnimationFrame(m_currentAnimationState, AnimationStartTile::WalkStart, AnimationFrameCount::WalkMax);
	}
	else if (a_animation == Animation::Jump)
	{
		m_currentAnimationState = Animation::Jump;

		UpdateAnimationFrame(m_currentAnimationState, AnimationStartTile::JumpStart, AnimationFrameCount::JumpMax);
	}
	else if (a_animation == Animation::Shoot)
	{
		m_currentAnimationState = Animation::Shoot;

		UpdateAnimationFrame(m_currentAnimationState, AnimationStartTile::ShootStart, AnimationFrameCount::ShootMax);
	}
	else if (a_animation == Animation::Stand)
	{
		m_currentAnimationState = Animation::Stand;

		UpdateAnimationFrame(m_currentAnimationState, AnimationStartTile::StandStart, AnimationFrameCount::StandMax);
	}

	mSprite->attr2 = SetAttrib2(m_currentAnim, 0, 0);

	m_animationFirstLoop = false;
}

void MegaMan::UpdateAnimationFrame(Animation a_animation, AnimationStartTile a_animationStartTile, AnimationFrameCount a_animationFrameCount)
{
	m_currentAnim = (m_animationFirstLoop == true) ? (a_animationStartTile * m_animationTileSize) : m_currentAnim;

	m_currentAnim = (m_currentAnim + m_animationTileSize) % ((a_animationStartTile * m_animationTileSize) + (a_animationFrameCount * m_animationTileSize));

	if (m_currentAnim < (a_animationStartTile * m_animationTileSize))
	{
		m_currentAnim = (a_animationStartTile * m_animationTileSize);
	}
}

//void UpdateMegaMan(MegaMan* aMegaMan)
//{
//	if (keyHeld(KEYS::LEFT))
//	{
//		aMegaMan->mXDir = int2fix(-1);
//		//mCurrentAnim = (mCurrentAnim + 32) % mAnimMaxValue;
//		//mSprite->attr2 = SetAttrib2(mCurrentAnim, 0, 0);
//	}
//	else if (keyDown(KEYS::RIGHT))
//	{
//		aMegaMan->mXDir = int2fix(1);
//		//mCurrentAnim = (mCurrentAnim + 32) % mAnimMaxValue;
//		//mSprite->attr2 = SetAttrib2(mCurrentAnim, 0, 0);
//	}
//	else if (aMegaMan->isJumping == false && keyDown(KEYS::UP))
//	{
//		aMegaMan->isJumping = true;
//		aMegaMan->mYDir = int2fix(-1);
//	}
//	else
//	{
//		aMegaMan->mXDir = int2fix(0);
//		//aMegaMan->mYDir = int2fix(0);
//	}
//
//	if (aMegaMan->isJumping)
//	{
//	//	aMegaMan->jumpCooldown -= float2fix(0.000001f);
//	//
//	//	if (fix2float(aMegaMan->jumpCooldown) < 0.0f)
//	//	{
//	//		aMegaMan->isJumping = false;
//	//	}
//	}
//	//else
//	//{
//	//	if (aMegaMan->mYPos != int2fix(0))
//	//	{
//	//		aMegaMan->mYDir = -1;
//	//	}
//	//}
//
//	//if (aMegaMan->mXDir != 0 || aMegaMan->mYDir != 0)
//	//{
//		aMegaMan->mXPos = fixAdd(aMegaMan->mXPos, aMegaMan->mXDir);
//		aMegaMan->mYPos = fixAdd(aMegaMan->mYPos, aMegaMan->mYDir);
//		aMegaMan->mSprite->attr0 = SetAttrib0(fix2int(aMegaMan->mYPos), A0_MODE_REG, 0, 0, A0_8BPP, A0_SQUARE);
//		aMegaMan->mSprite->attr1 = SetAttrib1(fix2int(aMegaMan->mXPos), 0, A1_SIZE_2);
//	//}
//}
