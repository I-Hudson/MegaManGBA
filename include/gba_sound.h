#ifndef __GBA_SOUND_H__
#define __GBA_SOUND_H__

#include "gba_reg.h"
#include "gba_types.h"

// === SOUND REGISTERS ===
// sound regs, partially following pin8gba's nomenclature

//! \name Channel 1: Square wave with sweep
#define REG_SND1SWEEP		*(vu16*)(REG_BASE + 0x0060)	//!< Channel 1 Sweep
#define REG_SND1CNT			*(vu16*)(REG_BASE + 0x0062)	//!< Channel 1 Control
#define REG_SND1FREQ		*(vu16*)(REG_BASE + 0x0064)	//!< Channel 1 frequency

//! \name Channel 2: Simple square wave
#define REG_SND2CNT			*(vu16*)(REG_BASE + 0x0068)	//!< Channel 2 control
#define REG_SND2FREQ		*(vu16*)(REG_BASE + 0x007C)	//!< Channel 2 frequency

//! \name Channel 3: Wave player
#define REG_SND3SEL			*(vu16*)(REG_BASE+0x0070)	//!< Channel 3 wave select
#define REG_SND3CNT			*(vu16*)(REG_BASE+0x0072)	//!< Channel 3 control
#define REG_SND3FREQ		*(vu16*)(REG_BASE+0x0074)	//!< Channel 3 frequency

//! \name Channel 4: Noise generator
#define REG_SND4CNT			*(vu16*)(REG_BASE+0x0078)	//!< Channel 4 control
#define REG_SND4FREQ		*(vu16*)(REG_BASE+0x007C)	//!< Channel 4 frequency

//! \name Sound control
#define REG_SNDCNT			*(vu32*)(REG_BASE+0x0080)	//!< Main sound control
#define REG_SNDDMGCNT		*(vu16*)(REG_BASE+0x0080)	//!< DMG channel control
#define REG_SNDDSCNT		*(vu16*)(REG_BASE+0x0082)	//!< Direct Sound control
#define REG_SNDSTAT			*(vu16*)(REG_BASE+0x0084)	//!< Sound status
#define REG_SNDBIAS			*(vu16*)(REG_BASE+0x0088)	//!< Sound bias

#define SSW_INC			 0		//!< Increasing sweep rate
#define SSW_DEC			0x0008	//!< Decreasing sweep rate
#define SSW_OFF         0x0008	//!< Disable sweep altogether

#define SSQR_DUTY1_8		 0	//!< 12.5% duty cycle (#-------)
#define SSQR_DUTY1_4	0x0040	//!< 25% duty cycle (##------)
#define SSQR_DUTY1_2	0x0080	//!< 50% duty cycle (####----)
#define SSQR_DUTY3_4	0x00C0	//!< 75% duty cycle (######--) Equivalent to 25%
#define SSQR_INC			 0	//!< Increasing volume
#define SSQR_DEC		0x0800	//!< Decreasing volume

#define SSTAT_SQR1		0x0001	//!< (R) Channel 1 status
#define SSTAT_SQR2		0x0002	//!< (R) Channel 2 status
#define SSTAT_WAVE		0x0004	//!< (R) Channel 3 status
#define SSTAT_NOISE		0x0008	//!< (R) Channel 4 status
#define SSTAT_DISABLE		 0	//!< Disable sound
#define SSTAT_ENABLE	0x0080	//!< Enable sound. NOTE: enable before using any other sound regs

#define SFREQ_RESET			0x8000

// Unshifted values
#define SDMG_SQR1		0x01
#define SDMG_SQR2		0x02
#define SDMG_WAVE		0x04
#define SDMG_NOISE		0x08

typedef enum
{
	NOTE_C = 0, NOTE_CIS, NOTE_D, NOTE_DIS,
	NOTE_E, NOTE_F, NOTE_FIS, NOTE_G,
	NOTE_GIS, NOTE_A, NOTE_BES, NOTE_B
} eSndNoteId;

// Rates for traditional notes in octave +5
const u32 __snd_rates[12] =
{
	8013, 7566, 7144, 6742, // C , C#, D , D#
	6362, 6005, 5666, 5346, // E , F , F#, G
	5048, 4766, 4499, 4246  // G#, A , A#, B
};

#define SND_RATE(note, oct) ( 2048-(__snd_rates[note]>>(4+(oct))) )

#define SSQR_ENV_BUILD(ivol, dir, time)				\
	(  ((ivol)<<12) | ((dir)<<11) | (((time)&7)<<8) )

#define SSQR_BUILD(_ivol, dir, step, duty, len)		\
	( SSQR_ENV_BUILD(ivol,dir,step) | (((duty)&3)<<6) | ((len)&63) )

#define SDMG_BUILD(_lmode, _rmode, _lvol, _rvol)	\
	( ((_rmode)<<12) | ((_lmode)<<8) | (((_rvol)&7)<<4) | ((_lvol)&7) )

#define SDMG_BUILD_LR(_mode, _vol) SDMG_BUILD(_mode, _mode, _vol, _vol)

extern void NotePrep(int octave);
extern void NotePlay(int note, int octave);
extern void SOS();

#endif // !__GBA_SOUND_H__

