#include "..\include\gba_sound.h"

void NotePrep(int octave)
{

}

void NotePlay(int note, int octave)
{
	// Play the actual note
	REG_SND1FREQ = SFREQ_RESET | SND_RATE(note, octave);
}

void SOS()
{
	const u8 lens[6] = { 1,1,4,1,1,4 };
	const u8 notes[6] = { 0x02, 0x05, 0x12,  0x02, 0x05, 0x12 };
	int ii;
	for (ii = 0; ii < 6; ++ii)
	{
		NotePlay(notes[ii] & 15, notes[ii] >> 4);
	}
}
