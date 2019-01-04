/************************************************************
** Program Name: HarryPotter.cpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the code for the HarryPotter class.
**   The HarryPotter class is derived from Creature.
************************************************************/

#include "HarryPotter.hpp"

/************************************************************
** Description: Function HarryPotter()
**   This function is the HarryPotter class default constructor.
************************************************************/
HarryPotter::HarryPotter(std::string name) : Creature(name)
{
	// -- Initial variables. --
	int num_dice = 2;
	int side_count = 6;

	// -- Set private members. --
	lives = 1;

	// -- Set protected members. --
	setSword(num_dice, side_count);
	setShield(num_dice, side_count);
	armor = 0;
	strength = 10;
}

/************************************************************
** Description: Function HarryPotter()
**   This function is the HarryPotter class copy constructor.
************************************************************/
HarryPotter::HarryPotter(const HarryPotter& obj) : Creature(obj)
{
	// -- Set all protected members using the HarryPotter passed as reference. --
	this->lives = obj.lives;
}

/************************************************************
** Description: Function operator=()
**   This function is the overloaded assignment operator.
************************************************************/
HarryPotter& HarryPotter::operator=(const HarryPotter& right)
{
	// -- Check that the left and right don't match. --
	if (this != &right) // Assign right to left if there is no match.
	{
		this->setSword(right.Sword.size(), right.Sword[0]->getSide());
		this->setShield(right.Shield.size(), right.Shield[0]->getSide());
		this->armor = right.armor;
		this->strength = right.strength;
		this->name = right.name;
		this->lives = right.lives;
	}
	
	// -- Return the HarryPotter object. --
	return *this;
}

/************************************************************
** Description: Function defend()
**   This function is the defend function for HarryPotter.
**   This version of defend() doesn't differ until HarryPotter
**   is about to die, in which case HarryPotters lives are checked,
**   and if he has any, he uses it and his strength jumps to 20 rather
**   than 0. If he doesn't have any he dies as any other Creature would.
************************************************************/
bool HarryPotter::defend(std::mt19937 &mers_twist, Team color, int atk_roll)
{
	// -- Initial variables. --
	int def_roll;
	int damage = 0;
	int hogwarts = 20;

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
			if (lives == 0)
			{
				strength = 0;
				std::cout << " has died." << std::endl;
				return true;
			}
			else
			{
				strength = hogwarts;
				std::cout << " uses Hogwarts." << std::endl;
				lives--;
				return false;
			}
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

/************************************************************
** Description: Function regen()
**   This function is the regen function for Harry Potter.
************************************************************/
int HarryPotter::regen(std::mt19937 &mers_twist)
{
	// -- Initial variables. --
	int num_of_sides = 5;
	int max_creature = 10;
	int recovery = 0;
	int init_str = strength;

	// -- If Hogwarts has been used, set max strength and HealDie
	//    differently. --
	if (lives == 0)
	{
		num_of_sides = 10;
		max_creature = 20;
	}

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
