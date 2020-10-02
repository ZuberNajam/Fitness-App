//FinalProject
//COP3014
//20180419

#ifndef _EXCEPTIONS_H_
#define _EXCEPTIONS_H_

#define _CRT_SECURE_NO_WARNINGS 
#include <iostream>
#include <exception>
using namespace std;


class NonPositiveValueException : public exception
{
public: const char* what() const throw()
	{
		return "Expected Positive Number Value";
	}	
};

class IllegalCharacterException : public exception
{
public: const char* what() const throw()
	{
		return "Illegal Character Entry";
	}	
};

class IllegalValueException : public exception
{
public: const char* what() const throw()
	{
		return "Entered Value Is Invalid";
	}	
};


















#endif
