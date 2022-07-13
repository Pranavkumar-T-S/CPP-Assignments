#include <iostream>
#include <exception>

using namespace std;

bool objCreated = false;

class InvalidNameException : public exception
{
public:
    InvalidNameException() : exception() {}

    const char *what()
    {
        return "given input is not a valid name";
    }
};

class InvalidAgeException : public exception
{
public:
    InvalidAgeException() : exception() {}

    const char *what()
    {
        return "given input is not a valid age";
    }
};

class InvalidCourseException : public exception
{
public:
    InvalidCourseException() : exception() {}

    const char *what()
    {
        return "given input is not a valid course name";
    }
};

class AlreadyCreated : public exception
{
public:
    AlreadyCreated() : exception() {}

    const char *what()
    {
        return "Only one object is allowed and an object is already instantiated ";
    }
};

string validCourses[] = {"engineering", "arts", "science", "visualcommunication", "medicine"};
int validCoursesCount = 5;

class Student
{
private:
    int age;
    string rollno, name, course;

public:
    Student(string rollno, string name, int age, string course)
    {
        if (objCreated)
        {
            throw AlreadyCreated();
        }
        objCreated = true;
        if (age > 21 || age < 15)
        {
            throw InvalidAgeException();
        }
        this->age = age;

        for (int i = 0; i < name.length(); i++)
        {
            if (isalpha(name[i]))
                continue;
            else
                throw InvalidNameException();
        }
        this->name = name;
        this->rollno = rollno;
        for (int i = 0; i < validCoursesCount; i++)
        {
            for (int j = 0; course[j]; j++)
                course[j] = course[j] > 64 && course[j] < 91 ? course[j] + 32 : course[j];

            if (validCourses[i] == course)
            {
                this->course = course;
                break;
            }
            else if (i == validCoursesCount - 1)
                throw InvalidCourseException();
        }
    }
};

int main()
{
    try
    {
        Student s1("19D064", "pranavkumar", 20, "Engineering");
        // Student s2("19D060", "pranav", 20, "Science");
    }
    catch (InvalidAgeException &e)
    {
        cout << e.what();
    }
    catch (InvalidCourseException &e)
    {
        cout << e.what();
    }
    catch (InvalidNameException &e)
    {
        cout << e.what();
    }
    catch (AlreadyCreated &e)
    {
        cout << e.what();
    }
    catch (...)
    {
        cout << "unknown error";
    }
}
