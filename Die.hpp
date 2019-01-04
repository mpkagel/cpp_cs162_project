/************************************************************
** Program Name: Die.hpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the prototype for the Die class.
************************************************************/

#ifndef DIE_HPP
#define DIE_HPP

#include <random> // Using Mersenne Twister random number generator.

/************************************************************
** Description: Class Die
**   The Die class has a number of sides and a roll() function
**   to produce a random die roll between 1 and the number of sides.
************************************************************/
class Die
{
private:
	int n; // Number of sides on Die.

public:
	// -- Constructor. -- 
	Die() { n = 4; }; // Set die number of sides to minimum.
	Die(int n) { this->n = n; }; // Other constructor with one argument.
	Die(const Die &obj) { this->n = obj.n; }; // Copy constructor.
	Die& operator=(const Die &right) // Overloaded assignment operator.
	{
		if (this != &right) // Assign right to left if there is no match.
		{
			this->n = right.n;
		}
		return *this;
	};

	// -- Getters and setters. --
	void setSide(int n) { this->n = n; };
	int getSide() { return n; };

	// -- Unique class functions. --
	int roll(std::mt19937 &mers_twist)
	{
		std::uniform_int_distribution<int> dist(1, n);
		return dist(mers_twist);
	}; // Mersennse Twister has been seeded with a deterministic seed.
};
#endif
