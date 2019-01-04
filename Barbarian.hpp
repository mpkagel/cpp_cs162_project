/************************************************************
** Program Name: Barbarian.hpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the prototype for the Barbarian class.
************************************************************/

#ifndef BARBARIAN_HPP
#define BARBARIAN_HPP

#include "Creature.hpp"

/************************************************************
** Description: Class Barbarian
**   The Barbarian class is a derived class of Creature.
**   Barbarians have armor 0, strength 12, and no special abilities.
************************************************************/
class Barbarian : public Creature
{
private:

public:
	// -- Constructor, copy constructor, overloaded assignment operator. --
	Barbarian(std::string name = " ");
	Barbarian(const Barbarian&); // Copy constructor.
	Barbarian& operator=(const Barbarian&); // Overloaded assignment operator.

	// -- Overridden pure virtual functions. --
	virtual void print() const { std::cout << "Barbarian"; };
	virtual Aspect getType() const { return BARBARIAN; };
	virtual int regen(std::mt19937 &);
};
#endif
