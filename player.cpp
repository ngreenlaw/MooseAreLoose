/*************************************
Nathan Greenlaw
ONID: greenlan
11/30/16
Final Project: The Moose are Loose
*************************************/

/*************************************
Source File for Player Class
*************************************/

#include "player.h"
#include <iostream>
#include <stdlib.h>

/*************************************
Constructor for Player Class
Sets the currentRoom to the starting room (Front Lawn)
Sets bag to 6 empty slots
*************************************/

Player::Player(Room* startRoom, int mooseLeft)
{
	currentRoom = startRoom;
	std::vector<std::string> inBag(6,"none");
	bag = inBag;
	mooseRemaining = mooseLeft;
}

/*************************************
int Player::move()
Allows the player to move inbetween rooms
returns 0 if going back to the action menu and 1 otherwise
*************************************/

//Move function for navigating the house
int Player::move()
{
	//Gets the current room the player is in
	Room* inRoom = currentRoom;

	//Gets where where the player can move
	Room* r = inRoom->getRight();
	Room* l = inRoom->getLeft();
	Room* u = inRoom->getUp();
	Room* d = inRoom->getDown();

	//Get Name of the rooms
	std::string rName;
	std::string lName;
	std::string uName;
	std::string dName;

	//Vector of possible rooms
	std::vector<Room*> roomOptions;
	std::vector<std::string> roomOptionsName;

	if (r != NULL)
	{
		rName = r->getNameOfRoom();
		roomOptions.push_back(r);
		roomOptionsName.push_back(rName);

	}

	if (l != NULL)
	{
		lName = l->getNameOfRoom();
		roomOptions.push_back(l);
		roomOptionsName.push_back(lName);
	}

	if (u != NULL)
	{
		uName = u->getNameOfRoom();
		roomOptions.push_back(u);
		roomOptionsName.push_back(uName);
	}

	if (d != NULL)
	{
		dName = d->getNameOfRoom();
		roomOptions.push_back(d);
		roomOptionsName.push_back(dName);
	}

	//Adds returning to action menu to end
	//roomOptions.push_back("Back To Menu");

	//Display where the player can move
	std::string roomChoice;
	int roomChoiceInt;

	//add cancel option
	roomOptionsName.push_back("Cancel");

	do
	{
		std::cout << "\nWhere would you like to move?" << std::endl;

		for (int i = 0; i < roomOptionsName.size(); i++)
		{
			std::cout << i + 1 << ". " << roomOptionsName.at(i) << std::endl;
		}

		std::getline(std::cin, roomChoice);
		roomChoiceInt = atoi(roomChoice.c_str());
	} while (!atoi(roomChoice.c_str()) || (roomChoiceInt < 1 || roomChoiceInt > roomOptionsName.size()));

	//Cancelling movement
	if (roomOptionsName.at(roomChoiceInt - 1) == "Cancel")
	{
		return 0;
	}

	//See if Door is locked and set the possible room choice
	Room* possibleRoom = roomOptions.at(roomChoiceInt - 1);
	bool lockedPossibleRoom = possibleRoom->getLockedDoor();
	int itemUsed;

	//ask to see if they want to use an item
	std::string keyChoice;
	int keyChoiceInt;


	//Check to see if the door is locked
	if (lockedPossibleRoom)
	{
		do
		{
			std::cout << "\nThe door is locked. Do you want to use a key? \n1. Yes \n2. No" << std::endl;

			std::getline(std::cin, keyChoice);
			keyChoiceInt = atoi(keyChoice.c_str());
		} while (!atoi(keyChoice.c_str()) || (keyChoiceInt < 1 || keyChoiceInt > 2));

		//If they decide not to use a key then return to the action choice
		if (keyChoiceInt == 2)
		{
			return 0;
		}

		//Display the bag to choose which item you want
		itemUsed = chooseFromBag();

		//Exiting Bag and return to action menu
		if (itemUsed == 6)
		{
			return 0;
		}

		//if the key matches then set the room to unlocked and move into it
		if (bag.at(itemUsed) == possibleRoom->getKeyToUnlockRoom())
		{
			std::cout << "\nYou tried the " << bag.at(itemUsed) << " and it worked!" << std::endl;
			std::cout << "You moved to the " << possibleRoom->getNameOfRoom() << "." << std::endl;

			//Use the item and set it's slot to none
			bag.at(itemUsed) = "none";

			possibleRoom->setLockedDoor(false);
			currentRoom = possibleRoom;
		}

		//
		else
		{
			std::cout << "\nYou tried the " << bag.at(itemUsed) << " and it did not work." << std::endl;
			return 0;
		}
	}

	//If the door isn't locked, move to the choosen room
	else
	{
		currentRoom = possibleRoom;
		std::cout << "\nYou moved to the " << possibleRoom->getNameOfRoom() << "." << std::endl;
	}

	return 1;
}

