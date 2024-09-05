/*
* infix_to_postfix_converter.cpp
* Modified : 12/09/2023
*
* This class represents the cpp file for the infix to postfix expression converter.
* This file should be used in conjunction with Assignment 2 for SENG1120.
*/

#include "infix_to_postfix_converter.h"

//This method creates new converter created with variables
infix_to_postfix_converter::infix_to_postfix_converter(std::string& input)
{
    //input is set to infix
    infix = input;
    //postfix is set by converting input
    postfix = convert_to_postfix(infix);
}

//This method acts as a destructor freeing all memory
infix_to_postfix_converter::~infix_to_postfix_converter()
{

}

//This method returns a reference to the string infix expression 
const std::string& infix_to_postfix_converter::get_infix() const
{
    return infix;
}   

//This method returns a references to the string postfix epression
const std::string& infix_to_postfix_converter::get_postfix() const
{
    return postfix;
}

//This method sets operators to precedence values 0 to 4
int infix_to_postfix_converter::precedence(char op) const
{
    //if input char equals ) set precedence to 0
    if (op == ')')
    {
        return 0;
    }
    //if input char equals * or / set precedence to 1
    else if (op == '*' || op == '/')
    {
        return 1;
    }
    //if input char equals + or - set precedence to 2
    else if (op == '+' || op == '-')
    {
        return 2;
    }
    //if input char equals ( set precedence to 4
    else if (op == '(')
    {
        return 4;
    }
    //if input char is not one of the above values throw exception
    throw std::invalid_argument("Invalid operator ");
}

//This method converts the input string, infix, to a postfix expression that is returns
std::string infix_to_postfix_converter::convert_to_postfix(std::string& input)
{
    //Intialises stack and queue as char lists
    LStack<char> operatorsStack;
    LQueue<char> postfixQueue;
    //variable used to host precedence of top item in stack
    int topStack;
    //String used to hold postfix expression to be returned
    std::string postfix;
    //variable used to account for the input strings length, so For Loop loops right amount of times
    int l = input.length();
    //For Loop that goes through entire input string checking all characters in order until entire string has been looped
    for(int i = 0; i < l; i++)
    {
        //variable used to retrieve the current looped char in cycle
        char& inputChar = input[i];
        //Loop checks if inputchar is operand and operator
        //If operand, automatically enqueue item to queue
        if (std::isalnum(inputChar))
        {
            postfixQueue.enqueue(inputChar);
            
        }
        //Loop accounts for spaces in infix expressions, skipping them completely
        else if(input[i] == ' ')
        {
            continue;
        }
        else
        {
            //Sets current character in input to its corresponding precedence
            int inputOp = precedence(inputChar);
            //If input character is ( push it to the stack
            if (inputOp == 4)
            {
                operatorsStack.push(inputChar);
            }
            else if (inputOp == 0)
            {
                //While the operator stack is not empty and the top item is not '(' enqueue the top item from the stack
                while (!operatorsStack.empty() && precedence(operatorsStack.top()) != 4)
                {
                    postfixQueue.enqueue(operatorsStack.pop());
                }
                //Loop accounts for mismatched parentheses
                if (operatorsStack.empty())
                {
                    throw std::invalid_argument("Mismatched parentheses");
                }
                // Pop ( from the stack
                operatorsStack.pop(); 
            }
            //Loop acounts for all all other operands
            else if(inputChar == '*' || inputChar == '/' || inputChar == '+' || inputChar == '-')
            {
                //if Stack is empty, set topStack to 3 so that current input char will be pushed into stack
                if(operatorsStack.empty())
                {
                    topStack = 3;
                }
                //if Stack isn't empty, just set topStack to the top item's precedence
                else
                {
                    topStack = precedence(operatorsStack.top());
                }
                //While stack isn't empty loop through it comparing precedence with current input character
                while (!operatorsStack.empty())
                {
                    topStack = precedence(operatorsStack.top());
                    //if input character has greater precedence then topStack, enqueue topStack
                    if (inputOp >= topStack)
                    {
                        postfixQueue.enqueue(operatorsStack.pop());
                    }
                    //if input character has lesser precedence then topStack, break from loop
                    else
                    {
                        break;
                    }
                }
                //Push the input character to stack
                operatorsStack.push(inputChar);
            }
            //If operator is invalid throw exception
            else
            {
               throw std::invalid_argument("Invalid operator " + inputChar);
            }
        }   
    }
    //Once infix expression is empty, pop the rest of the stack onto the queue
    while (!operatorsStack.empty())
    {
        postfixQueue.enqueue(operatorsStack.pop());
    }
    //Once stack and infix expressions are empty, dequeue postfix queue into postfix string
    while (!postfixQueue.empty())
    {
        postfix += postfixQueue.dequeue();
    }
    //Return postfix string 
    return postfix;
}