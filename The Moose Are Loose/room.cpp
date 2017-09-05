/*************************************
Nathan Greenlaw
ONID: greenlan
11/30/16
Final Project: The Moose are Loose
*************************************/

/*************************************
Source File for Base Room Class and Derived Classes
*************************************/
#include "stdafx.h"
#include "room.h"

/*************************************

Room class functions

*************************************/

Room::~Room()
{
}

	/*************************************

			Item in room functions

	*************************************/

/*************************************
void Room::setItemInRoom(bool)

Set the member itemInRoom to true or false 
if there is or is not an item in the room
*************************************/

void Room::setItemInRoom(bool TF)
{
	itemInRoom = TF;
}

/*************************************
bool Room::getItemInRoom()

Get the member itemInRoom with the value true or false
if there is or is not an item in the room
*************************************/

bool Room::getItemInRoom()
{
	return itemInRoom;
}

/*************************************
void Room::setTypeOfItemInRoom(std::string)

Set the member typeOfItemInRoom to a string
of the item that is in the room, a string of 
"none" means there is no item in the room
*************************************/

void Room::setTypeOfItemInRoom(std::string item)
{
	typeOfItemInRoom = item;
}

/*************************************
std::string Room::getTypeOfItemInRoom()

Set the member typeOfItemInRoom to a string
of the item that is in the room, a string of
"none" means there is no item in the room
*************************************/

std::string Room::getTypeOfItemInRoom()
{
	return typeOfItemInRoom;
}


	/*************************************

			Moose in room functions

	*************************************/

/*************************************
void Room::setMooseInRoom(bool)

Set the member mooseInRoom to true or false
if there is or is not an moose in the room
*************************************/

void Room::setMooseInRoom(bool TFM)
{
	mooseInRoom = TFM;
}

/*************************************
bool Room::getMooseInRoom()

Get the member mooseInRoom with the value true or false
if there is or is not an moose in the room
*************************************/

bool Room::getMooseInRoom()
{
	return mooseInRoom;
}

/*************************************
void Room::setTypeOfMooseInRoom(std::string)

Set the member typeOfMooseInRoom to a string
of the moose that is in the room, a string of
"none" means there is no moose in the room
*************************************/

void Room::setTypeOfMooseInRoom(std::string moose)
{
	typeOfMooseInRoom = moose;
}

/*************************************
std::string Room::getTypeOfMooseInRoom()

Get the member typeOfMooseInRoom which is 
the type moose that is in the room, a string of
"none" means there is no moose in the room
*************************************/

std::string Room::getTypeOfMooseInRoom()
{
	return typeOfMooseInRoom;
}

/*************************************
void Room::setMooseAfraidOf(std::string mooseRepel)

Set the member mooseAfraidOf to a string
of what the moose is afraid of and
"none" means there is no moose in the room
*************************************/

void Room::setMooseAfraidOf(std::string mooseType)
{
	if (mooseType == "smellyMoose")
	{
		mooseAfraidOf = "air freshener";
		if (keyToUnlockRoom != "none")
		{
			lockedDoor = true;
		}
	}

	else if (mooseType == "sleepyMoose")
	{
		mooseAfraidOf = "alarm clock";
		if (keyToUnlockRoom != "none")
		{
			lockedDoor = true;
		}

		if (outside == false)
		{
			lightsOn = false;
		}
	}

	else if (mooseType == "vegetarianMoose")
	{
		mooseAfraidOf = "meat";
	}

	else if (mooseType == "poshMoose")
	{
		mooseAfraidOf = "garden gnome";
	}

	else if (mooseType == "copycatMoose")
	{
		mooseAfraidOf = "mirror";
		if (outside == false)
		{
			lightsOn = false;
		}
	}
}

/*************************************
std::string Room::getMooseAfraidOf()

Get the member mooseAfraidOf which is a string
of what the moose is afraid of and
"none" means there is no moose in the room
*************************************/

std::string Room::getMooseAfraidOf()
{
	return mooseAfraidOf;
}

	/*************************************

		Locked Door in room functions

	*************************************/

