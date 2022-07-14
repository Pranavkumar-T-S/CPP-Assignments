# Day 8 :
## Topic:
* Templates
## Assignment:
    Consider Zoho provides telecommunication services like landline and mobile. You are to program a common billing system using generic templates for these services. 
1. Create a class for mobile connection. Each mobile connection should have a ten digit mobile number and a bill amount to be paid. 
2. Create a class for landline connection. Each landline connection should have a six digit landline number, STD code and a bill amount to be paid. 
3. Create a class with template to process bill payments. The class should do the following:
    1. Store all connections (for any particular service). 

    2. A function to pay bills using the connection 
    number. The function should update the bill due amount to zero for the particular connection. This function should call a function with same name in mobile and landline to find the connection using the number (to demonstrate templates). For mobile, match the user input with the ten digit mobile number. For landline, user will input STD code and the six digit number together. You will have to separate them and find the corresponding connection.
    
    3. A function to update new due bill amount using the connection number. If there is already amount due for a particular connection, the new amount should get added. This function should also call the common functions

    You have to provide the user with the following options:
    1. Add a new mobile connection.
    2. Add a new landline connection.
    3. Pay bill using the connection number.
    4. Update bill amount using the connection number.