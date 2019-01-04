/************************************************************
** Program Name: Vampire.cpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the code for the Vampire class.
**   The Vampire class is derived from Creature.
************************************************************/

#include "Vampire.hpp"

/************************************************************
** Description: Function Vampire()
**   This function is the Vampire class default constructor.
************************************************************/
Vampire::Vampire(std::string name) : Creature(name)
{
	// -- Initial variables. --
	int num_dice = 1;
	int side_count = 12;

	// -- Set protected members. --
	setSword(num_dice, side_count);

	side_count = 6;
	setShield(num_dice, side_count);

	armor = 1;
	strength = 18;
}

/************************************************************
** Description: Function Vampire()
**   This function is the Vampire class copy constructor.
************************************************************/
Vampire::Vampire(const Vampire& obj) : Creature(obj)
{
	// -- Set all protected members using the Vampire passed as reference. --
}

/************************************************************
** Description: Function operator=()
**   This function is the overloaded assignment operator.
************************************************************/
Vampire& Vampire::operator=(const Vampire& right)
{
	// -- Check that the left and right don't match. --
	if (this != &right) // Assign right to left if there is no match.
	{
		this->setSword(right.Sword.size(), right.Sword[0]->getSide());
		this->setShield(right.Shield.size(), right.Shield[0]->getSide());
		this->armor = right.armor;
		this->strength = right.strength;
		this->name = right.name;
	}

	// -- Return the Vampire object. --
	return *this;
}

/************************************************************
** Description: Function defend()
**   This function is the defend function for Vampire.
**   It starts by rolling for charm. If charm is triggered, it erases
**   the attack roll printed previously, and returns false for
**   death status. If charm is not triggered, it calls printShield(), rolls
**   the Shield dice, prints the output, and returns the death
**	 status of the Creature.
************************************************************/
bool Vampire::defend(std::mt19937 &mers_twist, Team color, int atk_roll)
{
	// -- Constants. --
	const int NUM_OF_SIDES = 2;

	// -- Initial variables. --
	int def_roll;
	int damage = 0;
	int charm = 0;
	char whitespace = ' ';
	std::uniform_int_distribution<int> dist(1, NUM_OF_SIDES);

	// -- Flip a coin. --
	charm = dist(mers_twist) - 1;

	// -- Determine if charm is used. --
	if (charm)
	{
		// -- Erase previous line of attack text. --
		printf("\r %100c", whitespace);
		// -- Vampire uses charm instead. --
		printf("\r");
		printTeam(color);
		std::cout << " uses charm and is not attacked." << std::endl;
		return false;
	}
	else
	{
		// -- Print defend dice. --
		std::cout << std::endl;
		printShield();

		// -- Use Shield to generate the defend roll. --
		def_roll = rollShield(mers_twist);

		// -- Calculate damage taken. --
		damage = atk_roll - def_roll - armor;

		// -- Print defend roll. --
		printTeam(color);
		std::cout << " defends for " << def_roll << "." << std::endl;

		// -- Check if damage is above zero, and deduct from strength
		//    accordingly, also return the death status. --
		printTeam(color);
		if (damage > 0)
		{
			strength -= damage;
			if (strength <= 0)
			{
				strength = 0;
				std::cout << " has died." << std::endl;
				return true;
			}
			else
			{
				std::cout << " takes " << damage << " damage." << std::endl;
				return false;
			}
		}
		else
		{
			std::cout << " takes no damage." << std::endl;
			return false;
		}
	}
}

/************************************************************
** Description: Function regen()
**   This function is the regen function for Vampire.
************************************************************/
int Vampire::regen(std::mt19937 &mers_twist)
{
	// -- Initial variables. --
	int num_of_sides = 9;
	int max_creature = 18;
	int recovery = 0;
	int init_str = strength;
	Die HealDie(num_of_sides);

	// -- Recover a portion of its strength prior to going to the end of its
	//    Team's queue. --
	recovery = HealDie.roll(mers_twist);
	strength += recovery;
	if (strength > max_creature)
	{
		strength = max_creature;
	}

	// -- Return actual strength recovered. --
	return strength - init_str;
}
