/************************************************************
** Program Name: Games.cpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the code for the Games class.
**   The Games class contains all variables and functions necessary
**   to run a fantasy combat tournament.
************************************************************/

#include "Games.hpp"

/************************************************************
** Description: Function ~Games()
**   This function is the Games class default destructor.
************************************************************/
Games::~Games()
{
	// -- Use evacuate to clear containers of allocated memory. --
	evacuate();
}

/************************************************************
** Description: Function evacuate()
**   This function empties all containers in Games.
************************************************************/
void Games::evacuate()
{
	// -- Delete each element of Red. --
	while (!Red.isEmpty())
	{
		Red.removeFront();
	}

	// -- Delete each element of Blue. --
	while (!Blue.isEmpty())
	{
		Blue.removeFront();
	}

	// -- Delete each element of Saniarium. --
	while (!Saniarium.isEmpty())
	{
		Saniarium.removeTop();
	}
}

/************************************************************
** Description: Function fillLineup()
**   This function fills one team's lineup.
************************************************************/
bool Games::fillLineup(Team color, int size)
{
	// -- Constants. --
	const int SIZE_OF_INVALID = 1;
	const char *invalid[SIZE_OF_INVALID] = { "CANCEL" };

	const int SIZE_OF_INVALID_TWO = 2;
	const char *invalid_two[SIZE_OF_INVALID_TWO] = { "D", "CANCEL" };
	
	const int NUM_OF_CASES = 10;
	const char *valid[NUM_OF_CASES] = { "V", "Vampire", "B", "Barbarian",
		"BL", "Blue Men", "M", "Medusa", "H", "Harry Potter" };

	// -- Menu and input validation variables. --
	std::string prompt;
	ValidInput val_input;
	Menu submenu;
	
	// -- Initial variables. --
	char creature_type[4096];
	char fighter_name[4096];
	char temp[4096];
	Aspect form;
	bool match = false;
	bool complete = false;

	// -- Check if the team is Red or Blue. --
	if (color == RED)
	{
		std::cout << "At any time during entry of information for the Red Team," << std::endl;
		std::cout << "enter \"CANCEL\" to discontinue filling up the Red Team's" << std::endl;
		std::cout << "lineup and return to menu." << std::endl << std::endl;
		// -- Add as many Creature's as the user has specified with size. --
		for (int i = 1; i <= size; i++)
		{
			// -- Enter fighter's creature type. --
			std::cout << "Please enter information for Red Team fighter #" << i
				<< "." << std::endl;
			std::cout << "Options for fighter #" << i << "'s creature type are as follows:"
				<< std::endl << std::endl;
			submenu.display();
			prompt = "Please enter creature type here: ";
			val_input.getStrAlternateLoop(prompt, creature_type,
				invalid, SIZE_OF_INVALID, valid, NUM_OF_CASES);
			if (val_input.getStatus() == 1)
			{
				std::cout << "The Red Team's lineup is incomplete. Returning to main menu."
					  << std::endl << std::endl;
				while (!Red.isEmpty()) // Delete incomplete Red Team.
				{
					Red.removeFront();
				}
				return complete;
			}
			form = submenu.strToEnum(creature_type, valid, NUM_OF_CASES);

			// -- Enter fighter's name. --
			do
			{
  			        prompt = "Please give the fighter a name or enter \"D\" for the default name: \n";				
				val_input.getStrInvalidLoop(prompt, fighter_name, invalid_two, SIZE_OF_INVALID_TWO);
				if (val_input.getStatus() == 1)
				{
					if (!strcmp(fighter_name, invalid_two[1]))
					{
						std::cout << "The Red Team's lineup is incomplete. Returning to main menu."
							  << std::endl << std::endl;
						while (!Red.isEmpty()) // Delete incomplete Red Team.
						{
							Red.removeFront();
						}
						return complete;
					}
					else if (!strcmp(fighter_name, invalid_two[0]))
					{
						strcpy(fighter_name, (submenu.enumToStr(form)).c_str());
						sprintf(temp, " #%d", i);
						strcat(fighter_name, temp);
						std::cout << "Fighter has the default name of " << fighter_name
							  << "." << std::endl;
					}
				}
				match = Red.checkName(fighter_name);
				if (match)
				{
					std::cout << "There is already a fighter on this team with that name." << std::endl;
					std::cout << "Please select a different name for the fighter about to be added." << std::endl;
				}
			} while (match);
			
			// -- Add fighter to team's queue. --
			Red.addBack(form, fighter_name);
			std::cout << std::endl;
		}
		// -- Display the queue. --
		this->printTeamQueue(color);
		complete = true;
	}
	else
	{
		std::cout << "At any time during entry of information for the Blue Team," << std::endl;
		std::cout << "enter \"CANCEL\" to discontinue filling up the Blue Team's" << std::endl;
		std::cout << "lineup and return to menu." << std::endl << std::endl;
		// -- Add as many Creature's as the user has specified with size. --
		for (int i = 1; i <= size; i++)
		{
			// -- Enter fighter's creature type. --
			std::cout << "Please enter information for Blue Team fighter #" << i
				<< "." << std::endl;
			std::cout << "Options for fighter #" << i << "'s creature type are as follows:"
				<< std::endl << std::endl;
			submenu.display();
			prompt = "Please enter creature type here: ";
			val_input.getStrAlternateLoop(prompt, creature_type,
				invalid, SIZE_OF_INVALID, valid, NUM_OF_CASES);
			if (val_input.getStatus() == 1)
			{
				std::cout << "The Blue Team's lineup is incomplete. Returning to main menu."
					  << std::endl << std::endl;
				while (!Blue.isEmpty()) // Delete incomplete Blue Team.
				{
					Blue.removeFront();
				}
				return complete;
			}
			form = submenu.strToEnum(creature_type, valid, NUM_OF_CASES);

			// -- Enter fighter's name. --
			do
			{
  			        prompt = "Please give the fighter a name or enter \"D\" for the default name: \n";				
				val_input.getStrInvalidLoop(prompt, fighter_name, invalid_two, SIZE_OF_INVALID_TWO);
				if (val_input.getStatus() == 1)
				{
					{
						if (!strcmp(fighter_name, invalid_two[1]))
						{
							std::cout << "The Blue Team's lineup is incomplete. Returning to main menu."
								  << std::endl << std::endl;
							while (!Blue.isEmpty()) // Delete incomplete Blue Team.
							{
								Blue.removeFront();
							}
							return complete;
						}
						else if (!strcmp(fighter_name, invalid_two[0]))
						{
							strcpy(fighter_name, (submenu.enumToStr(form)).c_str());
							sprintf(temp, " #%d", i);
							strcat(fighter_name, temp);
							std::cout << "Fighter has the default name of " << fighter_name
								  << "." << std::endl;
						}
					}
				}
				match = Blue.checkName(fighter_name);
				if (match)
				{
					std::cout << "There is already a fighter on this team with that name." << std::endl;
					std::cout << "Please select a different name for the fighter about to be added." << std::endl;
				}
			} while (match);
			
			// -- Add fighter to team's queue. --
			Blue.addBack(form, fighter_name);
			std::cout << std::endl;
		}
		// -- Display the queue. --
		this->printTeamQueue(color);
		complete = true;
	}
	return complete;
}

