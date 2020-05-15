// semesterproject.cpp : This file contains the 'main' function. Program execution begins and ends there.
// By: David Garza
// Date: 20200514
// Description: Dungeon Crawling game. Collect coins and find your way out. Watch out for traps!
// Note: Art may be skewed.



#include <iostream>
#include <string>
#include <time.h>
#include <random>
#include <vector>
#include "Room.h"




void displaySplashScreen() {
std::cout << "  __   __           _   _         __   __ _            " << std::endl;
std::cout << " |  \_/  |         | | (_)       |  \_/  (_)           " << std::endl;
std::cout << " | \   / |_   _ ___| |_ _  ___   | \   / |_ _ __   ___ " << std::endl;
std::cout << " | |\_/| | | | / __| __| |/ __|  | |\_/| | | '_ \ / _ \ " << std::endl;
std::cout << " | |   | | |_| \__ \ |_| | (__   | |   | | | | | |  __/" << std::endl;
std::cout << " |_|   |_|\__, |___/\__|_|\___|  |_|   |_|_|_| |_|\___|" << std::endl;
std::cout << "           __/ |                                     " << std::endl;
std::cout << "          |___/                                      " << std::endl;
	std::cout << "" << std::endl;
	//Credit to Spicer from ASCII Art
	std::cout <<  "_____________________________________________" << std::endl;
	std::cout << "|.'',            Mystic_Mine              ,''.|" << std::endl;
	std::cout << "|.'.'',                                 ,''.'.|" << std::endl;
	std::cout << "|.'.'.'',                             ,''.'.'.|" << std::endl;
	std::cout << "|.'.'.'.'',                         ,''.'.'.'.|" << std::endl;
	std::cout << "|.'.'.'.'.|                         |.'.'.'.'.|" << std::endl;
	std::cout << "|.'.'.'.'.|===;                 ;===|.'.'.'.'.|" << std::endl;
	std::cout << "|.'.'.'.'.|:::|',             ,'|:::|.'.'.'.'.|" << std::endl;
	std::cout << "|.'.'.'.'.|---|'.|, _______ ,|.'|---|.'.'.'.'.|" << std::endl;
	std::cout << "|.'.'.'.'.|:::|'.|'|???????|'|.'|:::|.'.'.'.'.|" << std::endl;
	std::cout << "|,',',',',|---|',|'|???????|'|,'|---|,',',',',|" << std::endl;
	std::cout << "|.'.'.'.'.|:::|'.|'|???????|'|.'|:::|.'.'.'.'.|" << std::endl;
	std::cout << "|.'.'.'.'.|---|','   /%%%\   ','|---|.'.'.'.'.|" << std::endl;
	std::cout << "|.'.'.'.'.|===:'    /%%%%%\    ':===|.'.'.'.'.|" << std::endl;
	std::cout << "|.'.'.'.'.|%%%%%%%%%%%%%%%%%%%%%%%%%|.'.'.'.'.|" << std::endl;
	std::cout << "|.'.'.'.','       /%%%%%%%%%\       ','.'.'.'.|" << std::endl;
	std::cout << "|.'.'.','        /%%%%%%%%%%%\        ','.'.'.|" << std::endl;
	std::cout << "|.'.','         /%%%%%%%%%%%%%\         ','.'.|" << std::endl;
	std::cout << "|.','          /%%%%%%%%%%%%%%%\          ','.|" << std::endl;
	std::cout << "|;____________/%%%%%%%%%%%%%%%%%\____________;|" << std::endl;
	std::cout << "" << std::endl;
	
	
}

void displayMainMenu() {
	// Main Menu
	std::cout << "\nMain Menu" << std::endl;
	
	std::cout << "s) Start Game" << std::endl;

	std::cout << "q) Quit Game" << std::endl;
	std::cout << "What would you like to do: ";
}
int determineHighScore(int& intCurrentHighScore, int intPotentialHighScore) {
	if (intPotentialHighScore >= intCurrentHighScore) {
		intCurrentHighScore = intPotentialHighScore;
	}
	return intCurrentHighScore;
}


int calculateHighScore(int intNumberOfItems, int intNumberOfCoins) {
	
	return ((intNumberOfItems * 500) + (intNumberOfCoins * 100));
}




