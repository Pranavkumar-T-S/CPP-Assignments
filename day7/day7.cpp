#include <bits/stdc++.h>
#include <functional>
#include <map>
#include <vector>

using namespace std;

// base class for all sensors
class sensor
{
    bool isConnected;
    int value;
    vector<std::function<void(int)>> actions;

public:
    sensor(bool availablity, int value)
    {
        this->isConnected = availablity;
        this->value = value;
    }

    virtual void onConnect()
    {
        this->isConnected = true;
    }

    virtual void onDisconnect()
    {
        this->isConnected = false;
    }

    void onChange()
    {
        for (int i = 0; i < actions.size(); i++)
        {
            actions[i](this->value);
        }
    }

    virtual void increaseValue()
    {
        if (isConnected)
        {
            this->value++;
            this->onChange();
        }
        else
            cout << "Sensor not connected";
    }

    void virtual decreaseValue()
    {
        if (isConnected)
        {
            this->value--;
            this->onChange();
        }
        else
            cout << "Sensor not connected";
    }

    virtual void setValue(int val)
    {
        if (isConnected)
        {
            this->value = val;
            this->onChange();
        }
        else
            cout << "Sensor not connected";
    }

    virtual void addAction(function<void(int)> a)
    {
        actions.push_back(a);
    }

    virtual int getValue()
    {
        return this->value;
    }

    virtual bool isAvailable()
    {
        return this->isConnected;
    }
};

// base class for all devices/actuators
class device
{
private:
    bool isConnected;
    bool status;
    map<string, bool> states;

public:
    device(bool isConnected, bool status, map<string, bool> states)
    {
        this->isConnected = isConnected;
        this->status = status;
        this->states = states;
    }

    virtual void onConnect()
    {
        this->isConnected = true;
    }

    virtual void onDisconnect()
    {
        this->isConnected = false;
    }

    virtual void setState(string state)
    {
        if (this->isConnected)
        {
            if (this->states.find(state) == this->states.end())
                throw "Invalid function for device";
            this->status = this->states[state];
        }
        else
            cout << "device not connected" << endl;
    }

    virtual bool isAvailable()
    {
        return this->isConnected;
    }

    virtual bool getState()
    {
        return this->status;
    }
};

// classes for different sensors which are all inherited from sensor class

class temperatureSensor : public sensor
{
public:
    temperatureSensor(bool availability, int temp) : sensor(availability, temp){};
};

class motionSensor : public sensor
{
public:
    motionSensor(bool availability, int motionRate) : sensor(availability, motionRate){};
};

class waterLevelSensor : public sensor
{
public:
    waterLevelSensor(bool availability, int waterLevel) : sensor(availability, waterLevel){};
};

class gasLevelSensor : public sensor
{
public:
    gasLevelSensor(bool availability, int gasLevel) : sensor(availability, gasLevel){};
};

// class for all devices/ acutators which are all inherited from device class

class fan : public device
{
public:
    fan(bool availability, bool status, map<string, bool> states) : device(availability, status, states){};
};

class light : public device
{
public:
    light(bool availability, bool status, map<string, bool> states) : device(availability, status, states){};
};

class door : public device
{
public:
    door(bool availability, bool status, map<string, bool> states) : device(availability, status, states){};
};

class waterPump : public device
{
public:
    waterPump(bool availability, bool status, map<string, bool> states) : device(availability, status, states){};
};

string toLowerCase(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = tolower(str[i]);
    }
    return str;
}
string toUpperCase(string str)
{
    for (int i = 0; i < str.length(); i++)
    {
        str[i] = toupper(str[i]);
    }
    return str;
}

// to check condition based on type of condition
bool checkCond(int value, string cond, int sensorValue)
{
    if (cond == "<")
    {
        return value < sensorValue;
    }
    else if (cond == "=")
    {
        return value == sensorValue;
    }
    else if (cond == ">")
    {
        return value > sensorValue;
    }
    else
    {
        throw "Invalid conditional symbol";
    }
}
// to add automation events for sensors
void addAutomationtask(map<string, sensor *> sMap, map<string, device *> dMap)
{
    string sensorName, cond, deviceName, function;
    int sensorValue;
    cout << endl;
    cout << "Syntax:" << endl;
    cout << "If: <sensor_name> <comparison> <sensor_value>" << endl;
    cout << "Then: <device> <function>" << endl;
    cout << "Enter input as shown in the syntax." << endl;
    cout << "If: ";
    cin >> sensorName;
    sensorName = toLowerCase(sensorName);
    cout << " ";
    cin >> cond;
    cout << " ";
    cin >> sensorValue;
    cout << endl
         << "Then: ";
    cin >> deviceName;
    deviceName = toLowerCase(deviceName);
    cout << " ";
    cin >> function;
    function = toUpperCase(function);
    if (dMap.find(deviceName) == dMap.end() || sMap.find(sensorName) == sMap.end())
        throw "invalid sensor/device name";

    device *d = dMap[deviceName];
    sensor *s = sMap[sensorName];
    auto a = [cond, sensorValue, d, function](int value) -> void
    {
        if ((*d).isAvailable() && checkCond(value, cond, sensorValue))
        {
            (*d).setState(function);
        }
    };

    (*s).addAction(a);
}

