# Day 4 :
## Topic:
* Constructor
* Destructor
## Assignment:

Design a class named Rectangle with members left, top, width, height with int* datatype. 

1.  Create a default constructor which initializes all the values with zero. 

    All Parameters in a parameterized constructor will have non pointer data type (eg. int, float etc..)
2.  Create a parameterized constructor with parameters width, height. where left, top will be initialized with zero.
3.  Create another parameterized constructor with all values as parameters.
4.  Create another parameterized constructor with all values as parameters with float data type. Float data type should be rounded off to nearest int value and set. (1.6 will be rounded to 2 && 1.3 will be rounded to 1).
5.  Write a copy constructor that will copy all the values from one obj to other.
6.  Above class will have another member variable named area with int* data type. where area will be set once the variable is copied to another. (Have to find the area and set It in copy constructor).
7.  Create a destructor, which frees the memory.
8.  Write a function to print the rect values.

Program should exit without memory leaks.