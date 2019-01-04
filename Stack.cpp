/************************************************************
** Program Name: Stack.cpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the code for the Stack class.
**   The Stack class contains and modifies a stack
**   of Creature pointers in a single linked stack.
************************************************************/

#include "Stack.hpp"

/************************************************************
** Description: Function StackNode()
**   This function is the StackNode struct constructor.
************************************************************/
Stack::StackNode::StackNode(Aspect type, std::string name, StackNode *next1)
{
	switch (type)
	{
	case VAMPIRE:
		inductee = new Vampire(name);
		break;
	case BARBARIAN:
		inductee = new Barbarian(name);
		break;
	case BLUEMEN:
		inductee = new BlueMen(name);
		break;
	case MEDUSA:
		inductee = new Medusa(name);
		break;
	case HARRYPOTTER:
		inductee = new HarryPotter(name);
		break;
	}

	next = next1;
}

/************************************************************
** Description: Function ~Stack()
**   This function is the stack class default constructor.
************************************************************/
Stack::~Stack()
{
	// -- Keep calling removeFront() until the stack is empty. --
	while (top != NULL)
	{
		removeTop();
	}
}

/************************************************************
** Description: Function removeTop()
**   This function removes Creature pointer from the top of the Stack.
************************************************************/
void Stack::removeTop()
{
	// -- Initial variables. --
	StackNode *index = NULL;

	// -- Check if the stack is empty. If so, throw the Empty()
	//    exception, and if not, remove the front and move the 
	//    top to top->next. --
	if (top == NULL)
	{
		std::cout << "The stack is empty." << std::endl;
		std::cout << "Cannot remove a node from an empty stack."
			<< std::endl << std::endl;
	}
	else if (top->next == NULL) // Check for single element.
	{
		delete top;
		top = NULL;
	}
	else
	{
		index = top->next;
		delete top;
		top = index;
		index = NULL;
	}
}

/************************************************************
** Description: Function print()
**   This function prints the stack from top to bottom.
************************************************************/
void Stack::printStack(int count)
{
	// -- Initial variables. --
	StackNode *index = top;

	// -- Check if the stack is empty, if so, print that
	//    the stack is empty, and if not, cycle through
	//    the stack and print each integer from top to
	//    bottom. --
        if (top == NULL)
	{
	      std::cout << "The stack is empty." << std::endl << std::endl;
	}
	else
	{
	    while (index != NULL)
	    {
	      std::cout << std::setw(9) << "Bout #" << count 
		  << ", the loser was: A ";
	      index->inductee->print();
	      std::cout << " named " << index->inductee->getName() << "."
		    << std::endl;
	      index = index->next;
	      count--;
	    }
	}
        std::cout << std::endl; 
}

/************************************************************
** Description: Function isEmpty()
**   This function determines whether the stack is empty or not
**   and returns a Boolean value.
************************************************************/
bool Stack::isEmpty()
{
	// -- Initial variables. --
	bool empty = false;

	// -- Check if the stack is empty. --
	if (top == NULL)
	{
		empty = true;
	}

	return empty;
}