/************************************************************
** Description: Function tourney()
**   This function runs the tournament.
************************************************************/
void Games::tourney(std::mt19937 &mers_twist)
{
	// -- Initial variables. --
  	Queue RedCopy;
  	Queue BlueCopy;
	int bout = 0; // Variable to keep track of number of calls
				  // to fight().
	int red_wins = 0;
	int blue_wins = 0;
	Team winner;

	// -- Copy each team's queue. --
	RedCopy = Red;
	BlueCopy = Blue;

	// -- Keep running fight() and tallying wins until a team
	//    runs out of fighters because they're all dead. --
	while (!(Red.isEmpty()) && !(Blue.isEmpty()))
	{
	        // -- Print each team's lineup. --
	        printTeamQueue(RED);
		printTeamQueue(BLUE);
		
		// -- Increment bout and call fight(). --
	        bout++;
		winner = fight(mers_twist, bout);

		// -- Give the winner a point. -- 
		if (winner == RED)
		{
			red_wins++;
		}
		else
		{
			blue_wins++;
		}
		std::cout << std::endl << std::endl;
	}

	// -- Print final points. --
	std::cout << "The Red Team has " << red_wins
		<< " points." << std::endl;
	std::cout << "The Blue Team has " << blue_wins
		<< " points." << std::endl;

	// -- Declare a winner. --
	if (red_wins > blue_wins)
	{
		std::cout << "The Red Team has won the tournament!" << std::endl;
	}
	else
	{
		std::cout << "The Blue Team has won the tournament!" << std::endl;
	}

	// -- Print the loser stack, clear Red, Blue, and Saniarium using evacuate(),
	//    and then use the RedCopy and BlueCopy to return Games to the state it was
	//    in prior to running tourney(). --
	std::cout << "The loser stack has the following fighters:" << std::endl; 
	Saniarium.printStack(bout);
	evacuate();
	Red = RedCopy;
	Blue = BlueCopy;
	std::cout << "The Red and Blue Teams have been restored to their" << std::endl;
	std::cout << "original lineups so that the tournament can be re-played" << std::endl;
	std::cout << "with the same Teams." << std::endl << std::endl;
}