/*************************************
int Player::search()
Allows the player to search the room
returns 0 if going back to the action menu and 1 otherwise
*************************************/

//Search Function for Looking around the room
int Player::search()
{
	//Room the player is in
	Room* thisRoom = currentRoom;

	//Searching options
	std::vector<std::string> searchOptions;
	std::string searchChoice;
	int searchChoiceInt;

	std::cout << "\nYou begin to search around the " << thisRoom->getNameOfRoom() << "." << std::endl;

	//if the lights are on you can search, otherwise you must turn the lights on before searching
	if (thisRoom->getLightsOn() == true)
	{

		//Say if there is a moose
		if (thisRoom->getMooseInRoom() == true)
		{
			std::cout << "There is a moose loose in the " << thisRoom->getNameOfRoom() << "!" << std::endl;
		//	std::cout << typeMoose() << std::endl;

			searchOptions.push_back("Attempt to remove the moose.");
		}

		//Say if there is an item
		if (thisRoom->getItemInRoom() == true)
		{
			std::cout << "There is a " << thisRoom->getTypeOfItemInRoom() << " in the area!" << std::endl;
			searchOptions.push_back("Pick up Item.");
		}

		//check to see if there are any options
		if (searchOptions.size() == 0)
		{
			std::cout << "There is nothing unusual or useful in this room." << std::endl;
			return 1;
		}

		else
		{
			//int searchElements;
			searchOptions.push_back("Nothing");
			//Give option for choosing what to do
			do
			{
				std::cout << "\nWhat would you like to do?" << std::endl;

				for (int i = 0; i < searchOptions.size(); i++)
				{
					std::cout << i + 1 << ". " << searchOptions.at(i) << std::endl;
				//	searchElements = i + 1;
				}
				//searchOptions.push_back("Nothing");
				//std::cout << searchElements + 1 << ". " << searchOptions.at(searchElements);

				std::getline(std::cin, searchChoice);
				searchChoiceInt = atoi(searchChoice.c_str());
			} while (!atoi(searchChoice.c_str()) || (searchChoiceInt < 1 || searchChoiceInt > searchOptions.size()));

			if (searchOptions.at(searchChoiceInt - 1) == "Nothing")
			{
				return 0;
			}

			else
			{
				//Remove Moose choice
				int itemTried;

				if (searchOptions.at(searchChoiceInt - 1) == "Attempt to remove the moose.")
				{
				//	std::cout << typeMoose() << std::endl;
					std::cout << "\nScare the moose away using an item!" << std::endl;

					//add cases for if the correct item is used on the correct moose
					//add new remove moose function that copies typeMoose() and changes it to use item choose and match it against the choosen moose's feared object

					//Display the bag to choose which item you want
					itemTried = chooseFromBag();

					//Exiting Bag and return to action menu
					if (itemTried == 6)
					{
						return 0;
					}

					//if the key matches then set the room to unlocked and move into it
					if (bag.at(itemTried) == thisRoom->getMooseAfraidOf())
					{
						std::cout << "\nYou tried the " << bag.at(itemTried) << " and it worked!" << std::endl;
						std::cout << "The moose gallops away in from the one thing it fears most!" << std::endl;
						thisRoom->setMooseInRoom(false);
						thisRoom->setMooseAfraidOf("none");
						thisRoom->setTypeOfMooseInRoom("none");
						bag.at(itemTried) = "none";

						mooseRemaining--;
				
						if (mooseRemaining > 0)
						{
							std::cout << "There are " << mooseRemaining << " moose loose in your home! The hunt continues." << std::endl;
						}
					}

					//
					else
					{
						std::cout << "\nYou tried the " << bag.at(itemTried) << " and it did not work, a little bit of laughter seems to be coming from the moose." << std::endl;
						return 0;
					}
				}

			

				//pick up item choice
				int puItem;
				std::string puItemString;

				if (searchOptions.at(searchChoiceInt - 1) == "Pick up Item.")
				{
					puItem = putItemInBag(thisRoom->getTypeOfItemInRoom());
					return puItem;
				}

				return 1;
			}
		}
		}

		//else turn on the lights
		else
		{
			//70% chance of turning on the lights and 30% chance of failing
			int findLight = ((rand() % 10) + 1);

			if (findLight > 3)
			{
				std::cout << "The lights are off but you fumble around for the light switch in the dark and find it!" << std::endl;
				currentRoom->setLightsOn(true);
			}

			else
			{
				std::cout << "The lights are off and you fumble around for the light switch in the dark. You stub your toe, it hurts and the lights are still off... Today can't get much worse." << std::endl;
			}

			return 1;
		}
}

