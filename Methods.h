#pragma once

#include "Variables.h"
#include <vector>
#include <string>

class methods
{
	public:

		// all main methods for game mechanics
		void mainMenu();
		void printRules();
		void rollSlots(int slot, char coloumn1, char column2, char column3);
		void rollStopped();
		void jackpotWon(int amountWon); // used to add to te players curret money when jackpot is won
		void initialiseVars();
		void printStats();
		void topupMoney();
		void placeBet();

		int exitGame();
		void checkWin(char column1, char column2, char column3); // used to place bet for current roll

		// all extra methods for hiding cursor etc
		void showConsoleCursor(bool showFlag);


		// Methods used for saving and loading files into the game
		void saveGame(variables* myVars);
		void loadGame(variables* myVars);

		void getFileNames(std::vector<std::string>* fileList);
};