/************************************************************
** Description: Function fight()
**   This function runs the fantasy combat game. It flips a coin
**   to see which player will go first. Then it continues to call
**   attack() and defend() until a Creature dies and loses the fight.
**   Round information is displayed at each round and a winner is
**   declared at the end.
************************************************************/
Team Games::fight(std::mt19937 &mers_twist, int bout)
{
	// -- Constants. --
	const int NUM_OF_SIDES = 2;

	// -- Initial variables. --
	Team attacker = RED;
	Team defender = BLUE;
	int attack_roll = 0;
	bool death = false;
	int round = 1;
	std::string dashes;
	dashes.append(20, '-');
	std::uniform_int_distribution<int> dist(1, NUM_OF_SIDES);

	// -- Flip a coin to see who attacks first. --
	if (!(dist(mers_twist) - 1))
	{
		attacker = BLUE;
		defender = RED;
	}

	// -- Have creature's fight. --
	do
	{
		// -- Initial status. --
	  std::cout << "Bout #" << bout << "," << std::setw(2) << " ";
		std::cout << "Round #" << round << std::endl;
		std::cout << dashes << std::endl << std::endl;
		if (attacker == RED)
		{
			std::cout << "The Red Team's ";
			Red[0]->print();
			std::cout << " attacks " << "the Blue Team's ";
			Blue[0]->print();
			std::cout << "." << std::endl;

			// -- Attack and defend rolls. --
			attack_roll = Red[0]->attack(mers_twist, attacker);
			death = Blue[0]->defend(mers_twist, defender, attack_roll);
		}
		else
		{
			std::cout << "The Blue Team's ";
			Blue[0]->print();
			std::cout << " attacks " << "the Red Team's ";
			Red[0]->print();
			std::cout << "." << std::endl;

			// -- Attack and defend rolls. --
			attack_roll = Blue[0]->attack(mers_twist, attacker);
			death = Red[0]->defend(mers_twist, defender, attack_roll);
		}
		
		// -- End of round status. --
		std::cout << std::endl;
		std::cout << "The Red Team's ";
		Red[0]->print();
		std::cout << " has " << Red[0]->getArmor() << " armor and "
			<< Red[0]->getStrength() << " strength." << std::endl;
		std::cout << "The Blue Team's ";
		Blue[0]->print();
		std::cout << " has " << Blue[0]->getArmor() << " armor and "
			<< Blue[0]->getStrength() << " strength." << std::endl << std::endl;

		// -- Check for death. --
		if (death)
		{
			return finalRound(mers_twist, attacker);
		}
		else
		{
			// -- Get ready for the next round. --
			std::swap(attacker, defender);
			round++;
			std::cout << std::endl;
		}
	} while (!death);
}

/************************************************************
** Description: Function finalRound()
**   This function prints final fight() results and does cleanup
**   for fight() once a Creature has died.
************************************************************/
Team Games::finalRound(std::mt19937 &mers_twist, Team attacker)
{
	// -- Initial variables. --
	bool death = true;
	Aspect form;
	int str;
	std::string title;

	// -- Check for who is attacking and defending. --
	if (attacker == RED)
	{
		// -- Print winner of the bout. --
		std::cout << "The Blue Team's ";
		Blue[0]->print();
		std::cout << " is dead." << std::endl;
		std::cout << "The Red Team's ";
		Red[0]->print();
		std::cout << " has won the bout!" << std::endl << std::endl;

		// -- Loser goes to the Saniarium. --
		form = Blue[0]->getType();
		title = Blue[0]->getName();
		Saniarium.addTop(form, title);
		Blue.removeFront();

		// -- Winner regens and goes to the back of its team's lineup. --
		std::cout << "The Red Team's ";
		Red[0]->print();
		std::cout << " recovers " << Red[0]->regen(mers_twist);
		std::cout << " strength," << std::endl;
		std::cout << "and is put back in the Red Team's lineup." 
			  << std::endl; 
		form = Red[0]->getType();
		title = Red[0]->getName();
		str = Red[0]->getStrength();
		Red.addBack(form, title);
		(Red.getBackCreature())->setStrength(str);
		Red.removeFront();

		// -- Return the winner. --
		return RED;
	}
	else
	{
		// -- Print winner of the bout. --
		std::cout << "The Red Team's ";
		Red[0]->print();
		std::cout << " is dead." << std::endl;
		std::cout << "The Blue Team's ";
		Blue[0]->print();
		std::cout << " has won the bout!" << std::endl << std::endl;

		// -- Loser goes to the Saniarium. --
		form = Red[0]->getType();
		title = Red[0]->getName();
		Saniarium.addTop(form, title);
		Red.removeFront();

		// -- Winner regens and goes to the back of its team's lineup. --
		std::cout << "The Blue Team's ";
		Blue[0]->print();
		std::cout << " recovers " << Blue[0]->regen(mers_twist);
		std::cout << " strength," << std::endl;
		std::cout << "and is put back in the Blue Team's lineup." 
			  << std::endl;
		form = Blue[0]->getType();
		title = Blue[0]->getName();
		str = Blue[0]->getStrength();
		Blue.addBack(form, title);
		(Blue.getBackCreature())->setStrength(str);
		Blue.removeFront();

		// -- Return the winner. --
		return BLUE;
	}
}

/************************************************************
** Description: Function printTeamQueue()
**   This function prints the information from one Team.
************************************************************/
void Games::printTeamQueue(Team color)
{
	if (color == RED)
	{
		std::cout << "The Red Team has the following lineup:" << std::endl;
		Red.printQueue();
	}
	else
	{
		std::cout << "The Blue Team has the following lineup:" << std::endl;
		Blue.printQueue();
	}
}