/*************************************
void Room::setLockedDoor(bool)

Set the member lockedDoor to true or false
if is locked or not
*************************************/

void Room::setLockedDoor(bool TFLD)
{
	lockedDoor = TFLD;
}

/*************************************
bool Room::getLockedDoor()

Get the member lockedDoor with the value true or false
if the room is locked or not
*************************************/

bool Room::getLockedDoor()
{
	return lockedDoor;
}

	/*************************************

	Lights on in room functions
	
	*************************************/

/*************************************
void Room::setLightsOn(bool);

Set the member lockedDoor to true or false
if is locked or not
*************************************/

void Room::setLightsOn(bool TFLO)
{
	lightsOn = TFLO;
}

/*************************************
bool Room::getLightsOn();

Get the member lockedDoor with the value true or false
if the room is locked or not
*************************************/

bool Room::getLightsOn()
{
	return lightsOn;
}

	/*************************************

	Key to Room functions

	*************************************/

/*************************************
std::string Room::getKeyToUnlockRoom()

Get the member keyToUnlockRoom which is a string
of the key needed to unlock the room
*************************************/

std::string Room::getKeyToUnlockRoom()
{
	std::string k = keyToUnlockRoom;
	return k;
}

	/*************************************

	Pointers to Room functions

	*************************************/


/*************************************
void Room::setRLUDPointers(Room* west, Room* east, Room* north, Room* south)

set the pointers to the nearby rooms
*************************************/

void Room::setRLUDPointers(Room* west, Room* east, Room* north, Room* south)
{
	right = west;
	left = east;
	up = north;
	down = south;
}

/*************************************
Room* Room::getRight()

Get the member right which is the room
to the right
*************************************/

Room* Room::getRight()
{
	return right;
}

/*************************************
Room* Room::getLeft()

Get the member left which is the room
to the left
*************************************/

Room* Room::getLeft()
{
	return left;
}

/*************************************
Room* Room::getUp()

Get the member up which is the room
to the up
*************************************/

Room* Room::getUp()
{
	return up;
}

/*************************************
Room* Room::getDown()

Get the member down which is the room
to the down
*************************************/

Room* Room::getDown()
{
	return down;
}



	/*************************************

	Name of Room function

	*************************************/

/*************************************
std::string Room::getNameOfRoom()

Get the member nameOfRoom which is the
name of the room
*************************************/

std::string Room::getNameOfRoom()
{
	return nameOfRoom;
}



/*************************************

Derived Class Contructors

*************************************/




/*************************************
Derived class FrontLawn
*************************************/

FrontLawn::FrontLawn()
{
	//Item members
	itemInRoom = false;
	typeOfItemInRoom = "none";

	//Moose members
	mooseInRoom = false;
	typeOfMooseInRoom = "none";
	mooseAfraidOf = "none";

	//Room members
	lockedDoor = false;
	lightsOn = true;
	nameOfRoom = "Front Lawn";
	outside = true;

	//Key members
	keyToUnlockRoom = "none";
}

/*************************************
Derived class Backyard
*************************************/

Backyard::Backyard()
{
	//Item members
	itemInRoom = false;
	typeOfItemInRoom = "none";

	//Moose members
	mooseInRoom = false;
	typeOfMooseInRoom = "none";
	mooseAfraidOf = "none";

	//Room members
	lockedDoor = false;
	lightsOn = true;
	nameOfRoom = "Backyard";
	outside = true;

	//Key members
	keyToUnlockRoom = "none";
}

/*************************************
Derived class Garage
*************************************/

Garage::Garage()
{
	//Item members
	itemInRoom = false;
	typeOfItemInRoom = "none";

	//Moose members
	mooseInRoom = false;
	typeOfMooseInRoom = "none";
	mooseAfraidOf = "none";

	//Room members
	lockedDoor = false;
	lightsOn = true;
	nameOfRoom = "Garage";
	outside = false;

	//Key members
	keyToUnlockRoom = "Garage Key";
}

/*************************************
Derived class LivingRoom
*************************************/

