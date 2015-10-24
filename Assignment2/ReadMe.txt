Program Name: A Complex Number Calculator
Author: Siren Chen
Files: main.cpp ComplexNumber.cpp ComplexNumber.h

Complier: g++ 4.9.2
Environment: Ubuntu 14.04

Description and Performance
This program will performs complex number arithmetic which include
adding, subtraction, multiplication, and division. This program wi
-ll read a command line of user input and then perform those arith
-metic. 
The first component in the line is:
A — addition
S - subtraction
M - multiplication
D - division

Assignment_2 ADD==================================================
ABS - Returns the magnitude of the given complex number
ARG - Returns the angle part of the given complex number, in radians
ARGDEG - Returns the argument of the given complex number, in degrees
EXP - For the given complex number, z, calculate the exponential of
      that number,exp(z)
INV - Return the reciprocal of the given complex number

The lower case characters are also work.

This program will work in two mode:
  1. Interactive mode
  2. Batch mode
If run the program at the command line without arguments, like:
  $ ./assignment1
It will use the keyboard and the screen as the input and output. 

If run the program with command line, like:
  $ ./assignment1 <data.txt> output.txt
It will read from data.txt and write to output.txt

Also, this program is support standard exponential notation.