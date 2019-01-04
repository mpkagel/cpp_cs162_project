/************************************************************
** Program Name: project4main.cpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: Code for Project 4.
**   This program has the main function for Project 4. It calls
**   the getSelection() menu function from the Menu class and
**   uses a switch to go through the menu options.
************************************************************/

#include <ctime>
#include "Games.hpp"

int main()
{	
	// -- Constants. --
	const int NUM_OF_CASES_TWO = 2;
	const char valid_two[NUM_OF_CASES_TWO] = { 'y', 'n' };
		
	// -- Menu and input validation variables. --
	Menu menu;
	int num_menu_options = 7;
	ValidInput val_input;
	std::string prompt;

	// -- Variables related to random number generation. --
	unsigned int seed = time(0);
	std::mt19937 mt(seed); // From Die.hpp #include <random>
							  // Seeding the Mersenne Twister.

	// -- Initial variables. --
	bool isFighters = false, isRed = false, isBlue = false;
	int team_size = 0, min_team_size = 1, max_team_size = 20;
	char choice;
	Team team_color;
	Games arena;

	// -- Display the program introduction. --
	menu.intro();

	// -- Get menu selection and run through switch. --
	do
	{
		menu.setSelection(num_menu_options);
		std::cout << std::endl;

		switch (menu.getSelection())
		{
		case 1: // Set the number of fighters.
			if (isFighters) // Check if number of fighters has already been set.
			{
				menu.fightersFull();
				break;
			}
			else
			{
				prompt = "Please enter an integer number for the number of fighters on each team between ";
				val_input.getIntLoop(prompt, &team_size, min_team_size, max_team_size);
				isFighters = true;
				std::cout << std::endl;
			}
			break;
		case 2: // Set the Red Team.
			if (!isFighters) // Check if number of fighters has not been set.
			{
				menu.fightersEmpty();
				break;
			}
			else if (isRed) // Check if the Red Team lineup has already been set.
			{
				menu.redFull();
				break;
			}
			else
			{
			        std::cout << "This team needs " << team_size << " fighters "
					  << "to complete its lineup." << std::endl << std::endl;
			        team_color = RED;
				isRed = arena.fillLineup(team_color, team_size);
			}
			break;
		case 3: // Set the Blue Team.
			if (!isFighters) // Check if number of fighters has not been set.
			{
				menu.fightersEmpty();
				break;
			}
			else if (isBlue) // Check if the Blue Team lineup has already been set.
			{
				menu.blueFull();
				break;
			}
			else
			{
			        std::cout << "This team needs " << team_size << " fighters "
					  << "to complete its lineup." << std::endl << std::endl;
				team_color = BLUE;
				isBlue = arena.fillLineup(team_color, team_size);
			}
			break;
		case 4: // Run the tournament.
			if (!isFighters)
			{
				menu.fightersEmpty();
				break;
			}
			else if (!isRed)
			{
				menu.redEmpty();
				break;
			}
			else if (!isBlue)
			{
				menu.blueEmpty();
				break;
			}
			else
			{
				arena.tourney(mt);
			}
			break;
		case 5: // Clear all data entered by user.
			std::cout << "Are you sure that you want to clear all data?" << std::endl;
			prompt =  "Enter \"y\" for yes, and \"n\" for no: ";
			val_input.getCharValidLoop(prompt, &choice, valid_two, NUM_OF_CASES_TWO);
			if (choice == 'y')
			{
				team_size = 0;
				arena.evacuate();
				std::cout << std::endl << "All data has been successfully cleared." 
					  << std::endl;
				isFighters = isRed = isBlue = false;
			}
			std::cout << std::endl;
			break;
		case 6: // Clear the screen.
			std::system("clear");
			break;
		case 7: // Exit program.
			break;
		}
	} while (menu.getSelection() != num_menu_options);

	return 0;
}
