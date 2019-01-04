/************************************************************
** Program Name: Barbarian.cpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the code for the Barbarian class.
**   The Barbarian class is derived from Creature.
************************************************************/

#include "Barbarian.hpp"

/************************************************************
** Description: Function Barbarian()
**   This function is the Barbarian class default constructor.
************************************************************/
Barbarian::Barbarian(std::string name) : Creature(name)
{
	// -- Initial variables. --
	int num_dice = 2;
	int side_count = 6;

	// -- Set protected members. --
	setSword(num_dice, side_count);
	setShield(num_dice, side_count);
	armor = 0;
	strength = 12;
}

/************************************************************
** Description: Function Barbarian()
**   This function is the Barbarian class copy constructor.
************************************************************/
Barbarian::Barbarian(const Barbarian& obj) : Creature(obj)
{
	// -- Set all protected members using the Barbarian passed as reference. --
}

/************************************************************
** Description: Function operator=()
**   This function is the overloaded assignment operator.
************************************************************/
Barbarian& Barbarian::operator=(const Barbarian& right)
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
	
	// -- Return the Barbarian object. --
	return *this;
}

/************************************************************
** Description: Function regen()
**   This function is the regen function for Barbarian.
************************************************************/
int Barbarian::regen(std::mt19937 &mers_twist)
{
	// -- Initial variables. --
	int num_of_sides = 6;
	int max_creature = 12;
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
