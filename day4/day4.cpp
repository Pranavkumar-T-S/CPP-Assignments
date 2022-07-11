#include <iostream>

using namespace std;

// Declaring Rectangle class
class Rectangle
{
    int *left, *top, *width, *height, *area;

public:
    // Empty constructor
    Rectangle()
    {
        this->left = new int(0);
        this->top = new int(0);
        this->width = new int(0);
        this->height = new int(0);
        this->area = new int((*this->width) * (*this->height));
    }
    // Parameterized constructor with 2 variables
    Rectangle(int width, int height)
    {
        this->left = new int(0);
        this->top = new int(0);
        this->width = new int(width);
        this->height = new int(height);
        this->area = new int((*this->width) * (*this->height));
    }

    // Parameterized constructor with 4 variables
    Rectangle(int width, int height, int left, int top)
    {

        this->width = new int(width);
        this->height = new int(height);
        this->left = new int(left);
        this->top = new int(top);
        this->area = new int((*this->width) * (*this->height));
    }

    Rectangle(float width, float height, float left, float top)
    {
        this->width = (new int((int)width));
        this->height = new int((int)height);
        this->left = new int((int)left);
        this->top = new int((int)top);
        this->area = new int((*this->width) * (*this->height));
    }

    Rectangle(const Rectangle &r)
    {
        this->width = new int(*(r.width));
        this->height = new int(*(r.height));
        this->left = new int(*(r.left));
        this->top = new int(*(r.top));
        this->area = new int((*this->width) * (*this->height));
        *r.area = *r.width * *r.height;
    }

    ~Rectangle()
    {
        delete left, top, height, width, area;
        cout << " deleting data members" << endl;
    }

    void printInfo()
    {
        cout << endl << "Information about the Rectangle object" << endl;
        cout << "Width: " << *this->width << endl;
        cout << "Height: " << *this->height << endl;
        cout << "Left: " << *this->left << endl;
        cout << "Top: " << *this->top << endl;
        cout << "Area: " << *this->area << endl;
    }

};

int main()
{
    Rectangle r1, r2(3, 2), r3(1, 1, 3, 3), r4(1.2f,1.9f,4.1f,4.2f), r5(r2);
    r1.printInfo();
    r2.printInfo();
    r3.printInfo();
    r4.printInfo();
    r5.printInfo();

    return 0;
}