/************************************************************
** Program Name: ValidInput.cpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the code for the ValidInput class.
**   The ValidInput class is used for input validation of
**   integers, doubles, strings, and characters.
************************************************************/

#include "ValidInput.hpp"

/************************************************************
** Description: Function getIntLoop()
**   This function allows the ValidInput object to run
**   through a do-while loop rather than using main to do
**   the same thing. It calls the getInt() and getStatus()
**   functions until a successful input is received.
************************************************************/
void ValidInput::getIntLoop(std::string request, int *ptr, int min, int max)
{
	do
	{
		if (min != INTMIN && max != INTMAX)
		{
			std::cout << request << min << " and " << max << ": ";
		}
		else
		{
			std::cout << request;
		}
		getInt(ptr, min, max);
	} while (getStatus() != 0);
}

/************************************************************
** Description: Function getDoubLoop()
**   This function allows the ValidInput object to run
**   through a do-while loop rather than using main to do
**   the same thing. It calls the getDoub() and getStatus()
**   functions until a successful input is received.
************************************************************/
void ValidInput::getDoubLoop(std::string request, double *ptr, double min, double max)
{
	do
	{
		std::cout << request << std::fixed << std::setprecision(2)
			<< min << " and " << max << ": ";
		getDoub(ptr, min, max);
	} while (getStatus() != 0);
}

/************************************************************
** Description: Function getStrLoop()
**   This function allows the ValidInput object to run
**   through a do-while loop rather than using main to do
**   the same thing. It calls the getStrValid() and getStatus()
**   functions until a successful input is received.
************************************************************/
void ValidInput::getStrLoop(std::string request, char *inp_str)
{
	do
	{
		std::cout << request;
		getStr(inp_str);
	} while (getStatus() != 0);
}

/************************************************************
** Description: Function getStrLoopAlternate()
**   This function allows the ValidInput object to run
**   through a do-while loop rather than using main to do
**   the same thing. It starts with getStrInvalid() to see if
**   the escape keyword/s have been entered. If not, then it
**   checks against valid input with getStrValid() to see if 
**   that matches. It uses getStatus() to determine whether to
**   discontinue the do-while loop or to keep going.
************************************************************/
void ValidInput::getStrAlternateLoop(std::string request, char *inp_str, 
	const char** invalid_str, int size_invalid,
	const char** valid_str, int size_valid)
{
	// -- Initial variables. --
	bool internal = true;

	do
	{
		std::cout << request;
		getStrInvalid(inp_str, invalid_str, size_invalid);
		if (getStatus() == 0)
		{
			getStrValid(inp_str, valid_str, size_valid, internal);
		}
	} while (getStatus() < 0);
}

/************************************************************
** Description: Function getStrLoopValid()
**   This function allows the ValidInput object to run
**   through a do-while loop rather than using main to do
**   the same thing. It calls the getStrValid() and getStatus()
**   functions until a successful input is received.
************************************************************/
void ValidInput::getStrValidLoop(std::string request, char *inp_str, const char **valid_str, int size)
{
	do
	{
		std::cout << request;
		getStrValid(inp_str, valid_str, size);
	} while (getStatus() != 0);
}

/************************************************************
** Description: Function getStrLoopInvalid()
**   This function allows the ValidInput object to run
**   through a do-while loop rather than using main to do
**   the same thing. It calls the getStrInvalid() and getStatus()
**   functions until a successful input is received.
************************************************************/
void ValidInput::getStrInvalidLoop(std::string request, char *inp_str, const char **invalid_str, int size)
{
	do
	{
		std::cout << request;
		getStrInvalid(inp_str, invalid_str, size);
	} while (getStatus() < 0);
}

/************************************************************
** Description: Function getCharLoopValid()
**   This function allows the ValidInput object to run
**   through a do-while loop rather than using main to do
**   the same thing. It calls the getCharValid() and getStatus()
**   functions until a successful input is received.
************************************************************/
void ValidInput::getCharValidLoop(std::string request, char *inp_str, const char *valid_str, int size)
{
	do
	{
		std::cout << request;
		getCharValid(inp_str, valid_str, size);
	} while (getStatus() != 0);
}

