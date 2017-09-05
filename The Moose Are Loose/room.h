/*************************************
Nathan Greenlaw
ONID: greenlan
11/30/16
Final Project: The Moose are Loose
*************************************/

/*************************************
Header File for Abstract Room Class
*************************************/

#ifndef ROOM_H
#define ROOM_H
#include "stdafx.h"

#include <string>

/*************************************
Abstract Room Base Class
*************************************/

class Room
{
public:
	//pure virtual destructor
	virtual ~Room() = 0;

	//Item in room functions
	virtual void setItemInRoom(bool);
	virtual bool getItemInRoom();
	virtual void setTypeOfItemInRoom(std::string);
	virtual std::string getTypeOfItemInRoom();

	//Moose in room functions (Change to moose objects instead of strings)
	virtual void setMooseInRoom(bool);
	virtual bool getMooseInRoom();
	virtual void setTypeOfMooseInRoom(std::string);
	virtual std::string getTypeOfMooseInRoom();
	virtual void setMooseAfraidOf(std::string);
	virtual std::string getMooseAfraidOf();

	//Locked Door functions
	virtual void setLockedDoor(bool);
	virtual bool getLockedDoor();

	//Lights functions
	virtual void setLightsOn(bool);
	virtual bool getLightsOn();

	//Keys in Rooms Function
	virtual std::string getKeyToUnlockRoom();

	//Nearby Rooms function
	virtual void setRLUDPointers(Room*, Room*, Room*, Room*);
	virtual Room* getRight();
	virtual Room* getLeft();
	virtual Room* getUp();
	virtual Room* getDown();

	//Room type functions
	virtual std::string getNameOfRoom();
	

protected:
	//Item members
	bool itemInRoom;
	std::string typeOfItemInRoom;

	//Moose members
	bool mooseInRoom;
	std::string typeOfMooseInRoom;
	std::string mooseAfraidOf;

	//Room members
	bool lockedDoor;
	bool lightsOn;
	std::string nameOfRoom;
	//room outside or not
	bool outside;

	//Key members
	std::string keyToUnlockRoom;

	//Pointers to other rooms
	Room* right;
	Room* left;
	Room* up;
	Room* down;
};

/*************************************
Derived class FrontLawn
*************************************/

class FrontLawn : public Room
{
public:
	//Front Lawn constructor
	FrontLawn();
};

/*************************************
Derived class Backyard
*************************************/

class Backyard : public Room
{
public:
	//Backyard constructor
	Backyard();
};

/*************************************
Derived class Garage
*************************************/

class Garage : public Room
{
public:
	//Garage constructor
	Garage();
};

/*************************************
Derived class LivingRoom
*************************************/

class LivingRoom : public Room
{
public:
	//LivingRoom constructor
	LivingRoom();
};

/*************************************
Derived class Kitchen
*************************************/

class Kitchen : public Room
{
public:
	//Kitchen constructor
	Kitchen();
};

/*************************************
Derived class Bathroom
*************************************/

class Bathroom : public Room
{
public:
	//Bathroom constructor
	Bathroom();
};

/*************************************
Derived class KidsBedroom
*************************************/

class KidsBedroom : public Room
{
public:
	//KidsBedroom constructor
	KidsBedroom();
};

/*************************************
Derived class Hallway
*************************************/

class Hallway : public Room
{
public:
	//Hallway constructor
	Hallway();
};

/*************************************
Derived class MasterBedroom
*************************************/

class MasterBedroom : public Room
{
public:
	//MasterBedroom constructor
	MasterBedroom();
};

/*************************************
Derived class MasterBathroom
*************************************/

class MasterBathroom : public Room
{
public:
	//MasterBathroom constructor
	MasterBathroom();
};

/*************************************
Derived class Roof
*************************************/

class Roof : public Room
{
public:
	//Roof constructor
	Roof();
};


#endif // !ROOM_H
