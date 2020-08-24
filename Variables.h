#pragma once

#include <string>

class variables
{
	public:
		// all integers used to store values
		int currentRoll{ 0 }; // 0 = first roll, 1 = second roll, 3 = third roll
		int userKey{ 0 };
		int randomChar{ 0 };
		int money{ 500 };
		int timesPlayed{ 0 };
		int timesWon{ 0 };
		int timesLost{ 0 };
		int moneyToTakeAway{ 100 };
		int moneyToAdd{ 0 };
		int newBet{ 0 };

		std::string saveName{ "" };

		// all characters to store values for first, second and third column plus stop key and all characters in slot machine
		char key{'S'};
		char firstColumn{'_'};
		char secondColumn{'_'};
		char thirdColumn{'_'};
		const char slotCharacters[20] = { '1', '2', '3', '4', '5', '6', '7', '8', '9', '#', '~', '!' };

		// all bools responsible for telling the game when a slot is stopped
		bool firstRowStopped{ false };
		bool secondRowStopped{ false };
		bool thirdRowStopped{ false };
		bool hasWonJackpot{ false };
};