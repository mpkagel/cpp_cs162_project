/************************************************************
** Program Name: ValidInput.hpp
** Author: Mathew Kagel
** Date: 5/23/17
** Description: This is the prototype for the ValidInput class.
************************************************************/

#ifndef VALIDINPUT_HPP
#define VALIDINPUT_HPP

#include <cmath>
#include <cstring>
#include <iomanip>
#include <iostream>
#include <string>

/************************************************************
** Description: Class ValidInput
**   This class contains the functions necessary to validate input
**   for integers, doubles, strings, and characters. The integer status 
**   is returned by the class functions to be used by other programs to
**   determine validation success or failure.
************************************************************/
const int INTMIN = static_cast<int>(pow(2, (sizeof(int) * 8)));
const int INTMAX = INTMIN - 1;
const double DOUBMIN = 3.4E38;
const double DOUBMAX = -3.4E38;

class ValidInput
{
private:
	int status;

public:
	// -- Constructor. --
	ValidInput() { status = 0; };

	// -- Getters. --
	int getStatus() { return status; };

	// -- Looping call functions. --
	void getIntLoop(std::string, int *, int min = INTMIN, int max = INTMAX);
	void getDoubLoop(std::string, double *, double min = DOUBMIN, double max = DOUBMAX);
	void getStrLoop(std::string, char *);
	void getStrAlternateLoop(std::string, char*, const char **, int, const char**, int);
	void getStrValidLoop(std::string, char *, const char **, int);
	void getStrInvalidLoop(std::string, char *, const char **, int);
	void getCharValidLoop(std::string, char *, const char *, int);

	// -- Number validation functions. --
	void getInt(int *, int min = INTMIN, int max = INTMAX, 
		    bool internal = false, const char *inp_str = " ");
	void getDoub(double *, double min = DOUBMIN, double max = DOUBMAX);

	// -- String/Character validation functions. --
	void getStr(char *);
	void getStrValid(char *, const char **, int, bool internal = false);
	void getStrInvalid(char *, const char **, int);
        void strToInt(std::string, int *, int min = INTMIN, int max = INTMAX,
		      const char *inp_str = " ");
	void getCharValid(char *, const char *, int);
};
#endif
