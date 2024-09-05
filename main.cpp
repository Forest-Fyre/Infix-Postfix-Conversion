/*
* main.cpp
* Modified : 25/08/2023
*
* This class represents the main driver for an infix to postfix conversion program.
* This file should be used in conjunction with Assignment 2 for SENG1120.
*/


#include <iostream>
#include "infix_to_postfix_converter.h"

/*
* Present the user with a prompt, returning the user's input
*/
std::string prompt()
{
    std::string input;
    std::cout << "Enter a string: ";
    //read entire line from cin, not just next token
    std::getline(std::cin, input);

    return input;
}

int main() 
{
    do
    {
        std::string input = prompt();
        if(input == "quit")
        {
            break;
        }

        try
        {
            infix_to_postfix_converter converter(input);
            std::cout << "\tThe infix expression: " << converter.get_infix() << std::endl;
            std::cout << "\tThe postfix expression: " << converter.get_postfix() << std::endl;
        }
        catch (std::exception& e)
        {
            std::cout << "Exception thrown: " << e.what() << std::endl;
        }

    } while(true);

    std::cout << "Goodbye!" << std::endl;

    return 0;
}
