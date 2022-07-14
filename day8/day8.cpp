#include <iostream>
#include <vector>

using namespace std;

// defining class for mobile connection
class mobileConnection
{
private:
    string phoneNumber;
    int billDue;

public:
    // empty constructor
    mobileConnection()
    {
        cout << "Enter the phone number: ";
        cin >> this->phoneNumber;
        cout << "Enter the bill due amount: ";
        cin >> this->billDue;
    }
    // parameterized constructor
    mobileConnection(string pn, int billDue)
    {
        this->phoneNumber = pn;
        this->billDue = billDue;
    }

    void payBill()
    {
        this->billDue = 0;
    }

    void updateBill(int amount)
    {
        this->billDue += amount;
    }

    bool checkNumber(string number)
    {
        return this->phoneNumber == number;
    }

    void printInfo()
    {
        cout << endl
             << "Connection Details" << endl;
        cout << "PhoneNumber number : " << this->phoneNumber << endl;
        cout << "Bill Amount Due : " << this->billDue << endl;
    }
};

class landlineConnection
{
private:
    string landlineNumber;
    string stdCode;
    int billDue;

public:
    // empty constructor
    landlineConnection()
    {
        cout << "Enter the STD code: ";
        cin >> this->stdCode;
        cout << "Enter the landline number: ";
        cin >> this->landlineNumber;
        cout << "Enter the bill due amount: ";
        cin >> this->billDue;
    }
    // parameterizzed constructor
    landlineConnection(string lln, string stdCode, int billDue)
    {
        this->landlineNumber = lln;
        this->stdCode = stdCode;
        this->billDue = billDue;
    }

    void payBill()
    {
        this->billDue = 0;
    }

    void updateBill(int amount)
    {
        this->billDue += amount;
    }

    bool checkNumber(string number)
    {
        string std = number.substr(0, number.size() - 6);
        string lln = number.substr(number.size() - 6, 6);
        return this->stdCode == std && this->landlineNumber == lln;
    }

    void printInfo()
    {
        cout << endl;
        cout << "Connection Details" << endl;
        cout << "STD code : " << this->stdCode << endl;
        cout << "Landline number : " << this->landlineNumber << endl;
        cout << "Bill Amount Due : " << this->billDue << endl;
    }
};
// Administrator class to manage mobile and landline connections
template <class T>
class Admin
{
    vector<T> connections;

public:
    // empty constructor
    Admin()
    {
        this->connections = vector<T>();
    }

    void addConnection()
    {
        T newConnection = T();
        this->connections.push_back(newConnection);
    }

    T &findConnection(string number)
    {
        for (int i = 0; i < this->connections.size(); i++)
        {
            if (this->connections[i].checkNumber(number))
            {
                return this->connections[i];
            }
            else if (i == this->connections.size() - 1)
            {
                throw "Wrong number";
            }
        }
        throw "No entries";
    }

    void payBill(string number)
    {
        T &connection = this->findConnection(number);
        connection.payBill();
        cout << "bill paid";
    }

    void billUpdate(string number, int newBill)
    {
        T &connection = this->findConnection(number);
        connection.updateBill(newBill);
        cout << "bill updated";
    }

    void printInfo(string number)
    {
        T &connection = this->findConnection(number);
        connection.printInfo();
    }
};
// To print availablle options in menu
void menu()
{
    cout << endl;
    cout << "#################################################################" << endl;
    cout << "Enter number for any one of the following options:" << endl;
    cout << "1) Add a new mobile connection." << endl;
    cout << "2) Add a new landline connection." << endl;
    cout << "3) Pay bill using the connection number." << endl;
    cout << "4) Update bill amount using the connection number." << endl;
    cout << "5) Print the information about connection using connection number" << endl;
    cout << "6) Quit" << endl;
}

int main()
{
    Admin<mobileConnection> a1 = Admin<mobileConnection>();
    Admin<landlineConnection> a2 = Admin<landlineConnection>();
    int option, newBill;
    string stdCode, landlineNumber, mobileNumber;
    bool flag = true;
    while (flag)
    {
        menu();
        try
        {
            cin >> option;
            switch (option)
            {
            case 1:
                a1.addConnection();
                break;

            case 2:
                a2.addConnection();
                break;

            case 3:
                cout << "Press 1 for mobile connection / 2 for landline connection" << endl;
                cin >> option;
                switch (option)
                {
                case 1:
                    cout << "Enter mobile Number: " << endl;
                    cin >> mobileNumber;
                    a1.payBill(mobileNumber);
                    break;
                case 2:
                    cout << "Enter landline Number along with STD code: " << endl;
                    cin >> landlineNumber;
                    a2.payBill(landlineNumber);
                    break;
                default:
                    cout << "Invalid Option" << endl;
                }
                break;

            case 4:
                cout << "Press 1 for mobile connection / 2 for landline connection" << endl;
                cin >> option;
                switch (option)
                {
                case 1:
                    cout << "Enter mobile Number: " << endl;
                    cin >> mobileNumber;
                    cout << " Enter new bill amount : " << endl;
                    cin >> newBill;
                    a1.billUpdate(mobileNumber, newBill);
                    break;
                case 2:
                    cout << "Enter landline Number along with STD code: " << endl;
                    cin >> landlineNumber;
                    cout << " Enter new bill amount : " << endl;
                    cin >> newBill;
                    a2.billUpdate(landlineNumber, newBill);
                    break;
                default:
                    cout << "Invalid Option" << endl;
                }
                break;

            case 5:
                cout << "Press 1 for mobile connection / 2 for landline connection" << endl;
                cin >> option;
                switch (option)
                {
                case 1:
                    cout << "Enter mobile Number: ";
                    cin >> mobileNumber;
                    a1.printInfo(mobileNumber);
                    break;
                case 2:
                    cout << "Enter landline Number along with STD code: ";
                    cin >> landlineNumber;
                    a2.printInfo(landlineNumber);
                    break;
                default:
                    cout << "Invalid Option" << endl;
                }
                break;

            case 6:
                flag = false;
                break;

            default:
                cout << "Invalid Option" << endl;
                break;
            }
        }
        catch (const char *e)
        {
            cout << e << endl;
        }
    }
}