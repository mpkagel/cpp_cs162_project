/************************************************************
** Program Name: Menu.hpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the prototype for the Menu class.
************************************************************/

#ifndef MENU_HPP
#define MENU_HPP

#include <cstring>
#include <iomanip>
#include <iostream>
#include "Creature.hpp"
#include "ValidInput.hpp"

/************************************************************
** Description: Class Menu
**   This class contains the functions necessary to get an integer
**   to run through a switch and also has some supporting functions
**   that make the switch in main() look cleaner.
************************************************************/
class Menu
{
private:
	int selection;

public:
	// -- Constructor. --
	Menu();

	// -- Getters and setters. --
	int getSelection() { return selection; };
	void setSelection(int num_menu_options);

	// -- Unique class functions. --
	void intro();
	void display();
	void fightersFull();
	void fightersEmpty();
	void redFull();
	void redEmpty();
	void blueFull();
	void blueEmpty();
	Aspect strToEnum(char *, const char **, int);
	std::string enumToStr(Aspect);
};
#endif