LivingRoom::LivingRoom()
{
	//Item members
	itemInRoom = false;
	typeOfItemInRoom = "none";

	//Moose members
	mooseInRoom = false;
	typeOfMooseInRoom = "none";
	mooseAfraidOf = "none";

	//Room members
	lockedDoor = false;
	lightsOn = true;
	nameOfRoom = "Living Room";
	outside = false;

	//Key members
	keyToUnlockRoom = "Living Room Key";
}

/*************************************
Derived class Kitchen
*************************************/

Kitchen::Kitchen()
{
	//Item members
	itemInRoom = false;
	typeOfItemInRoom = "none";

	//Moose members
	mooseInRoom = false;
	typeOfMooseInRoom = "none";
	mooseAfraidOf = "none";

	//Room members
	lockedDoor = false;
	lightsOn = true;
	nameOfRoom = "Kitchen";
	outside = false;

	//Key members
	keyToUnlockRoom = "none";
}

/*************************************
Derived class Bathroom
*************************************/

Bathroom::Bathroom()
{
	//Item members
	itemInRoom = false;
	typeOfItemInRoom = "none";

	//Moose members
	mooseInRoom = false;
	typeOfMooseInRoom = "none";
	mooseAfraidOf = "none";

	//Room members
	lockedDoor = false;
	lightsOn = true;
	nameOfRoom = "Bathroom";
	outside = false;

	//Key members
	keyToUnlockRoom = "Bathroom Key";
}

/*************************************
Derived class KidsBedroom
*************************************/

KidsBedroom::KidsBedroom()
{
	//Item members
	itemInRoom = false;
	typeOfItemInRoom = "none";

	//Moose members
	mooseInRoom = false;
	typeOfMooseInRoom = "none";
	mooseAfraidOf = "none";

	//Room members
	lockedDoor = false;
	lightsOn = true;
	nameOfRoom = "Kid's Bedroom";
	outside = false;

	//Key members
	keyToUnlockRoom = "Kid's Bedroom Key";
}

/*************************************
Derived class Hallway
*************************************/

Hallway::Hallway()
{
	//Item members
	itemInRoom = false;
	typeOfItemInRoom = "none";

	//Moose members
	mooseInRoom = false;
	typeOfMooseInRoom = "none";
	mooseAfraidOf = "none";

	//Room members
	lockedDoor = false;
	lightsOn = true;
	nameOfRoom = "Hallway";
	outside = false;

	//Key members
	keyToUnlockRoom = "none";
}

/*************************************
Derived class MasterBedroom
*************************************/

MasterBedroom::MasterBedroom()
{
	//Item members
	itemInRoom = false;
	typeOfItemInRoom = "none";

	//Moose members
	mooseInRoom = false;
	typeOfMooseInRoom = "none";
	mooseAfraidOf = "none";

	//Room members
	lockedDoor = false;
	lightsOn = true;
	nameOfRoom = "Master Bedroom";
	outside = false;

	//Key members
	keyToUnlockRoom = "Master Bedroom Key";
}

/*************************************
Derived class MasterBathroom
*************************************/

MasterBathroom::MasterBathroom()
{
	//Item members
	itemInRoom = false;
	typeOfItemInRoom = "none";

	//Moose members
	mooseInRoom = false;
	typeOfMooseInRoom = "none";
	mooseAfraidOf = "none";

	//Room members
	lockedDoor = false;
	lightsOn = true;
	nameOfRoom = "Master Bathroom";
	outside = false;

	//Key members
	keyToUnlockRoom = "Master Bathroom Key";
}

/*************************************
Derived class Roof
*************************************/

Roof::Roof()
{
	//Item members
	itemInRoom = false;
	typeOfItemInRoom = "none";

	//Moose members
	mooseInRoom = false;
	typeOfMooseInRoom = "none";
	mooseAfraidOf = "none";

	//Room members
	lockedDoor = false;
	lightsOn = true;
	nameOfRoom = "Roof";
	outside = true;

	//Key members
	keyToUnlockRoom = "none";
}