/************************************************************
** Description: Function getInt()
**   This function validates input for integers. It has the
**   option to check the value against a minimum and a maximum,
**   but it doesn't have to check a value.
************************************************************/
void ValidInput::getInt(int *ptr, int min, int max, bool internal, const char *inp_str)
{
	// -- Initial variables. --
	status = -1;
	char buffer[4096];
	char test[4096];
	bool length_test = false;

	// -- If the check is internal, don't take input, and if the
	//    the check is external, get input from the user. --
	if (!internal)
	{
		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			printf("Reached EOF while reading data. \n \n");
			return;
		}
		else if (sscanf(buffer, "%d", ptr) != 1)
		{
			printf("Integer number not detected. \n \n");
			return;
		}
		else
		{
		sprintf(test, "%d", *ptr);
		length_test = ((strlen(test) + 1) == strlen(buffer));
		}
	}
	else
	{
		if (sscanf(inp_str, "%d", ptr) != 1)
		{
			printf("Integer number not detected. \n \n");
			return;
		}
		else
		{
		sprintf(test, "%d", *ptr);
		length_test = (strlen(test) == strlen(inp_str));
		}
	}
	
	// -- Take the user input or passed input and check it further. --
	if (length_test)
	{
		status = 0;

		if (min == INTMIN && max == INTMAX)
		{
			;
		}
		else
		{
			if (*ptr < min)
			{
				status = -1;
				printf("Value is below range. \n\n");
			}
			else if (*ptr > max)
			{
				status = -1;
				printf("Value is above range. \n\n");
			}
		}
	}
	else
	{
		printf("Invalid input. \n \n");
	}
}

/************************************************************
** Description: Function getDoub()
**   This function validates input for doubles. It has the
**   option to check the value against a minimum and a maximum,
**   but it doesn't have to check a value.
************************************************************/
void ValidInput::getDoub(double *ptr, double min, double max)
{
	// -- Initial variables. --
	status = -1;
	char buffer[4096];
	char test[4096];

	// -- Get input from user and check. --
	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
	{
		printf("Reached EOF while reading data. \n \n");
	}
	else if (sscanf(buffer, "%lf", ptr) != 1)
	{
		printf("Decimal number not detected. \n \n");
	}
	else
	{
		sscanf(buffer, "%s", test);
		if ((strlen(test) + 1) == strlen(buffer))
		{
			status = 0;
			if (min == DOUBMIN && max == DOUBMAX)
			{
				;
			}
			else
			{
				if (*ptr < min)
				{
					status = -1;
					printf("Value is below range. \n\n");
				}
				else if (*ptr > max)
				{
					status = -1;
					printf("Value is above range. \n\n");
				}
			}
		}
		else
		{
			printf("Invalid input. \n \n");
		}
	}
}

/************************************************************
** Description: Function getStr()
**   This function checks a string against the empty string
**   and lets all other input pass through.
************************************************************/
void ValidInput::getStr(char *inp_str)
{
	// -- Initial variables. --
	status = 0; // String will likely pass all checks.
	char buffer[4096];
	std::string transfer;
	int index = 0, j = 1;

	// -- Get input from user and check for empty string. --
	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
	{
		printf("Reached EOF while reading data. \n \n");
	}
	else if (sscanf(buffer, "%s", inp_str) < 0) // Use sscanf to test for empty strings.
	{

		status = -1; // Empty string is an invalid input.
		printf("Invalid input. \n \n");
	}
	if (status == 0)
	{
		transfer.assign(buffer);
		while (static_cast<int>(transfer.at(index)) == 32)
		{
			index++;
		}
		transfer.erase(0, index); // Remove leading white space.
		index = transfer.length() - 2;
		while (static_cast<int>(transfer.at(index)) == 32)
		{
			index--;
			j++;
		}
		transfer.erase(index + 1, j); // Remove trailing white space.
		strcpy(inp_str, transfer.c_str());
	}
}

