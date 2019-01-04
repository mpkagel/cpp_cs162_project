/************************************************************
** Program Name: Menu.cpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the code for the Menu class.
************************************************************/

#include "Menu.hpp"

/************************************************************
** Description: Function Menu()
**   The following function is the Menu default constructor.
************************************************************/
Menu::Menu()
{
	// -- Initial variables. --
	selection = 0;
}

/************************************************************
** Description: Function setSelection()
**   The following function takes input from the user and returns that
**   to main() in order to select from various options in a switch.
************************************************************/
void Menu::setSelection(int num_menu_options)
{
	// -- Initial variables. --
	ValidInput val_input;

	// -- Display menu options to user. --
	std::cout << "Enter an integer number \"1\" through \"" << num_menu_options << "\":" << std::endl << std::endl;
	std::cout << std::setw(10) << "\"1\":" << " Select a number of fighters for both teams." << std::endl;
	std::cout << std::setw(10) << "\"2\":" << " Enter the lineup for the Red Team." << std::endl;
	std::cout << std::setw(10) << "\"3\":" << " Enter the lineup for the Blue Team." << std::endl;
	std::cout << std::setw(10) << "\"4\":" << " PvP creature tournament!" << std::endl;
	std::cout << std::setw(10) << "\"5\":" << " Clear data entered for number of fighters and both teams." << std::endl;
	std::cout << std::setw(10) << "\"6\":" << " Clear the screen." << std::endl;
	std::cout << std::setw(10) << "\"7\":" << " Quit the program." << std::endl;
	std::cout << std::endl;

	// -- Get menu selection input from user. --
	do
	{
		std::cout << "Please enter your selection here: ";
		val_input.getInt(&selection, 1, num_menu_options);
	} while (val_input.getStatus() != 0);
}

/************************************************************
** Description: Function intro()
**   The following function displays an intro to the program.
************************************************************/
void Menu::intro()
{
	std::cout << "This program is a fantasy combat game in which two players' have" << std::endl;
	std::cout << "a team of creatures that fight each other in a tournament." << std::endl;
	std::cout << "The creature's to choose from are as follows:" << std::endl << std::endl;
	std::cout << "Vampire" << std::endl;
	std::cout << "Barbarian" << std::endl;
	std::cout << "Blue Men" << std::endl;
	std::cout << "Medusa" << std::endl;
	std::cout << "Harry Potter" << std::endl << std::endl;
	std::cout << "The menu options in this program are" << std::endl;
        std::cout << "intended to be chosen in a specific order." << std::endl << std::endl;
	std::cout << "First, choose a number of fighters that both teams will have." << std::endl;
	std::cout << "Second, enter fighter information for the Red Team" << std::endl;
	std::cout << std::setw(5) << " " <<  "(both creature type and name for each fighter)." << std::endl;
	std::cout << "Third, enter fighter information for the Blue Team" << std::endl;
	std::cout << std::setw(5) << " " <<  "(both creature type and name for each fighter)." << std::endl;
	std::cout << "Fourth, start the tournament." << std::endl << std::endl;
	std::cout << "If these are selected out of order, an error message will help guide you" << std::endl;
	std::cout << "toward the correct menu selection order that the program is looking for."
		  << std::endl << std::endl;
}

/************************************************************
** Description: Function display()
**   The following function displays which strings are valid
**   input so a user knows what to input.
************************************************************/
void Menu::display()
{
	std::cout << std::setw(15) << "Vampire: " << "Enter \"V\" or \"Vampire\"" << std::endl;
	std::cout << std::setw(15) << "Barbarian: "
		<< "Enter \"B\" or \"Barbarian\"" << std::endl;
	std::cout << std::setw(15) << "Blue Men: "
		<< "Enter \"BL\" or \"Blue Men\"" << std::endl;
	std::cout << std::setw(15) << "Medusa: "
		<< "Enter \"M\" or \"Medusa\"" << std::endl;
	std::cout << std::setw(15) << "Harry Potter: "
		<< "Enter \"H\" or \"Harry Potter\"" << std::endl << std::endl;
}

