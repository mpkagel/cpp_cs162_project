/************************************************************
** Program Name: Medusa.hpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the prototype for the Medusa class.
************************************************************/

#ifndef MEDUSA_HPP
#define MEDUSA_HPP

#include "Creature.hpp"

/************************************************************
** Description: Class Medusa
**   The Medusa class is a derived class of Creature.
**   Medusas have armor 3, strength 8, and a glare ability that
**   shows up in attack().
************************************************************/
class Medusa : public Creature
{
private:

public:
	// -- Constructor, copy constructor, overloaded assignment operator. --
	Medusa(std::string name = " ");
	Medusa(const Medusa&); // Copy constructor.
	Medusa& operator=(const Medusa&); // Overloaded assignment operator.

	// -- Overridden virtual functions. --
	virtual int attack(std::mt19937 &, Team) override;

	// -- Overridden pure virtual functions. --
	virtual void print() const { std::cout << "Medusa"; };
	virtual Aspect getType() const { return MEDUSA; };
	virtual int regen(std::mt19937 &);
};
#endif
