# Day 6 :
## Topic:
* Exception handling
## Assignment:
1. The exceptions the code may throw along with the handler message are listed below:
 	* Division by zero: Print "Invalid division".                                                                        
    * Creation of heap memory variable: If the computer is unable to allocate the memory for computation, Print 'Memory is compromised!'
    * String parsed to a numeric variable : Print "Format mismatch".
    * Accessing an invalid index in string : Print "Index is invalid".
    * Accessing an invalid index in array : Print "Array index is invalid".   
 * MyException (user defined exception) : This is a user defined Exception which you need to create. It takes a parameter. When an exception of this class is encountered, the handler should print "MyException[param]", here is the parameter passed to the exception class.  
* Exceptions other than mentioned above : Any other exception except the above ones fall in this category. Print "Exception encountered".  
Finally, after the exception is handled, print "Exception Handling Accomplished".

NOTE: To obtain array values, string and index (to be searched for in the string) as input and perform division operations ,etc to handle exceptions respectively.

2. Cases to be implement (another prog)
    * If an exception occurs within outer try block.
    * If an exception occurs inside inner try block.
    * In case of no such notable exceptions.
    * To re-throw an exception already catched.


3. Use case based question 1

    Create a class Student with members roll no, name, age and course. Initialize values through parameterized constructor.If age of student is not in between 15 and 21 then generate user-defined exception "AgeNotWithinRangeException". If name contains numbers or special symbols raise exception "NameNotValidException". The course must fall under a predefined list of available courses (not case sensitive), if not  "InvalidCouseException" must be raised. Define the 3 exception classes. The user can only create one object. If user attempts to create more than one object for Student class, th