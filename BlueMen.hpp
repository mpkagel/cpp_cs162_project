/************************************************************
** Program Name: BlueMen.hpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the prototype for the BlueMen class.
************************************************************/

#ifndef BLUEMEN_HPP
#define BLUEMEN_HPP

#include "Creature.hpp"

/************************************************************
** Description: Class BlueMen
**   The BlueMen class is a derived class of Creature.
**   BlueMen have armor 3, strength 12, and a mob ability that
**   shows up in defend().
************************************************************/
class BlueMen : public Creature
{
private:

public:
	// -- Constructor, copy constructor, overloaded assignment operator. --
	BlueMen(std::string name = " ");
	BlueMen(const BlueMen&); // Copy constructor.
	BlueMen& operator=(const BlueMen&); // Overloaded assignment operator.

	// -- Overridden virtual functions. --
	virtual int attack(std::mt19937 &, Team) override;
	virtual bool defend(std::mt19937 &, Team, int) override;

	// -- Overridden pure virtual functions. --
	virtual void print() const { std::cout << "Blue Men"; };
	virtual Aspect getType() const { return BLUEMEN; };
	virtual int regen(std::mt19937 &);
};
#endif
