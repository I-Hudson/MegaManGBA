#include "Intellisense.h"
#include "gba.h"

//#include "BG_Externs.h"
//#include "BG_ExternsTestLevel.h"
//#include "FG_Externs.h"

#include <sstream>
#include <string>
#include <sstream>
#include <cstring>

#pragma region Print to console

extern "C" 
{
	// ------------------------------------------------------------------------
	// GLOBALS
	// ------------------------------------------------------------------------
	extern char nocash_buffer[80];

	// ------------------------------------------------------------------------
	// PROTOTYPES
	// ------------------------------------------------------------------------
	//! Print the currect nocash_buffer to the no$gba debugger console
	void nocash_message(void);

}
//const char*
void Print(const char* a_message)
{
	int stringLen = strlen(a_message);
	strncpy(nocash_buffer, a_message, stringLen);
	nocash_buffer[stringLen] = '\0';
	nocash_message();
}

//String
void Print(std::string a_message)
{
	std::string str(a_message);

	const char* output = str.c_str();

	int stringLen = strlen(output);
	strncpy(nocash_buffer, output, stringLen);
	nocash_buffer[stringLen] = '\0';
	nocash_message();
}

//int
void Print(int a_message)
{
	std::stringstream stream;
	stream << a_message;
	std::string str = stream.str();

	const char* output = str.c_str();

	int stringLen = strlen(output);
	strncpy(nocash_buffer, output, stringLen);
	nocash_buffer[stringLen] = '\0';
	nocash_message();
}

//fixed
void Print(fixed a_message)
{
	std::stringstream stream;
	stream << a_message;
	std::string str = stream.str();

	const char* output = str.c_str();

	int stringLen = strlen(output);
	strncpy(nocash_buffer, output, stringLen);
	nocash_buffer[stringLen] = '\0';
	nocash_message();
}
#pragma endregion

void delay(unsigned int a_amount)
{
	for (int i = 0; i < a_amount * 10; i++);
}

int main()
{
	REG_DISPLAYCONTROL = VIDEOMODE_0 | ENABLE_OBJECTS | BGMODE_0 | MAPPINGMODE_1D;

	//GBA_Background background(bgPalette, bgPaletteLen, 0, bgTiles, bgTilesLen, 8, bgMap, bgMapLen, BGMODE_0);
	//background.SetBackgroundController(0, 0, 0, 0, A0_4BPP, 16, 0, BG_REG_SIZE_32x32);
	//
	//GBA_Background forground(bgPalette, bgPaletteLen, 1, fgTiles, fgTilesLen, 16, fgMap, fgMapLen, BGMODE_1);
	//forground.SetBackgroundController(0, 0, 1, 0, A0_4BPP, 16, 0, BG_REG_SIZE_32x32);

	MegaMan megaMan;
	megaMan.LoadResources();

	//loop forever
	while (1)
	{
		vsync();
		PollKeys();

		Print(fix2int(megaMan.m_yPos));

		megaMan.Update();
	}

	return 0;
}