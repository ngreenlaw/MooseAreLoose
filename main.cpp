/*************************************
Nathan Greenlaw
ONID: greenlan
11/30/16
Final Project: The Moose are Loose
*************************************/

/*************************************
Main file for executing program
*************************************/

//player.h has room, vector and string headers in it
#include "player.h"
//for cout and getline
#include <iostream>
//for rand()
#include <cstdlib>
//for atoi
#include <stdlib.h>
//for time()
#include <time.h>

int main()
{
	//Give random see every time
	srand(time(NULL));

	//create the vector to hold the pointers to rooms
	std::vector<Room*> house;

	//Create all the rooms and add them to the house with the rooms with locks being added first to avoid an infinte loop when assigning items

	//Create the living room object and pointer
	LivingRoom livingRoomObject;
	LivingRoom* livingRoom = &livingRoomObject;
	house.push_back(livingRoom);

	//Create the garage object and pointer
	Garage garageObject;
	Garage* garage = &garageObject;
	house.push_back(garage);

	//Create the bathroom object and pointer
	Bathroom bathroomObject;
	Bathroom* bathroom = &bathroomObject;
	house.push_back(bathroom);

	//Create the kids bedroom object and pointer
	KidsBedroom kidsBedroomObject;
	KidsBedroom* kidsBedroom = &kidsBedroomObject;
	house.push_back(kidsBedroom);

	//Create the master bedroom object and pointer
	MasterBedroom masterBedroomObject;
	MasterBedroom* masterBedroom = &masterBedroomObject;
	house.push_back(masterBedroom);

	//Create the master bathrooom object and pointer
	MasterBathroom masterBathroomObject;
	MasterBathroom* masterBathroom = &masterBathroomObject;
	house.push_back(masterBathroom);

	//Create the Front Lawn object and pointer
	FrontLawn frontLawnObject;
	FrontLawn* frontLawn = &frontLawnObject;
	house.push_back(frontLawn);

	//Create the backyard object and pointer
	Backyard backyardObject;
	Backyard* backyard = &backyardObject;
	house.push_back(backyard);

	//Create the kitchen object and pointer
	Kitchen kitchenObject;
	Kitchen* kitchen = &kitchenObject;
	house.push_back(kitchen);

	//Create the hallway object and pointer
	Hallway hallwayObject;
	Hallway* hallway = &hallwayObject;
	house.push_back(hallway);

	//Create the roof object and pointer
	Roof roofObject;
	Roof* roof = &roofObject;
	house.push_back(roof);

//std::cout << masterBathroom->getKeyToUnlockRoom() <<std::endl;
//std::cout << roof->getTypeOfItemInRoom() <<std::endl;
	
	//Set all room pointers

	frontLawn->setRLUDPointers(garage, backyard, livingRoom, roof);
	backyard->setRLUDPointers(frontLawn, kidsBedroom, kitchen,garage);
	garage->setRLUDPointers(backyard, livingRoom, NULL, frontLawn);
	livingRoom->setRLUDPointers(garage, kitchen, hallway, frontLawn);
	kitchen->setRLUDPointers(livingRoom, NULL, bathroom, backyard);
	bathroom->setRLUDPointers(NULL, NULL, NULL, kitchen);
	kidsBedroom->setRLUDPointers(backyard, hallway, roof, NULL);
	hallway->setRLUDPointers(kidsBedroom, masterBedroom, roof, livingRoom);
	masterBedroom->setRLUDPointers(hallway, masterBathroom, roof, NULL);
	masterBathroom->setRLUDPointers(masterBedroom, NULL, NULL, NULL);
	roof->setRLUDPointers(kidsBedroom, masterBedroom, frontLawn, hallway);


	//Create number of moose in the house by asking for level of diifculty
	int numMooseInvaders;// = (rand() % 5) + 2;
	std::string mooseInvaders;

	do
	{
		std::cout << "Choose your difficulty: \n1. Very Easy \n2. Easy \n3. Medium \n4. Hard \n5. Very Hard" << std::endl;

		std::getline(std::cin, mooseInvaders);
		numMooseInvaders = atoi(mooseInvaders.c_str());
	} while (!atoi(mooseInvaders.c_str()) || (numMooseInvaders < 1 || numMooseInvaders > 5));



	//place moose around house

	//create vector of moose
	std::vector<std::string> mooseList;
	mooseList.push_back("smellyMoose");
	mooseList.push_back("sleepyMoose");
	mooseList.push_back("vegetarianMoose");
	mooseList.push_back("poshMoose");
	mooseList.push_back("copycatMoose");

	std::vector<std::string> mooseInHouse;
	std::string addMoose;
	int mooseChoosen;
	std::string addMooseToHouse;
	int mooseAddedToHouse;
	Room* roomToAddMoose;

	//Randomly select moose to put in house
	for (int i = 0; i < numMooseInvaders; i++)
	{
		mooseChoosen = (rand() % mooseList.size());
		addMoose = mooseList.at(mooseChoosen);
		mooseInHouse.push_back(addMoose);
		mooseList.erase (mooseList.begin()+mooseChoosen);
	}

	int startingMooseInHouseSize = mooseInHouse.size();
	//Add moose to rooms
	for (int j = 0; j < startingMooseInHouseSize; j++)
	{
		//loop until a room with no moose is picked
		do
		{
			mooseAddedToHouse = (rand() % house.size());
			roomToAddMoose = house.at(mooseAddedToHouse);
		} while (roomToAddMoose->getMooseInRoom() == true);

		//take the moose in the list of moose in the house and add it to the room
		addMooseToHouse = mooseInHouse.at(j);
		roomToAddMoose->setMooseInRoom(true);
		roomToAddMoose->setTypeOfMooseInRoom(addMooseToHouse);
		roomToAddMoose->setMooseAfraidOf(addMooseToHouse);
	}



	//adding items to room
	std::vector<Room*> houseVector;
	houseVector = house;

	//creating items list
	std::vector<std::string> itemsInGame;

	itemsInGame.push_back("Living Room Key");
	itemsInGame.push_back("Garage Key");
	itemsInGame.push_back("Bathroom Key");
	itemsInGame.push_back("Kid's Bedroom Key");
	itemsInGame.push_back("Master Bedroom Key");
	itemsInGame.push_back("Master Bathroom Key");
	itemsInGame.push_back("air freshener");
	itemsInGame.push_back("alarm clock");
	itemsInGame.push_back("meat");
	itemsInGame.push_back("garden gnome");
	itemsInGame.push_back("mirror");

	//add items to room
	int itemChoosen;
	int roomForItem;
	std::string item;
	Room* roomItemChoosen;
	int startingItemSize = itemsInGame.size();

		std::cout<< "The locations of the items and moose for easy testing, see my reflection document for a map of the rooms." <<std::endl;

	for (int k = 0; k < startingItemSize; k++)
	{

		//randomly select room and item
		do
		{
			itemChoosen = (rand() % itemsInGame.size());
			//roomForItem = k; //(rand() % houseVector.size()); for choosing rooms randomly, switched to just running through the list
			item = itemsInGame.at(itemChoosen);
			roomItemChoosen = houseVector.at(0); //roomForItem);

			if(roomItemChoosen->getKeyToUnlockRoom() != item)
			{
			//test line to print out where everything is for the graders
			std::cout << "The " <<  roomItemChoosen->getNameOfRoom()<< " has the " << item << " and the moose it has is "<< roomItemChoosen->getTypeOfMooseInRoom() << " that is afraid of " << roomItemChoosen->getMooseAfraidOf() << "\n" << std::endl;
			}
		} while ((roomItemChoosen->getKeyToUnlockRoom()) == item);

		//add item to room
		roomItemChoosen->setItemInRoom(true);
		roomItemChoosen->setTypeOfItemInRoom(item);

		//erase item and room from list
		houseVector.erase (houseVector.begin());//+roomForItem);
		itemsInGame.erase (itemsInGame.begin()+itemChoosen);
	}

	//Create the player and the pointer
	Player pObject(frontLawn, numMooseInvaders);
	Player* p = &pObject;

	//Start the actual game

	std::cout << "		The Moose are Loose!" << std::endl;
	std::cout << "'Typical news, using a crazy title to catch the attention of the listener,' you think to yourself as you listen to the radio on your drive home." << std::endl;
	std::cout << "This type of story was not uncommon anymore, moose had been invading homes for months. Luckily, the nearby schools have been delaying the busses so that parents can get home before their kids." << std::endl;
	std::cout << "You pull up to your driveway after a long day of work, ready to relax but for some reason your garage will not open." << std::endl;
	std::cout << "As you are fumbling with your remote, your elderly neighbor approaches your car in the driveway." << std::endl;
	std::cout << "You roll down the window and your neighbor says that they saw " << numMooseInvaders << " moose enter your house!" << std::endl;
	std::cout << "As this is not the first time this has happened to you, you know you have the required items to repel the mouse in your house." << std::endl;
	std::cout << "Unfortunately, the moose usually are smart enough to move the items and keys to each room around the house." << std::endl;
	std::cout << "You know from the news reports that you only have about 90 minutes from arriving home before the moose stop being scared of you." << std::endl;
	std::cout << "Each moose has its very own 'moosenality' therefore each is scared of a specific item and some moose lock the doors to the room they are in so you may need a key to get in." << std::endl;
	std::cout << "Your goal is to use the items found around the house to repel the moose and take your house back before they take it from you instead." << std::endl;
	std::cout << "There is only one of each type of moose in the house so you will only need the item once and they will not lock the door again once you unlock it." << std::endl;
	std::cout << "The actions you have are moving and searching a room. Each successful action takes a minute of time. You must search a room to see if there is a moose in it, as they are clever." << std::endl;
	std::cout << "Some people have reported that the moose are sometimes too clever and there is no way of taking the house back. To that end you may concede at any time." << std::endl;
	std::cout << "Good luck and may the moose have mercy on your soul.\n" << std::endl;

	int timeLeft = 90;
	std::string actionChoice;
	int actionChoiceInt;
	int actionReturn = 0;

	do
	{
		//Execute actions until either all moose are gone, you run out of time or concede to the moose
		do
		{
			std::cout << "\nYou are in the " << p->getCurrentRoom()->getNameOfRoom() << ".\n" << std::endl;
			//Displays if there is a moose in the room or not if the lights are on
			if(p->getCurrentRoom()->getLightsOn() == true)
			{
				if((p->getCurrentRoom()->getMooseInRoom()) == true)
				{
					std::cout << "There is a moose loose in the " << p->getCurrentRoom()->getNameOfRoom() << "!" << std::endl;
					std::cout << p->typeMoose() << "\n" << std::endl;
				}
			
				else
				{
					std::cout << "There is no moose in this room.\n" << std::endl;
				}
			}

			else
			{
				std::cout << "It is too dark to see anything... try searching for the light switch.\n" << std::endl;
			}

			std::cout << "Select an action to take: \n1. Move \n2. Search/Remove Moose \n3. Look at Bag \n4. Concede to the Moose" << std::endl;

			std::getline(std::cin, actionChoice);
			actionChoiceInt = atoi(actionChoice.c_str());
		} while (!atoi(actionChoice.c_str()) || (actionChoiceInt < 1 || actionChoiceInt > 4));

		switch (actionChoiceInt)
		{
		case 1:
		{
			actionReturn = p->move();
			break;
		}

		case 2:
		{
			actionReturn = p->search();
			break;
		}

		case 3:
		{
			p->displayBag();
			actionReturn = 0;
			break;
		}

		case 4:
		{
			timeLeft = -1;
			actionReturn =0;
			break;
		}

		default:
			break;
		}

		if (actionReturn == 1)
		{
			timeLeft--;
		}

		if( (timeLeft >0) && (p->getMooseRemaining() > 0))
		{
		std::cout << "You have " << timeLeft << " minutes remaining." << std::endl;
		}
		//std::cout << p->getMooseRemaining() << " moose left" << std::endl;

	} while ((timeLeft > 0) && ((p->getMooseRemaining()) > 0)); //Loop until there are no more moose or time is up

	//Won the game!
	if (p->getMooseRemaining() == 0)
	{
		std::cout << "\nSuccess! You breath a sigh of relief as you feel the excitement of victory." << std::endl;
		std::cout << "All of the moose have been repelled from your home..." << std::endl;
		std::cout << "But as you look out the window the moose are still out there, lurking in the background, waiting for the chance to strike again and take your house from you." << std::endl;
		std::cout << "\nThe End" << std::endl;
	}

	else
	{
		//Choose to quit
		if (timeLeft == -1)
		{
			std::cout << "\nThe moose have outsmarted you and taken your house." << std::endl;
			std::cout << "As you run out of your house you hear the sound of hooves clacking... it seems like they are mocking you by applauding your feeble effort..." << std::endl;
			std::cout << "Looks like it is time to start looking for a new place to live." << std::endl;
			std::cout << "\nGame Over" << std::endl;
		}

		//Ran out of time
		else
		{
			std::cout << "\nThe moose have stopped being scared of you and they have grown confident during the time spent in your house. It seems that you have now run out of time." << std::endl;
			std::cout << "The moose have found you in the " << p->getCurrentRoom()->getNameOfRoom() << " this seems to be the end." << std::endl;
			std::cout << "As they draw closer you look up and close your eyes, this is it for you." << std::endl;
			std::cout << "The look in their eyes tells you, first it's your house and next, the world." << std::endl;
			std::cout << "\nGame Over" << std::endl;
		}
	}

	return 0;
}

