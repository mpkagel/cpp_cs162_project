/************************************************************
** Program Name: Creature.hpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the prototype for the Creature class.
************************************************************/

#ifndef CREATURE_HPP
#define CREATURE_HPP

#include <iostream>
#include <string>
#include <vector>
#include "Die.hpp"

/************************************************************
** Description: Class Creature
**   The Creature class is an abstract base class for other
**   derived creatures/characters. Each Creature has a Sword
**   (attack dice), a Shield (defend dice), an armor rating,
**   a strength, and a name.
************************************************************/
const int MAXSTR = 40; // Maximum damage, used for Medusa and other instakills if any.
					   // MAXSTR represents the maximum strength of 20 from Harry Potter with Hogwarts,
					   // multiplied by 2.	
enum Team { RED, BLUE };
enum Aspect { VAMPIRE, BARBARIAN, BLUEMEN, MEDUSA, HARRYPOTTER };

class Creature
{
protected:
	std::vector<Die *> Sword; // Collection of dice constituting the attack dice, similar to Risk.
	std::vector<Die *> Shield; // Collection of dice constituting the defend dice, similar to Risk.
	int armor;
	int strength;
	std::string name;

public:
	// -- Constructor, destructor, and copy constructor. --
	Creature(std::string name = " ") { this->name = name; };
	virtual ~Creature();
	Creature(const Creature&); // Copy constructor.

	// -- Getters and setters. --
	void setSword(int, int);
	void setShield(int, int);
	int getArmor() { return this->armor; };
	int getStrength() { return this->strength; };
	std::string getName() { return name; };
	void setStrength(int strength) { this->strength = strength; };

	// -- Unique class functions. --
	int rollSword(std::mt19937 &);
	int rollShield(std::mt19937 &);
	void printSword() const;
	void printShield() const;
	void printTeam(Team) const;

	// -- Virtual functions. --
	virtual int attack(std::mt19937 &, Team);
	virtual bool defend(std::mt19937 &, Team, int);

	// -- Pure virtual functions. --
	virtual void print() const = 0;
	virtual Aspect getType() const = 0;
	virtual int regen(std::mt19937 &) = 0;
};
#endif
