#include <iostream>
#include <fstream>
#include <string>
#include <stdlib.h>
#include <vector>
#include <string>
#include <iostream>

#include "Methods.h"
#include <windows.h>
#include <iterator>
#include <iterator>

void methods::saveGame(variables* myVars)
{
	std::ofstream saveFile("/Saves/*.txt");
	
	std::cout << "\nPlease give your save file a name:\n";
	std::cin >> myVars->saveName;
	myVars->saveName += ".txt";

	if (!saveFile.is_open())
	{
		// DELETE FILE IF ALREADY EXISTS OR CREATE NEW IF IT DOESN'T
		//saveFile.clear();
		saveFile.open(myVars->saveName);
		saveFile << myVars->money << "\n";
		saveFile << myVars->timesPlayed << "\n";
		saveFile << myVars->timesWon << "\n";
		saveFile << myVars->timesLost << "\n";
		saveFile.close();
	}

	std::cout << "\nGame has been saved!";

	this->mainMenu();
}

void methods::loadGame(variables* myVars)
{
	// LOAD IN SAVE FILE AND REPLACE CURRENT VARIABLE VALUES WITH SAVED ONES

	std::ifstream fileLoaded ("/Saves/ * .txt");

	std::vector<std::string> listOfSaves;
	this->getFileNames(&listOfSaves);

	std::cout << "\nPlease choose which save file you want to use:";

	for (std::vector<std::string>::iterator it = listOfSaves.begin(); it != listOfSaves.end(); ++it)
	{
		std::cout << "\n" << *it;
	}

	std::cout << "\n";
	std::cin >> myVars->saveName;
	myVars->saveName += ".txt";

	if (!fileLoaded.is_open())
	{
		fileLoaded.open(myVars->saveName);
		fileLoaded >> myVars->money >> myVars->timesPlayed >> myVars->timesWon >> myVars->timesLost;
		fileLoaded.close();
	}

	std::cout << "\nPrevious Game loaded!";

	this->mainMenu();
}

void methods::getFileNames(std::vector<std::string>* fileList)
{
	std::vector<std::string> fileNames;

	WIN32_FIND_DATA search_data;

	memset(&search_data, 0, sizeof(WIN32_FIND_DATA));

	HANDLE handle = FindFirstFile("/Saves/*.txt", &search_data);

	while (handle != INVALID_HANDLE_VALUE)
	{
		fileList->emplace_back(std::string(search_data.cFileName));

		if (FindNextFile(handle, &search_data) == FALSE)
		{
			break;
		}
	}
}