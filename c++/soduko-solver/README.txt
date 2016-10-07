

Originally I wrote this program in Java but found it too verbose and feature lacking. I kept blowing the stack in Java! 
Passing by reference in C++ really helped me to cut down on extra objects/classes to manage. 
I had to change a bit of the design of the solver in the translation but it still works!


This program will attempt to solve a given 9x9 suduku puzzle using backtracking and constraints. 
The contstraints used are the classical game rules (including no same number in either the specified 3x3 grids, the same row, or the same column)


TO RUN THE PROGRAM:

type "make" to build the program
run the .exe named "solver"


OUTPUT

The program will display the solved game board or it will
print "no solution" if there is not a possible way to solve the given puzzle


NOTE / HELP THE PROGRAM IS NOT COMPILING 

If this program does not run, please check the CCFLAGS in the makefile. 
I wrote this program on my home machine and I am confident it will run on the school's system but in the 
case it does not, it is usually my CCFLAGS sets to g++ instead of g++11 or something simple like that - thank you!
