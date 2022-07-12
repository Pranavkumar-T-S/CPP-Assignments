#include <iostream>
#include <exception>
using namespace std;

// User defined exception class 
class MyException : public exception
{
    string param, message;

public:
    MyException(string param, string message) : exception()
    {
        this->param = param;
        this->message = message;
    }
    string what()
    {
        return param;
    }
    string getMessage()
    {
        return message;
    }
};

// functions perform operation and throws exception if required
float division(float num, float den)
{
    if (den == 0)
        throw MyException("Division by zero", "Invalid division");
    else
        return num / den;
}

char charAt(string str, int index)
{
    if (index < 0 || index > str.length() - 1)
        throw MyException("Accessing an invalid index in string", "Index is invalid");
    else
        str[index];
}

void *allocMemory(long size)
{
    void *ptr = new (nothrow) char[size];
    if (ptr)
        return ptr;
    else
        throw MyException("Creation of heap memory variable", "Memory is compromised!");
}

int parseInt(string a)
{
    for (int i = 0; i < a.length(); i++)
    {
        if (isdigit(a[i]))
        {
            continue;
        }
        else
            throw MyException("String parsed to a numeric variable", "String parsed to a numeric variable");
        return stoi(a);
    }
}

template <class T>
T elemAt(T *arr, int n, int index)
{
    for (int i = 0; i < n; i++)
    {
        if (i == index)
            return arr[i];
    }
    throw MyException("Accessing an invalid index in array", "Array index is invalid");
}

int main()
{
    float a = 4, b = 0;
    int arr[] = {1, 2, 3, 4, 5, 6, 7, 9, 10};
    long memorySize = 0xffffffff;
    string s = "990";
    try
    {
        // uncomment the code to get required exception
        division(a,b);
        // allocMemory(memorySize);
        // cout << parseInt("0x123");
        // cout << charAt(s, 4);
        // cout << elemAt(arr, 10, 10);
        // throw "Exception other than mentioned";
    }
    catch (MyException &e)
    {
        cout << "MyException[" << e.what() << "] : " << e.getMessage() << endl;
    }
    catch (...)
    {
        cout << "Exception encountered" << endl;
    }

    cout << "Exception Handling Accomplished";
}