/************************************************************
** Program Name: Stack.hpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the prototype for the Stack class.
************************************************************/

#ifndef STACK_HPP
#define STACK_HPP

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
** Description: Class Stack
**   The Stack class contains a single linked stack and
**   the functions to manipulate the stack entries and display the
**   stack entries.
************************************************************/
class Stack
{
private:
	struct StackNode // Double linked structure.
	{
		Creature *inductee;
		StackNode *next; // Pointer to next StackNode.
		StackNode(Aspect, std::string, StackNode *next1 = NULL);
	        ~StackNode()
	        {
		       delete inductee;
		       inductee = NULL;
		}
	};
	StackNode *top; // First node of Stack.

public:
	// -- Constructor and destructor. --
	Stack() { top = NULL; }; // Default constructor.
	~Stack(); // Default destructor.

	// -- Unique class functions. --
	void addTop(Aspect type, std::string name) 
		{ top = new StackNode(type, name, this->top); };
	void removeTop();
	void printStack(int);
	bool isEmpty();
};
#endif
