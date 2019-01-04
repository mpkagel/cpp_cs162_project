/************************************************************
** Program Name: Queue.hpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the prototype for the Queue class.
************************************************************/

#ifndef QUEUE_HPP
#define QUEUE_HPP

#include <iomanip>
#include <iostream>
#include <string>
#include "Creature.hpp"
#include "Barbarian.hpp"
#include "BlueMen.hpp"
#include "HarryPotter.hpp"
#include "Medusa.hpp"
#include "Vampire.hpp"

/************************************************************
** Description: Class Queue
**   The Queue class contains a double linked queue and
**   the functions to manipulate the queue entries and display the
**   queue entries.
************************************************************/
class Queue
{
private:
	struct QueueNode // Double linked structure.
	{
		Creature *inductee;
		QueueNode *next; // Pointer to next QueueNode.
		QueueNode *prev; // Pointer to previous QueueNode.
		QueueNode(Aspect, std::string, QueueNode *prev1 = NULL, QueueNode *next1 = NULL);
	        ~QueueNode()
	        {
		     delete inductee;
		     inductee = NULL;
	        } 
	};
	QueueNode *front; // First node of Queue.
	QueueNode *back; // Last node of Queue.

public:
	// -- Constructor, destructor, and overloaded assignment operator. --
	Queue() // Default constructor.
	{
		front = NULL;
		back = NULL;
	};
	~Queue(); // Default destructor.
	Queue& operator=(const Queue&); // Overloaded assignment operator.

	// -- Other overloaded operators. --
	Creature * & operator[](int); // Overloaded [].

	// -- Getters. --
	Creature * & getBackCreature() { return back->inductee; };

	// -- Unique class functions. --
	void addBack(Aspect, std::string);
	void removeFront();
	void printQueue();
	bool checkName(char *);
	bool isEmpty();
};
#endif
