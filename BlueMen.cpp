/************************************************************
** Program Name: BlueMen.cpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the code for the BlueMen class.
**   The BlueMen class is derived from Creature.
************************************************************/

#include "BlueMen.hpp"

/************************************************************
** Description: Function BlueMen()
**   This function is the regen function for Blue Men.
************************************************************/
BlueMen::BlueMen(std::string name) : Creature(name)
{
	// -- Initial variables. --
	int num_dice = 2;
	int side_count = 10;

	// -- Set protected members. --
	setSword(num_dice, side_count);

	num_dice = 3;
	side_count = 6;
	setShield(num_dice, side_count);

	armor = 3;
	strength = 12;
}

/************************************************************
** Description: Function BlueMen()
**   This function is the BlueMen class copy constructor.
************************************************************/
BlueMen::BlueMen(const BlueMen& obj) : Creature(obj)
{
	// -- Set all protected members using the BlueMen passed as reference. --
}

/************************************************************
** Description: Function operator=()
**   This function is the overloaded assignment operator.
************************************************************/
BlueMen& BlueMen::operator=(const BlueMen& right)
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
	
	// -- Return the BlueMen object. --
	return *this;
}

/************************************************************
** Description: Function attack()
**   This function is the default attack function for Creature.
**   It calls printSword(), rolls the Sword dice, prints the
**   output, and returns the attack roll. The override is there
**   to change one word of the output for the BlueMen class.
************************************************************/
int BlueMen::attack(std::mt19937 &mers_twist, Team color)
{
	// -- Initial variables. --
	int atk_roll = rollSword(mers_twist);

	// -- Print attack dice. --
	printSword();

	// -- Print attack roll. --
	printTeam(color);
	std::cout << " attack for " << atk_roll << ".";

	// -- Return attack roll. --
	return atk_roll;
}

/************************************************************
** Description: Function defend()
**   This function is the defend function for BlueMen.
**   It starts by using mob, which checks how many defend Die
**   BlueMen's Shield is supposed to have. Then it uses setShield()
**   to set it to that amount before continuing. After this, defend()
**   continues as it normally would: it calls printShield(), rolls
**   the Shield dice, prints the output, and returns the death
**	 status of the Creature.
************************************************************/
bool BlueMen::defend(std::mt19937 &mers_twist, Team color, int atk_roll)
{
	// -- Initial variables. --
	int def_roll;
	int damage = 0;
	int num_dice = 3;
	int side_count = 6;

	// -- Reset the Blue Men's Shield. --
	num_dice = ((strength - 1) / 4) + 1;
	setShield(num_dice, side_count);

	// -- Print defend dice.--
	std::cout << std::endl;
	printShield();

	// -- Use Shield to generate the defend roll. --
	def_roll = rollShield(mers_twist);

	// -- Calculate damage taken. --
	damage = atk_roll - def_roll - armor;

	// -- Print defend roll. --
	printTeam(color);
	std::cout << " defend for " << def_roll << "." << std::endl;

	// -- Check if damage is above zero, and deduct from strength
	//    accordingly, also return the death status. --
	printTeam(color);
	if (damage > 0)
	{
		strength -= damage;
		if (strength <= 0)
		{
			strength = 0;
			std::cout << " have died." << std::endl;
			return true;
		}
		else
		{
			std::cout << " take " << damage << " damage." << std::endl;
			return false;
		}
	}
	else
	{
		std::cout << " take no damage." << std::endl;
		return false;
	}
}

/************************************************************
** Description: Function regen()
**   This function is the overloaded assignment operator.
************************************************************/
int BlueMen::regen(std::mt19937 &mers_twist)
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
