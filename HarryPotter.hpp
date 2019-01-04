/************************************************************
** Program Name: HarryPotter.hpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the prototype for the HarryPotter class.
************************************************************/

#ifndef HARRYPOTTER_HPP
#define HARRYPOTTER_HPP

#include "Creature.hpp"

/************************************************************
** Description: Class HarryPotter
**   The HarryPotter class is a derived class of Creature.
**   HarryPotters have armor 0, strength 10, and a Hogwarts ability that
**   shows up in defend().
************************************************************/
class HarryPotter : public Creature
{
private:
	int lives;

public:
	// -- Constructor, copy constructor, overloaded assignment operator. --
	HarryPotter(std::string name = " ");
	HarryPotter(const HarryPotter&); // Copy constructor.
	HarryPotter& operator=(const HarryPotter&); // Overloaded assignment operator.

	// -- Overridden virtual functions. --
	virtual bool defend(std::mt19937 &, Team, int) override;

	// -- Overridden pure virtual functions. --
	virtual void print() const { std::cout << "Harry Potter"; };
	virtual Aspect getType() const { return HARRYPOTTER; };
	virtual int regen(std::mt19937 &);
};
#endif
