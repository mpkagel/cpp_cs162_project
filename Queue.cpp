/************************************************************
** Program Name: Queue.cpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the code for the Queue class.
**   The Queue class contains and modifies a queue
**   of Creature pointers in a double linked queue.
************************************************************/

#include "Queue.hpp"

/************************************************************
** Description: Function QueueNode()
**   This function is the QueueNode struct constructor.
************************************************************/
Queue::QueueNode::QueueNode(Aspect type, std::string name, QueueNode *prev1, QueueNode *next1)
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

	prev = prev1;
	next = next1;
}

/************************************************************
** Description: Function ~Queue()
**   This function is the Queue class default constructor.
************************************************************/
Queue::~Queue()
{
	// -- Keep calling removeFront() until the queue is empty. --
	while (front != NULL)
	{
		removeFront();
	}
}

/************************************************************
** Description: Function operator=()
**   This function is the overloaded assignment operator.
************************************************************/
Queue& Queue::operator=(const Queue& right)
{
	// -- Initial variables. --
	QueueNode *index = right.front;
	Aspect form;
	std::string name;

	// -- Check that the left and right don't match. --
	if (this != &right) // Assign right to left if there is no match.
	{
		while (index != NULL)
		{
			form = index->inductee->getType();
			name = index->inductee->getName();
			this->addBack(form, name);
			index = index->next;
		}
	}

	// -- Return the Queue object. --
	return *this;
}

/************************************************************
** Description: Function operator[]()
**   This function is the overloaded assignment operator.
************************************************************/
Creature * & Queue::operator[](int counter)
{
	// -- Initial variables. --
	QueueNode *index = this->front;
	
	// -- Cycle through the queue the specified number of times. --
	for (int i = 0; i < counter; i++)
	{
		index = index->next;
	}

	// -- Return pointer to Creature by reference. --
	return index->inductee;
}

/************************************************************
** Description: Function addBack()
**   This function adds a Creature pointer to the back of the queue.
************************************************************/
void Queue::addBack(Aspect type, std::string name)
{
	// -- Initial variables. --
	QueueNode *index = NULL;

	// -- Check if the queue is empty. If so, create the back,
	//    and if not, add a new back and adjust the old back
	//    accordingly. --
	if (back == NULL)
	{
		back = new QueueNode(type, name, this->back);
		front = back;
	}
	else
	{
		index = back;
		back = new QueueNode(type, name, this->back);
		index->next = back;
		index = NULL;
	}
}

/************************************************************
** Description: Function removeFront()
**   This function removes a Creature pointer from the front of the queue.
************************************************************/
void Queue::removeFront()
{
	// -- Initial variables. --
	QueueNode *index = NULL;

	// -- Check if the queue is empty. If so, throw the Empty()
	//    exception, and if not, remove the front and move the 
	//    front to front->next. --
	if (front == NULL)
	{
		std::cout << "The queue is empty." << std::endl;
		std::cout << "Cannot remove a node from an empty queue."
			<< std::endl << std::endl;
	}
	else if (front->next == NULL) // Check for single element.
	{
		delete front;
		front = NULL;
		back = NULL;
	}
	else
	{
		index = front->next;
		delete front;
		front = index;
		index = NULL;
	}
}

/************************************************************
** Description: Function printQueue()
**   This function prints the queue from front to back.
************************************************************/
void Queue::printQueue()
{
	// -- Initial variables. --
	int counter = 1;
	QueueNode *index = front;

	// -- Check if the queue is empty, if so, print that
	//    the queue is empty, and if not, cycle through
	//    the queue and print each integer from front to
	//    back. --
	if (front == NULL)
	{
		std::cout << "The queue is empty." << std::endl << std::endl;
	}
	else
	{
		while (index != NULL)
		{
		        std::cout << std::setw(12) << "Fighter #" << counter << " is a ";
			index->inductee->print();
			std::cout << " named " << index->inductee->getName() << "."
				  << std::endl;
			index = index->next;
			counter++;
		}
		std::cout << std::endl;
	}
}

/************************************************************
** Description: Function checkName()
**   This function checks a string against all of the names
**   in the queue and returns true if it finds a match, and
**   false if it doesn't find a match.
************************************************************/
bool Queue::checkName(char *inp_str)
{
	// -- Initial variables. --
	bool match = false;
	QueueNode *index = front;

	// -- Cycle through the queue, comparing the string against
	//    all of the fighter's names in the queue. --
	while (index != NULL)
	{
		if (!strcmp(inp_str, (index->inductee->getName()).c_str()))
		{
			match = true;
		}
		index = index->next;
	}
	index = NULL;
	
	// -- Return whether or not a match was found. --
	return match;
}

/************************************************************
** Description: Function isEmpty()
**   This function determines whether the queue is empty or not
**   and returns a Boolean value.
************************************************************/
bool Queue::isEmpty()
{
	// -- Initial variables. --
	bool empty = false;

	// -- Check if the queue is empty. --
	if (front == NULL)
	{
		empty = true;
	}
	
	return empty;
}


