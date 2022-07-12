#include <iostream>

using namespace std;

int main()
{

    // 1) If an exception occurs within outer try block.
    try
    {
        throw "Exception occured within outer try block";
        try
        {
            throw "Exception occured within inside try block";
            cout << "In case of no such notable exceptions" << endl;
        }
        catch (const char *e)
        {
            cout << "Inner catch: " << e << endl;
        }
    }
    catch (const char *e)
    {
        cout << "Outer catch: " << e << endl;
    }

    // 2) If an exception occurs inside try block.
    try
    {
        // throw "Exception occurs within outer try block";
        try
        {
            throw "Exception occured within inside try block";
            cout << "In case of no such notable exceptions" << endl;
        }
        catch (const char *e)
        {
            cout << "Inner catch: " << e << endl;
        }
    }
    catch (const char *e)
    {
        cout << "Outer catch: " << e << endl;
    }

    // 3) In case of no such notable exceptions.
    try
    {
        // throw "Exception occured within outer try block";
        try
        {
            // throw "Exception occured within inside try block";
            cout << "In case of no such notable exceptions." << endl;
        }
        catch (const char *e)
        {
            cout << "Inner catch: " << e << endl;
        }
    }
    catch (const char *e)
    {
        cout << "Outer catch: " << e << endl;
    }

    // 4) To re-throw an exception already catched.
    try
    {
        // throw "Exception occured within outer try block";
        try
        {
            throw "Re-throwing exception already catched";
            cout << "In case of no such notable exceptions." << endl;
        }
        catch (const char *e)
        {
            // rethrowing the exception
            throw e;
            cout << "Inner catch: " << e << endl;
        }
    }
    catch (const char *e)
    {
        cout << "Outer catch: " << e << endl;
    }

    return 0;
}