/*************************************
std::string Player::typeMoose()
returns a string that is a hint of which type moose
is in the room
*************************************/

//Function to look at moose type when removing
std::string Player::typeMoose()
{
	Room* mooseRoom = currentRoom;
	std::string mooseType = mooseRoom->getTypeOfMooseInRoom();

	if (mooseType == "smellyMoose")
	{
		return "The stench in the room is horrible... this is one smelly moose!";
	}

	else if (mooseType == "sleepyMoose")
	{
		return "The moose looks up through barely open eyelids... it seems that the moose is very sleepy.";
	}

	else if (mooseType == "vegetarianMoose")
	{
		return "The moose looks at you with leaves in its mouth and looks like it would never want to eat you. Maybe it is a vegetarian?";
	}

	else if (mooseType == "poshMoose")
	{
		return "The moose is looking around the area unimpressed... it seems to not like any furniture or decorations that are tacky.";
	}

	else if (mooseType == "copycatMoose")
	{
		return "Wait a second! This moose is wearing your clothing! Show this moose that they are not a human!";
	}
}

/*************************************
int Player::putItemInBag()
Allows the player to put an item in the bag
returns a 0 if they decide not to sawp out an iteam
and a 1 otherwise
*************************************/

//Function to put an item in the bag return 0 if not swapping and 1 if so
int Player::putItemInBag(std::string newItem)
{
	//check to see if there is an available slot
	int slotOpen = 0;

	//variables to discard an item
	std::string discardChoice;
	int discardChoiceInt;
	int discardedItem;


	for (int i = 0; i < 6; i++)
	{
		if (bag.at(i) == "none")
		{
			//replace first empty slot
			bag.at(i) = newItem;

			//reset room items to having nothing
			currentRoom->setItemInRoom(false);
			currentRoom->setTypeOfItemInRoom("none");

			std::cout << "You place the " << newItem << " in your bag." << std::endl;			
			//end loop
			i = 10;
			slotOpen = i;
			return 1;
		}
	}

	//There were no empty spots
	if (slotOpen == 0)
	{
		std::cout << "Your bag is full, swap an item out for " << newItem << "?" << std::endl;
		do
		{
			std::cout << "1. Yes \n2. No" << std::endl;

			std::getline(std::cin, discardChoice);
			discardChoiceInt = atoi(discardChoice.c_str());
		} while (!atoi(discardChoice.c_str()) || (discardChoiceInt < 1 || discardChoiceInt > 2));

		//if choosing to swap for an item
		if (discardChoiceInt == 1)
		{
			std::cout << "\nWhich item would you like to swap " << newItem << " with?" << std::endl;
			discardedItem = chooseFromBag();

			//If the exit bag option wasn't choosen
			if (discardedItem != 6)
			{
				currentRoom->setItemInRoom(true);
				currentRoom->setTypeOfItemInRoom(bag.at(discardedItem));
				std::cout << "You dropped the " << bag.at(discardedItem) << " and replaced it with the " << newItem << "." << std::endl;
				bag.at(discardedItem) = newItem;
				return 1;
			}

		}
	}
	return 0;
}

/*************************************
void Player::displayBag()
Displays the items in your bag
*************************************/

//Function to display bag
void Player::displayBag()
{
	std::cout << "\nThe items in your bag are: " << std::endl;

	for (int i = 0; i < bag.size(); i++)
	{
		std::cout << i+1 << ". " << bag.at(i) << std::endl;
	}
}

/*************************************
int Player::chooseFromBag()
Allows to choose an item from their bag
returns the location in the bag of the item
they choose
*************************************/

//Function to choose from bag
int Player::chooseFromBag()
{
	//bag choice variables
	std::string bagChoice;
	int bagChoiceInt;

	do
	{
		std::cout << "\nChoose an item from your bag with the last option being no selection" << std::endl;
		displayBag();
		std::cout << "7. Exit the Bag" << std::endl;
		std::getline(std::cin, bagChoice);
		bagChoiceInt = atoi(bagChoice.c_str());
	} while (!atoi(bagChoice.c_str()) || (bagChoiceInt < 1 || bagChoiceInt > 7));

	return bagChoiceInt - 1;
}

/*************************************
Room* Player::getCurrentRiim()
returns the player's current location
*************************************/

Room* Player::getCurrentRoom()
{
	return currentRoom;
}

/*************************************
int Player::getMooseRemaining()
returns the number of moose left in the house
*************************************/

int Player::getMooseRemaining()
{
	return mooseRemaining;
}
