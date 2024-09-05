/*
* infix_to_postfix_converter.h
* Modified : 25/08/2023
*
* This class represents the header for an infix to postfix expression converter.
* This file should be used in conjunction with Assignment 2 for SENG1120.
*/

#ifndef SENG1120_INFIX_TO_POSTFIX_H
#define SENG1120_INFIX_TO_POSTFIX_H

#include <cctype>      // isalnum
#include <stdexcept>   // standard exception classes
#include <string>
#include "lstack.h"
#include "lqueue.h"

class infix_to_postfix_converter
{
public:
    /*
    * Precondition: None
    * Postcondition: A new instance is created with the specified input.
    * The conversion process should be completed using the input, thereby initialising
    * the postfix string.
    */
    infix_to_postfix_converter(std::string& input);

    /*
    * Precondition: None
    * Postcondition: The converter is destroyed and all associated memory is freed.
    */
    ~infix_to_postfix_converter();

    /*
    * Returns a reference to the infix expression. This should be the string that was used
    * to initialise the class.
    *
    * Precondition: The class is initialised.
    * Postcondition: The class has not changed.
    */
    const std::string& get_infix() const;

    /*
    * Returns a reference to the (converted) postfix expression. This should be the postfix
    * expression that was converted from the input passed on creation.
    *
    * Precondition: The class is initialised.
    * Postcondition: The class has not changed.
    */
    const std::string& get_postfix() const;

private:

    /*
    * Returns the precedence of an operator. A higher value corresponds to a higher precedence.
    *
    * Precondition: The class is initialised.
    * Postcondition: The class has not changed.
    */
    int precedence(char op) const;

    /*
    * Converts the input string to postfix, which is then returned.
    * This method must use both your stack and queue, as described in the assignment spec.
    *
    * Note: A (single) letter or number are considered as operands while only the +, -, *, and \ operators are required to be
    * handled as operators. Parentheses are also supported, but you are not required to validate matches.
    *
    * Precondition: The class is initialised. You may assume that input is a valid infix expression.
    * Postcondition: The class has not changed. An exception should be thrown for an unknown symbol or operator.
    */
    std::string convert_to_postfix(std::string& input);

    std::string  infix;    // The infix expression passed to the class
    std::string  postfix;  // The postfix expression, converted from the infix expression
};

#endif