void printStatus(map<string, sensor *> sMap, map<string, device *> dMap)
{
    cout << endl;
    cout << "SENSORS	        STATUS " << endl;
    cout << "______________________" << endl;
    for (auto &pair : sMap)
    {
        if (pair.second->isAvailable())
        {
            cout << pair.first << "		 " << pair.second->getValue() << endl;
        }
        else
        {
            cout << pair.first << "		 "
                 << "OFFLINE" << endl;
        }
    }
    cout << endl;
    cout << "DEVICES	        STATUS " << endl;
    cout << "______________________" << endl;
    for (auto &pair : dMap)
    {
        if (pair.second->isAvailable())
        {
            cout << pair.first << "		   " << (pair.second->getState() ? "ON" : "OFF") << endl;
        }
        else
        {
            cout << pair.first << "		 "
                 << "OFFLINE" << endl;
        }
    }
}
// to print main menu
void printMenu()
{
    cout << endl;
    cout << "Enter any one of the following option" << endl;
    cout << "1) Print Status" << endl;
    cout << "2) Simulate Input " << endl;
    cout << "3) Device Automation" << endl;
    cout << "4) Exit" << endl;
}

// to print simulation menu
void simulateInputMenu()
{
    cout << endl;
    cout << "Enter any one of the option: " << endl;
    cout << "1. Increase Value" << endl;
    cout << "2. Decrease Value" << endl;
    cout << "3. Set Value" << endl;
    cout << "4. Connect Device" << endl;
    cout << "5. Disconnect Device" << endl;
}

int main()
{

    map<string, bool> states1;
    states1.insert(pair<string, bool>("ON", true));
    states1.insert(pair<string, bool>("OFF", false));

    map<string, device *> dMap;
    fan f1(true, false, states1);
    dMap.insert(pair<string, device *>("fan", &f1));
    light l1(true, false, states1);
    dMap.insert(pair<string, device *>("light", &l1));
    door d1(true, false, states1);
    dMap.insert(pair<string, device *>("door", &d1));
    waterPump p1(true, false, states1);
    dMap.insert(pair<string, device *>("waterpump", &p1));

    map<string, sensor *> sMap;
    temperatureSensor t1(true, 30);
    sMap.insert(pair<string, sensor *>("temperature", &t1));
    motionSensor m1(true, 10);
    sMap.insert(pair<string, sensor *>("motion", &m1));
    waterLevelSensor w1(true, 50);
    sMap.insert(pair<string, sensor *>("waterlvl", &w1));
    gasLevelSensor g1(true, 30);
    sMap.insert(pair<string, sensor *>("gaslvl", &g1));

    bool flag = true;
    int option, val;
    string name;

    while (flag)
    {
        try
        {
            printMenu();
            cin >> option;
            switch (option)
            {
            case 1:
                printStatus(sMap, dMap);
                break;

            case 2:
                cout << "enter sensor name" << endl;
                cin >> name;
                name = toLowerCase(name);

                for (auto &pair : sMap)
                {
                    if (pair.first == name)
                    {
                        simulateInputMenu();
                        cin >> option;
                        switch (option)
                        {
                        case 1:
                            pair.second->increaseValue();
                            break;
                        case 2:
                            pair.second->decreaseValue();
                            break;
                        case 3:
                            cout << "Enter the value";
                            cin >> val;
                            pair.second->setValue(val);
                            break;
                        case 4:
                            pair.second->onConnect();
                            break;
                        case 5:
                            pair.second->onDisconnect();
                            break;
                        default:
                            cout << "Invalid Option" << endl;
                        }
                        break;
                    }
                }
                break;

            case 3:
                addAutomationtask(sMap, dMap);
                break;

            case 4:
                flag = false;
                cout << " Exiting from client application";
                break;
            default:
                cout << "Invalid Option";
            }
        }
        catch (...)
        {
            cout << "error" << endl;
        }
    }
}
