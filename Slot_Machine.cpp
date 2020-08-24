#include <iostream>
#include "Methods.h"
#include <ctime>  
#include <windows.h>
#include <cstdlib> 

using namespace std;

methods* slotMachine;

void methods::showConsoleCursor(bool showFlag)
{
	HANDLE out = GetStdHandle(STD_OUTPUT_HANDLE);

	CONSOLE_CURSOR_INFO     cursorInfo;

	GetConsoleCursorInfo(out, &cursorInfo);
	cursorInfo.bVisible = showFlag; // set the cursor visibility
	SetConsoleCursorInfo(out, &cursorInfo);
}

int main()
{
	srand(time(0));
	slotMachine->showConsoleCursor(false);
	slotMachine->mainMenu();

	delete slotMachine;
}