int main()
{
	srand((unsigned int)time(NULL));
	// Variables
	std::vector<Room> vtrRoom(7);
	int intNumberOfCoins = 0;
	int intNumberOfItems = 0;
	int intStartingNumberOfLives = 3;
	int intCurrentRoomIndex = 0;
	int intNumberOfRooms = 7;
	int intNumberOfLives = intStartingNumberOfLives;
	int intHighScore = 5000;
	char chrMenuChoice = ' ';
	char chrDirectionChoice = ' ';
	std::string strAcceptedChoiceInRoom = "wasd0ict";
	bool boolWinCondition = false;
	Room objTempRoom;

	displaySplashScreen();

	do {
		displayMainMenu();

		std::cin >> chrMenuChoice;

		switch (chrMenuChoice) {
		case 's':
			// Setup of game state for new game place Start the game
			intNumberOfCoins = 0;
			intNumberOfItems = 0;
			intNumberOfLives = intStartingNumberOfLives;
			boolWinCondition = false;
			vtrRoom.clear();

			objTempRoom = Room();
			objTempRoom.setNorth(1);
			objTempRoom.setEast(2);
			objTempRoom.setSouth(3);
			objTempRoom.setWest(4);
			vtrRoom.push_back(objTempRoom);
			objTempRoom = Room();
			objTempRoom.setSouth(0);
			objTempRoom.setEast(5);
			vtrRoom.push_back(objTempRoom);
			objTempRoom = Room();
			objTempRoom.setWest(0);
			objTempRoom.setSouth(6);
			vtrRoom.push_back(objTempRoom);
			objTempRoom = Room();
			objTempRoom.setNorth(0);
			vtrRoom.push_back(objTempRoom);
			objTempRoom = Room();
			objTempRoom.setEast(0);
			vtrRoom.push_back(objTempRoom);
			objTempRoom = Room();
			objTempRoom.setSouth(2);
			objTempRoom.setWest(1);
			vtrRoom.push_back(objTempRoom);
			objTempRoom = Room();
			objTempRoom.setNorth(2);
			vtrRoom.push_back(objTempRoom);

			std::cout << "You awake in a room that looks like a mine shaft, no one has been here for a while." << std::endl;
			// Main game room movement and search loop
			while (boolWinCondition != true && intNumberOfLives > 0) {
				std::cout << "Player Stats: Lives: " << intNumberOfLives << ", Items: " << intNumberOfItems << ", Coins: " << intNumberOfCoins << std::endl;
				std::cout << "You enter a room in the mine shaft ..." << std::endl;

				Room objRoom = vtrRoom.at(intCurrentRoomIndex);
				std::cerr << objRoom.toString() << std::endl;

				//Loop for correct user input
				do {

					std::cout << "Which direction do you want to go (w [go North], a [go West], s [go South], d [go East])? " << std::endl;
					std::cout << "What would you like to do (c [Search for Coins], i [Search for items], t [Search for traps)? ";
					std::cin >> chrDirectionChoice;
				} while (strAcceptedChoiceInRoom.find(chrDirectionChoice) == std::string::npos);


				//Logic for handling user input choice
				switch (chrDirectionChoice) {
				case 'w': //Walk North
					std::cout << "You walk north..." << std::endl;
					objRoom.checkForTrap(intNumberOfLives);
					if (objRoom.getNorth() > -1) {
						intCurrentRoomIndex = objRoom.getNorth();
					}
					else {
						std::cout << " and hit a wall!" << std::endl;
					}

					break;
				case 'a': //Walk West
					std::cout << "You walk west..." << std::endl;
					objRoom.checkForTrap(intNumberOfLives);
					if (objRoom.getWest() > -1) {
						intCurrentRoomIndex = objRoom.getWest();
					}
					else {
						std::cout << " and hit a wall!" << std::endl;
					}

					break;
				case 's': //Walk South
					std::cout << "You walk south..." << std::endl;
					objRoom.checkForTrap(intNumberOfLives);
					if (objRoom.getSouth() > -1) {
						intCurrentRoomIndex = objRoom.getSouth();
					}
					else {
						std::cout << " and hit a wall!" << std::endl;
					}

					break;
				case 'd': //Walk East
					std::cout << "You walk east..." << std::endl;
					objRoom.checkForTrap(intNumberOfLives);
					if (objRoom.getEast() > -1) {
						intCurrentRoomIndex = objRoom.getEast();
					}
					else {
						std::cout << " and hit a wall!" << std::endl;
					}

					break;
				case 'i': //Search for items
					std::cout << "You search for items in the room...";
					if (objRoom.checkForItem()) {
						intNumberOfItems++;
						intNumberOfLives++;
						std::cout << "You find a piece of a medallion. An aura surrounds it.";
							std::cout << " \ " << std::endl;
							std::cout << "      _____    " << std::endl;
							std::cout << " `   /    / " << std::endl;
							std::cout << "    /  \  \  " << std::endl;
							std::cout << "   /       /" << std::endl;
							std::cout << "_ /   _ _ /" << std::endl;
							std::cout << "  \       \ " << std::endl;
							std::cout << "   \      / " << std::endl;
							std::cout << "    \  / / " << std::endl;
							std::cout << " '   \___\ " << std::endl;
							std::cout << " / " << std::endl;
							std::cout << "" << std::endl;
						if (intNumberOfItems >= 2) {
							boolWinCondition = true;
						}
					}
					else {
						std::cout << " you end up empty handed.";
					}
					break;
				case 'c': //Search for coins
					std::cout << "You search for coins in the room...";
					if (objRoom.getCoins() > 0) {

						intNumberOfCoins += objRoom.getCoins();

						std::cout << " you found " << objRoom.getCoins() << " coin(s)." << std::endl;;
						std::cout << " ,,, " << std::endl;
						std::cout << "{($)}" << std::endl;
						std::cout << " ''' " << std::endl;
						std::cout << "" << std::endl;
					}
					else {
						std::cout << " you end up empty handed.";
					}
					break;
				case 't': //Search for traps
					std::cout << "You search for traps in the room...";
					if (objRoom.checkForTrap(intNumberOfLives, true)) {
						// Logic moved into class
					}
					else {
						std::cout << " there are no traps.";
					}
					break;
				case '0': //Developers exit menu trick.
					intNumberOfLives = 0;
					break;
				} // Switch for player choices in rooom
				std::cout << std::endl;
			} /// Game Loop


			break;
		case 'q':
			//TODO: Calculate High Score
			std::cout << "\nYour vision fades, you " << (boolWinCondition ? "wake up outside, medallion in hand." : "perish.");
			std::cout << "\nYour Score: " << calculateHighScore(intNumberOfItems, intNumberOfCoins);
			std::cout << "\nHigh Score: " << determineHighScore(intHighScore, calculateHighScore(intNumberOfItems, intNumberOfCoins));
			break;
		}
	} while (chrMenuChoice != 'q');

	std::cout << std::endl;

	return 0;
}