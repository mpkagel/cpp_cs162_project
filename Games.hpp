/************************************************************
** Program Name: Games.hpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the class prototype for the Games class.
************************************************************/

#ifndef GAMES_HPP
#define GAMES_HPP

#include "Die.hpp"
#include "Menu.hpp"
#include "Queue.hpp"
#include "Stack.hpp"
#include "ValidInput.hpp"

/************************************************************
** Description: Class Games
**   The Games class contains two queues of Creatures and
**   a stack for Creatures that have lost. The Games class has
**   the functions necessary to run a tournament with the queues
**   and manage Creatures in the queues and stack.
************************************************************/
class Games
{
private:
	Queue Red; 
	Queue Blue;
	Stack Saniarium; // Has the loser pile.

public:
	// -- Destructor. --
	~Games();

	// -- Unique class functions. --
	void evacuate();
	bool fillLineup(Team, int);
	void tourney(std::mt19937 &);
	Team fight(std::mt19937 &, int);
	Team finalRound(std::mt19937 &, Team);
	void printTeamQueue(Team);
};
#endif
