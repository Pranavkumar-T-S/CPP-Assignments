#include <iostream>

namespace base
{   // class inside namespace
    class Polynomial
    {
        private:
        int degree;
        int *coefficients;
        public:
        Polynomial(int degree, int *coefficients)
        {
            this->degree = degree;
            this->coefficients = new int[degree];
            for (int i = 0; i <= degree; i++)
            {
                this->coefficients[i] = coefficients[i];
            }
        }

        void printPoly()
        {
            for (int i = 0; i <= degree; i++)
                std::cout << coefficients[i] << "x^" << degree-i << "+";
        std::cout << std::endl;
        }
    };

    namespace math
    {
        int add(int a, int b)
        {
            return a + b;
        }

        int sub(int a, int b)
        {
            return a - b;
        }

        int mul(int a, int b)
        {
            return a * b;
        }

        int div(int a, int b)
        {
            return a / b;
        }

        int factorial(int n)
        {
            int res = 1;
            while (n != 0)
            {
                res = res * n;
                n--;
            }
            return res;
        }
    }
}

namespace version
{
    namespace cpp98
    {
        std::string version()
        {
            return "C++98";
        }
    }
    namespace cpp03
    {
        std::string version()
        {
            return "C++98";
        }
    }
    namespace cpp11
    {
        std::string version()
        {
            return "C++11";
        }
    }
    inline namespace cpp14
    {
        std::string version()
        {
            return "C++14";
        }
    }
    namespace cpp17
    {
        std::string version()
        {
            return "C++17";
        }
    }
}

class Calculator
{
private:
    int a, b;

public:
    Calculator()
    {
        this->a = 0;
        this->b = 0;
    }
    Calculator(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    // Importing function from other namespace by using fully qualified name 

    int add() { return base::math::add(a, b); }

    int add(int x, int y) { return base::math::add(a, b); }

    int sub(int x, int y) { return base::math::sub(a, b); }

    int sub() { return base::math::sub(a, b); }

    int mul(int x, int y) { return base::math::mul(a, b); }

    int mul() { return base::math::mul(a, b); }

    int factorial(int n) { return base::math::factorial(n); }
};

int main()
{

    int x = 4, y = 3 , p[] = {3,2,4,1};
    
    // using methods of class inside namespace
    auto p1 =base::Polynomial(3, p);
    p1.printPoly();
    // using methods of seperated class 
    Calculator c1 = Calculator(x, y);
    std::cout << "Addition of " << x << " and " << y << " gives "<< c1.add() << std::endl;
    std::cout << "Subtraction of " << y << " from " << x << " gives " << c1.sub() << std::endl;
    std::cout << "Factorial of " << x << " is " << c1.factorial(x) << std::endl;

    // Namespace alias
    namespace ns = base::math;
    std::cout << "Factorial of " << y << " is " << ns::factorial(y) << std::endl;

    // inline namespace calling
    std::cout << "Version of compiler: " << version::version() << std::endl;
}
