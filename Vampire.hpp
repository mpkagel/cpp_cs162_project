/************************************************************
** Program Name: Vampire.hpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the prototype for the Vampire class.
************************************************************/

#ifndef VAMPIRE_HPP
#define VAMPIRE_HPP

#include <cstring>
#include "Creature.hpp"

/************************************************************
** Description: Class Vampire
**   The Vampire class is a derived class of Creature.
**   Vampires have armor 1, strength 18, and a charm ability that
**   shows up in defend().
************************************************************/
class Vampire : public Creature
{
private:

public:
	// -- Constructor, copy constructor, overloaded assignment operator. --
	Vampire(std::string name = " ");
	Vampire(const Vampire&); // Copy constructor.
	Vampire& operator=(const Vampire&); // Overloaded assignment operator.

	// -- Overridden virtual functions. --
	virtual bool defend(std::mt19937 &, Team, int) override;

	// -- Overridden pure virtual functions. --
	virtual void print() const { std::cout << "Vampire"; };
	virtual Aspect getType() const { return VAMPIRE; };
	virtual int regen(std::mt19937 &);
};
#endif