/************************************************************
** Description: Function fightersFull()
**   The following function displays the message when the user
**   tries to set the number of fighters twice without clearing
**   the program's information.
************************************************************/
void Menu::fightersFull()
{
	std::cout << "The number of fighters has already been set." << std::endl;
	std::cout << "If you would like to clear the number of fighters," << std::endl;
	std::cout << "please use the menu to clear all data and start" << std::endl;
	std::cout << "over at option 1)." << std::endl << std::endl;
}

/************************************************************
** Description: Function fightersEmpty()
**   The following function displays the message when the user
**   tries to set the Red Team, Blue Team, or start the tournament
**   when the number of fighters hasn't been set yet.
************************************************************/
void Menu::fightersEmpty()
{
	std::cout << "The number of fighters for each team has not been set." << std::endl;
	std::cout << "Please use the menu to set the number of fighters." << std::endl << std::endl;
}

/************************************************************
** Description: Function redFull()
**   The following function displays the message when the user
**   tries to enter the lineup for the Red Team when it has
**   already been done.
************************************************************/
void Menu::redFull()
{
	std::cout << "The Red Team's lineup has already been set." << std::endl;
	std::cout << "If you would like to clear the Red Team lineup," << std::endl;
	std::cout << "please use the menu to clear all data and start" << std::endl; 
	std::cout << "over at option 1)." << std::endl << std::endl;
}

/************************************************************
** Description: Function redEmpty()
**   The following function displays the message when the user
**   tries to start the tournament, but the Red Team has not
**   been set yet.
************************************************************/
void Menu::redEmpty()
{
	std::cout << "The Red Team's lineup has not been set." << std::endl;
	std::cout << "Please use the menu to set the Red Team's lineup." << std::endl << std::endl;
}

/************************************************************
** Description: Function blueFull()
**   The following function displays the message when the user
**   tries to enter the lineup for the Blue Team when it has
**   already been done.
************************************************************/
void Menu::blueFull()
{
	std::cout << "The Blue Team's lineup has already been set." << std::endl;
	std::cout << "If you would like to clear the Blue Team lineup," << std::endl;
	std::cout << "please use the menu to clear all data and start" << std::endl;
	std::cout << "over at option 1)." << std::endl << std::endl;
}

/************************************************************
** Description: Function blueEmpty()
**   The following function displays the message when the user
**   tries to start the tournament, but the Blue Team has not
**   been set yet.
************************************************************/
void Menu::blueEmpty()
{
	std::cout << "The Blue Team's lineup has not been set." << std::endl;
	std::cout << "Please use the menu to set the Blue Team's lineup." << std::endl << std::endl;
}

/************************************************************
** Description: Function strToEnum()
**   The following function takes a C string input and
**   convert it into an enumerated number based upon a list of 
**   matching valid C strings that it is compared to.
************************************************************/
Aspect Menu::strToEnum(char *input, const char** valid_str, int size)
{
	// -- Initial variables. --
	Aspect output;

	// -- Loop through test cases to match the string to an enumerated number. --
	for (int i = 0; i < size; i++)
	{
		if (strcmp(input, *(valid_str + i)) == 0)
		{
			output = static_cast<Aspect>(i / 2); // Type cast integer i to corresponding enumerated number.
		}
	}

	// -- Return output. --
	return output;
}

/************************************************************
** Description: Function strToEnum()
**   The following function takes an enumerated number and
**   turns it back into a string.
************************************************************/
std::string Menu::enumToStr(Aspect type)
{
	// -- Initial variables. --
	std::string output;

	switch (type)
	{
	case VAMPIRE:
		output = "Vampire";
		break;
	case BARBARIAN:
		output = "Barbarian";
		break;
	case BLUEMEN:
		output = "Blue Men";
		break;
	case MEDUSA:
		output = "Medusa";
		break;
	case HARRYPOTTER:
		output = "Harry Potter";
		break;
	}

	// -- Return output. --
	return output;
}
