/************************************************************
** Program Name: Medusa.cpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the code for the Medusa class.
**   The Medusa class is derived from Creature.
************************************************************/

#include "Medusa.hpp"

/************************************************************
** Description: Function Medusa()
**   This function is the Medusa class default constructor.
************************************************************/
Medusa::Medusa(std::string name) : Creature(name)
{
	// -- Initial variables. --
	int num_dice = 2;
	int side_count = 6;

	// -- Set protected members. --
	setSword(num_dice, side_count);

	num_dice = 1;
	setShield(num_dice, side_count);

	armor = 3;
	strength = 8;
}

/************************************************************
** Description: Function Medusa()
**   This function is the Medusa class copy constructor.
************************************************************/
Medusa::Medusa(const Medusa& obj) : Creature(obj)
{
	// -- Set all protected members using the Medusa passed as reference. --
}

/************************************************************
** Description: Function operator=()
**   This function is the overloaded assignment operator.
************************************************************/
Medusa& Medusa::operator=(const Medusa& right)
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

	// -- Return the Medusa object. --
	return *this;
}

/************************************************************
** Description: Function attack()
**   This function is the attack function for Medusa.
**   It calls printSword() and rolls the Sword dice. If the roll is
**   a 12, glare is triggered which causes the roll to go from
**   12 to whatever MAXSTR is set to. MAXSTR is supposed to be set
**   high enough to kill anything in one shot. If glare is not
**   triggered, then attack prints the output, and returns the
**   attack roll as normal.
************************************************************/
int Medusa::attack(std::mt19937 &mers_twist, Team color)
{
	// -- Initial variables. --
	int atk_roll = rollSword(mers_twist);

	// -- Print attack dice. --
	printSword();

	// -- Print attack roll. --
	printTeam(color);
	if (atk_roll == 12) // Glare condition.
	{
		std::cout << " uses glare.";
		atk_roll = MAXSTR;
	}
	else
	{
		std::cout << " attacks for " << atk_roll << ".";
	}

	// -- Return attack roll. --
	return atk_roll;
}

/************************************************************
** Description: Function regen()
**   This function is the regen function for Medusa.
************************************************************/
int Medusa::regen(std::mt19937 &mers_twist)
{
	// -- Initial variables. --
	int num_of_sides = 4;
	int max_creature = 8;
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
