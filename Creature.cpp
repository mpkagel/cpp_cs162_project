/************************************************************
** Program Name: Creature.cpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the code for the Creature class.
**   The Creature class is an abstract base class for all of
**   the creatures/characters fighting in this fantasy combat
**   game.
************************************************************/

#include "Creature.hpp"

/************************************************************
** Description: Function ~Creature()
**   This function is the Creature default destructor.
************************************************************/
Creature::~Creature()
{
	// -- Delete memory for Sword. --
	for (int i = 0; i < Sword.size(); i++)
	{
		delete Sword[i];
		Sword[i] = NULL;
	}

	// -- Delete memory for Shield. --
	for (int i = 0; i < Shield.size(); i++)
	{
		delete Shield[i];
		Shield[i] = NULL;
	}

	// -- Clear vectors. --
	Sword.clear();
	Shield.clear();
}

/************************************************************
** Description: Function Creature()
**   This function is the Creature class copy constructor.
************************************************************/
Creature::Creature(const Creature& obj)
{
	// -- Set all protected members using the Creature passed as reference. --
	this->setSword(obj.Sword.size(), obj.Sword[0]->getSide());
	this->setShield(obj.Shield.size(), obj.Shield[0]->getSide());
	this->armor = obj.armor;
	this->strength = obj.strength;
	this->name = obj.name;
}

/************************************************************
** Description: Function setSword()
**   This function sets the Sword vector with the specified
**   quantity of die, and each die has the same number of sides
**   that are specified.
************************************************************/
void Creature::setSword(int qnty, int sides)
{
	// -- Initial variables. --
	Die *Temp = NULL;

	// -- Delete old Sword if any. --
	for (int i = 0; i < Sword.size(); i++)
	{
		delete Sword[i];
		Sword[i] = NULL;
	}
	Sword.clear();

	// -- Add a new Sword with specified values. --
	for (int i = 0; i < qnty; i++)
	{
		Temp = new Die;
		Temp->setSide(sides);
		Sword.push_back(Temp);
		Temp = NULL;
	}
}

/************************************************************
** Description: Function setShield()
**   This function sets the Shield vector with the specified
**   quantity of die, and each die has the same number of sides
**   that are specified.
************************************************************/
void Creature::setShield(int qnty, int sides)
{
	// -- Initial variables. --
	Die *Temp = NULL;

	// -- Delete old Shield if any, primarily for Blue Men. --
	for (int i = 0; i < Shield.size(); i++)
	{
		delete Shield[i];
		Shield[i] = NULL;
	}
	Shield.clear();

	// -- Add a new Shield with specified values. --
	for (int i = 0; i < qnty; i++)
	{
		Temp = new Die;
		Temp->setSide(sides);
		Shield.push_back(Temp);
		Temp = NULL;
	}
}

/************************************************************
** Description: Function rollSword()
**   This function rolls each Die in Sword and returns the output.
************************************************************/
int Creature::rollSword(std::mt19937 &mers_twist)
{
	// -- Initial variables. --
	int roll_output = 0;

	// -- Roll dice. --
	for (int i = 0; i < Sword.size(); i++)
	{
		roll_output += Sword[i]->roll(mers_twist);
	}

	// -- Return sum of rolls. --
	return roll_output;
}

/************************************************************
** Description: Function rollShield()
**   This function rolls each Die in Shield and returns the output.
************************************************************/
int Creature::rollShield(std::mt19937 &mers_twist)
{
	// -- Initial variables. --
	int roll_output = 0;

	// -- Roll dice. --
	for (int i = 0; i < Shield.size(); i++)
	{
		roll_output += Shield[i]->roll(mers_twist);
	}

	// -- Return sum of rolls. --
	return roll_output;
}

/************************************************************
** Description: Function printSword()
**   This function prints the Sword's Die information.
************************************************************/
void Creature::printSword() const
{
	std::cout << "A ";
	print();
	std::cout << " uses a ";
	std::cout << Sword.size() << "d" << Sword[0]->getSide();
	std::cout << " for attacking." << std::endl;
}

/************************************************************
** Description: Function printShield()
**   This function prints the Shield's Die information.
************************************************************/
void Creature::printShield() const
{
	std::cout << "A ";
	print();
	std::cout << " uses a ";
	std::cout << Shield.size() << "d" << Shield[0]->getSide();
	std::cout << " for defending." << std::endl;
}

/************************************************************
** Description: Function printTeam()
**   This function is the default defend function for Creature.
**   It calls printShield(), rolls the Shield dice, prints the
**   output, and returns the death status of the Creature.
************************************************************/
void Creature::printTeam(Team color) const
{
	std::cout << "The ";
	if (color == RED)
	{
		std::cout << "Red";
	}
	else
	{
		std::cout << "Blue";
	}
	std::cout << " Team's "; 
	print();
}

/************************************************************
** Description: Function attack()
**   This function is the default attack function for Creature.
**   It calls printSword(), rolls the Sword dice, prints the
**   output, and returns the attack roll.
************************************************************/
int Creature::attack(std::mt19937 &mers_twist, Team color)
{
	// -- Initial variables. --
	int atk_roll = rollSword(mers_twist);

	// -- Print attack dice. --
	printSword();

	// -- Print attack roll. --
	printTeam(color);
	std::cout << " attacks for " << atk_roll << ".";

	// -- Return attack roll. --
	return atk_roll;
}

/************************************************************
** Description: Function defend()
**   This function is the default defend function for Creature.
**   It calls printShield(), rolls the Shield dice, prints the
**   output, and returns the death status of the Creature.
************************************************************/
bool Creature::defend(std::mt19937 &mers_twist, Team color, int atk_roll)
{
	// -- Initial variables. --
	int def_roll;
	int damage = 0;

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