/************************************************************
** Description: Function getStrValid()
**   This function checks a string against possible valid cases.
************************************************************/
void ValidInput::getStrValid(char *inp_str, const char **valid_str, int size, bool internal)
{
	// -- Initial variables. --
	status = -1;
	char buffer[4096];
	std::string transfer;

	// -- If the check is internal, don't take input, and if the
	//    the check is external, get input from the user. --
	if (!internal)
	{
		if (fgets(buffer, sizeof(buffer), stdin) == NULL)
		{
			printf("Reached EOF while reading data. \n \n");
		}
		else
		{
			transfer.assign(buffer);
			transfer.erase(transfer.length() - 1, 1); // Get rid of newline character.
			strcpy(inp_str, transfer.c_str());
		}
	}

	// -- Check user input or passed input against list of valid strings. --
	for (int i = 0; i < size; i++)
	{
		if (strcmp(inp_str, *(valid_str + i)) == 0)
		{
			status = 0;
		}
	}
	if (status != 0)
	{
		printf("No matching input detected. \n \n");
	}
}

/************************************************************
** Description: Function getStrInvalid()
**   This function checks a string against possible invalid cases.
************************************************************/
void ValidInput::getStrInvalid(char *inp_str, const char **invalid_str, int size)
{
	// -- Initial variables. --
	status = 0; // String will likely pass all checks.
	char buffer[4096];
	std::string transfer;
	int index = 0, j = 1;

	// -- Get input from user and check against invalid strings. --
	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
	{
		printf("Reached EOF while reading data. \n \n");
	}
	else
	{
	        if (sscanf(buffer, "%s", inp_str) < 0) // Use sscanf to test for empty strings.
		{
		        status = -1; // Empty string is an invalid input.
			printf("Invalid input. \n\n");
		}
		else
		{
		        transfer.assign(buffer);
		        transfer.erase(transfer.length() - 1, 1); // Get rid of newline character.
		        strcpy(inp_str, transfer.c_str());
			for (int i = 0; i < size; i++)
			{
				if (strcmp(inp_str, *(invalid_str + i)) == 0)
				{
					status = 1; // Alternative integer that still passes.
				}
			}
		}
	}
	if (status == 0)
	{
	        transfer.clear();
		transfer.assign(buffer);
		while (static_cast<int>(transfer.at(index)) == 32)
		{
			index++;
		}
		transfer.erase(0, index); // Remove leading white space.
		index = transfer.length() - 2;
		while (static_cast<int>(transfer.at(index)) == 32)
		{
			index--;
			j++;
		}
		transfer.erase(index + 1, j); // Remove trailing white space.
		strcpy(inp_str, transfer.c_str());
	}
}

/************************************************************
** Description: Function strToInt()
**   This function attempts to turn a string into a integer.
**   If this fails, the function calls getIntLoop().
************************************************************/
void ValidInput::strToInt(std::string prompt, int *ptr, int min, int max, const char *inp_str)
{
	// -- Initial variables. --
	bool internal = true;

	// -- Call getInt() with passed string. --
	getInt(ptr, min, max, internal, inp_str);

	// -- If the first getInt() fails, throw the string out,
	//    and keep calling getInt(). --
	if (status != 0)
	{
		getIntLoop(prompt, ptr, min, max);
	}
}

/************************************************************
** Description: Function getCharValid()
**   This function checks a character against possible valid cases.
************************************************************/
void ValidInput::getCharValid(char *inp_str, const char *valid_str, int size)
{
	// -- Initial variables. --
	status = -1;
	char buffer[4096];
	char test[4096];

	// -- Get input from user and check against list of valid characters. --
	if (fgets(buffer, sizeof(buffer), stdin) == NULL)
	{
		printf("Reached EOF while reading data. \n \n");
	}
	else if (sscanf(buffer, "%c", inp_str) != 1)
	{
		printf("No character detected. \n \n");
	}
	else
	{
		sprintf(test, "%c", *inp_str);
		if ((strlen(test) + 1) == strlen(buffer))
		{
			for (int i = 0; i < size; i++)
			{
				if (*inp_str == valid_str[i])
				{
					status = 0;
				}
			}
		}
		if (status != 0)
		{
			printf("No matching input detected. \n \n");
		}
	}
}

