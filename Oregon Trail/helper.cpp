#include "Helper.hpp"


#ifdef _WIN32

#include <windows.h>

void helper::go_to_xy(const int x, const int y)
{
	const COORD point = {static_cast<short>(x), static_cast<short>(y)};
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), point);
}

void helper::clear_console()
{
	const COORD top_left = { 0, 0 };
	const auto console = GetStdHandle(STD_OUTPUT_HANDLE);
	CONSOLE_SCREEN_BUFFER_INFO screen;
	DWORD written;

	GetConsoleScreenBufferInfo(console, &screen);
	FillConsoleOutputCharacterA(
		console, ' ', screen.dwSize.X * screen.dwSize.Y, top_left, &written
	);
	FillConsoleOutputAttribute(
		console, FOREGROUND_GREEN | FOREGROUND_RED | FOREGROUND_BLUE,
		screen.dwSize.X * screen.dwSize.Y, top_left, &written
	);

	SetConsoleCursorPosition(console, top_left);
}

#else

#include <unistd.h>
#include <term.h>

static void helper::go_to_xy(int x, int y)
{
	int err;
	if (!cur_term)
		if (setupterm(NULL, STDOUT_FILENO, &err) == ERR)
			return;
	putp(tparm(tigetstr("cup"), y, x, 0, 0, 0, 0, 0, 0, 0));
}

void helper::clear_console()
{
	// CSI[2J clears screen, CSI[H moves the cursor to top-left corner
	std::cout << "\x1B[2J\x1B[H";
}

#endif
