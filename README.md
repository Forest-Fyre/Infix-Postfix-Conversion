# Infix to Postfix Expression Converter

This project is a C++ implementation that converts infix mathematical expressions (e.g., `A+B`) into postfix notation (e.g., `AB+`). The conversion process utilizes custom linked implementations of **stack** and **queue** data structures, which are essential for evaluating expressions without needing parentheses for operator precedence.

## Features
- **Infix to Postfix Conversion**: Transforms standard infix expressions into postfix format.
- **Custom Data Structures**: Implements linked stack and queue to facilitate expression manipulation.
- **Operator Precedence Handling**: Ensures correct order of operations without parentheses.
- **Makefile Support**: Uses a Makefile for efficient project build and management.

## Getting Started

### Prerequisites

- C++ compiler (e.g., `g++`)
- GNU Make

### Building the Project

To compile the project, navigate to the project directory and run:

make
This will compile the source code and create an executable.

Running the Program
After building, you can run the program using:

./infix_to_postfix
Usage Example
Input an infix expression like:

A + B * C - D
The program will output the equivalent postfix expression:

mathematica
ABC*+D-
