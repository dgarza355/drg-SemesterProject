#include <random>
#include <time.h>
#include <iostream>
#include <string>
#include "Room.h"

Room::Room()
{
	srand((unsigned int)time(NULL));
	init();
}


Room::~Room()
{
}


void Room::init()
{
	intNumberOfCoins = 0;
	hasItem = false;
	hasTrap = false;
	intNorthIndex = -1;
	intEastIndex = -1;
	intSouthIndex = -1;
	intWestIndex = -1;
	switch (rand() % 10 + 1)
	{
	case 1: case 3: case 5:
		intNumberOfCoins = 1;
		break;
	case 2: case 4:
		intNumberOfCoins = 2;
		break;
	case 6: case 7:
		hasTrap = true;
		break;
	case 8:
		hasItem = true;
		break;
	default:
		break;
	}
}


int Room::getCoins()
{
	return intNumberOfCoins;
}


bool Room::checkForTrap(int& intpPlayerLives)
{
	if (hasTrap) {
		std::cout << "You triggered a trap and you got hurt." << std::endl;
		std::cout << "     ,--.!, " << std::endl;
		std::cout << "  __/   -*-" << std::endl;
		std::cout << ",d08b.  '|` " << std::endl;
		std::cout << "0088MM     " << std::endl;
		std::cout << "`9MMP'   " << std::endl;
		std::cout << "" << std::endl;
		intpPlayerLives--;
		hasTrap = false;
		std::cout << "You should look for traps next time (t [Search for Traps])!" << std::endl;
		return true;
		
	}
	return false;
}

bool Room::checkForTrap(int& intpPlayerLives, bool doesSearch) {
	if (doesSearch) {
		if ((rand() % 10 + 1) >= 6) {
			return checkForTrap(intpPlayerLives);
		}
		else {
			std::cout << " You cleared the trap." << std::endl;
		}
		hasTrap = false;
	}
	return false;
}

bool Room::checkForItem()
{
	return hasItem;
}


int Room::getNorth() {
	return intNorthIndex;
}

int Room::getEast() {
	return intEastIndex;
}

int Room::getSouth() {
	return intSouthIndex;
}

int Room::getWest() {
	return intWestIndex;
}

int Room::setNorth(int intpIndex) {
	intNorthIndex = intpIndex;
	return getNorth();
}

int Room::setEast(int intpIndex) {
	intEastIndex = intpIndex;
	return getEast();
}

int Room::setSouth(int intpIndex) {
	intSouthIndex = intpIndex;
	return getSouth();
}


int Room::setWest(int intpIndex) {
	intWestIndex = intpIndex;
	return getWest();
}

std::string Room::toString()
{
	std::string strDebug = "DEBUG: Coin? ";
	strDebug += std::to_string(getCoins());
	strDebug += ", Trap? " + hasTrap;
	strDebug += ", Item? " + checkForItem();
	return strDebug;
}
