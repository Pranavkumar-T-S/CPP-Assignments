#include <iostream>

using namespace std;

enum vehicleType
{
    petrol,
    diesel,
    lpg,
    electric
};
string vt[] = {"petrol", "diesel", "lpg", "electric"};

class Vehicle
{
public:
    int vehicleType;
    string brand;
    string model;
    string color;
    float mileage;
    int price;

    // empty constructor
    Vehicle(){};
    // parameterized constructor
    Vehicle(int vt, string b, string m, string c, float mil, int p)
    {
        vehicleType = vt;
        brand = b;
        model = m;
        color = c;
        mileage = mil;
        price = p;
    }
    // abstract method
    virtual int getNoOfWheels(){return 0 ;}

    // << overloading << in operator in ostream class
    friend ostream &operator<<(ostream &output, const Vehicle &v)
    {
        cout << v.vehicleType << " " << v.brand << " " << v.model << " " << v.color << " " << v.mileage << " " << v.price;
    }
    // overloading < operator
    bool operator<(Vehicle v1)
    {
        return price < v1.price;
    }
    // overloading > operator
    bool operator>(Vehicle v1)
    {
        return price > v1.price;
    }
};

class Bike : public Vehicle
{
public:
    int weight;
    string bikeType;
    // empty constructor
    Bike(){};
    // parameterized constructor
    Bike(int vt, string b, string m, string c, float mil, int p, int w, string bt)
    {
        vehicleType = vt;
        brand = b;
        model = m;
        color = c;
        mileage = mil;
        price = p;
        weight = w;
        bikeType = bt;
    }

    int getNoOfWheels() { return 2; }
};

class Car : public Vehicle
{
public:
    int number_of_persons;
    string carType;
    // empty constructor
    Car(){};
    // parameterized constructor
    Car(int vt, string b, string m, string c, float mil, int p, int nop, string ct)
    {
        vehicleType = vt;
        brand = b;
        model = m;
        color = c;
        mileage = mil;
        price = p;
        number_of_persons = nop;
        carType = ct;
    }
    int getNoOfWheels() { return 4; }
};

int main()
{
    // Instantiating objects
    Bike b1(vehicleType(petrol), "TVS", "pulsar", "black", 60, 100000, 100, "motorbikes");
    Bike b2(vehicleType(petrol), "TVS", "scooty", "violet", 45, 80000, 80, "scooter");
    Car c1(vehicleType(petrol), "Honda", "city", "white", 40, 1400000, 4, "sedan");
    Car c2(vehicleType(diesel), "Tata", "sumo", "white", 30, 2000000, 6, "SUV");

    cout << "no of wheels of bike: " << b1.getNoOfWheels() << endl;
    cout << "no of wheels of car: " << c1.getNoOfWheels() << endl;
    // comparing objects
    if (b1 > b2)
    {
        cout << b1.model << " is greater than " << b2.model << endl;
    }
    else if (b1 < b2)
    {
        cout << b1.model << " is greater than " << b2.model << endl;
    }
    else
        cout << b1.model << " and " << b2.model << "are equal" << endl;

    cout << c1.model << " is " << ((c1 > c2) ? "" : "not ") << "greater than " << c2.model << endl;
    cout << endl;
    cout << c1 << endl;
    cout << b1;
    return 0;
}
