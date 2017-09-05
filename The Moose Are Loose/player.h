/*************************************
Nathan Greenlaw
ONID: greenlan
11/30/16
Final Project: The Moose are Loose
*************************************/

/*************************************
Header File for Player Class
*************************************/

#ifndef PLAYER_H
#define PLAYER_H

#include "stdafx.h"
#include "room.h"
#include <vector>

class Player
{
public:
	Player(Room*,int);
	//~Player();

	//Move function for navigating the house
	int move();

	//Search Function for Looking around the room
	int search();

	//Function to look at moose type when removing
	std::string typeMoose();

	//Function to get teh moose remaining
	int getMooseRemaining();

	//Function to put an item in the bag
	int putItemInBag(std::string);

	//Function to display bag
	void displayBag();

	//Function to choose from bag
	int chooseFromBag();

	//Get function for currentRoom member
	Room* getCurrentRoom();

protected:
	//current room player is in
	Room* currentRoom;

	//vector of items in bag
	std::vector<std::string> bag;

	//Moose left in house
	int mooseRemaining;

	//Time left in the game (Move to main function)
	int timeLeft;
};

#endif
