#include <iostream>
#include <sstream>
#include <vector>

using namespace std;
// Enumeration for bank types and string array for decoding
enum BankType
{
    PRIVATE,
    PUBLIC
};

string banktypes_list[] = {"private", "public"};

// Enumeration for loan types and string array for decoding
enum loanType
{
    goldloan,
    landloan,
    personalloan
};

string loantypes_list[] = {"goldloan", "landloan", "personalloan"};

// Date structure to store date
struct date
{
    int day;
    int month;
    int year;
};

// TO convert date from string to date structure
struct date data_struct(string date_s)
{
    struct date *d1 = new date;
    d1->day = stoi(date_s.substr(0, 2));
    d1->month = stoi(date_s.substr(3, 2));
    d1->year = stoi(date_s.substr(6, 4));
    return *d1;
}

// Bank class contains information about banks
class Bank
{
protected:
    string name;
    date establishedDate;
    BankType banktype;
    string branchname;

public:
    // empty constructor
    Bank(){}
    //parameterized constructor
    Bank(string nm, string ed, BankType bt, string bnm)
    {
        name = nm;
        establishedDate = data_struct(ed);
        banktype = bt;
        branchname = bnm;
    }
    // public functions to get information of object

    string getName()
    {
        return name;
    }

    string getEstablisedDate()
    {
        ostringstream str1;
        str1 << establishedDate.day << '-' << establishedDate.month << '-' << establishedDate.year;
        return str1.str();
    }

    BankType getBankType()
    {
        return banktype;
    }

    virtual string getInfo()
    {
        ostringstream str1;
        str1 << "Name: " << name
             << "\n Established Date: " << getEstablisedDate()
             << "\n Bank Type: " << banktypes_list[banktype]
             << "\n Branch Name: " << branchname;
        return str1.str();
    }
    string getBranchName()
    {
        return branchname;
    }

};
// Loan class contains information about Loan 
class Loan
{
protected:
    vector<loanType> availableloans;
    float interestRate;
    vector<string> documentsReqForLoan;

public:
    Loan() {}
    Loan(vector<loanType> alt, float ir,vector<string> docsReq) { 
        availableloans = alt;
        interestRate = ir;
        documentsReqForLoan = docsReq;
    }

    string getAvailableLoans()
    {
        string res = " Available loans : ";
        for (int al : availableloans)
        {
            res = res + loantypes_list[al] + ", " ;
        }
        return res;
    }

    float getInterestRate()
    {
        return interestRate;
    }

    string getDocumentsRequiredForLoan()
    {
        string str1 = "";
        for (string doc : documentsReqForLoan)
        {
            str1 = str1 + doc + ", ";
        }
        return str1;
    }



};
// classes for banks
class HDFC : public Bank, public Loan{
    private:
        string id;

    public:
    HDFC(string bn, float ir, string id) : 
        Bank("HDFC", "01-06-1950", PRIVATE, bn), 
        Loan(vector<loanType>({goldloan, personalloan}), ir, vector<string>({"aadhar", "pan card"})){
            this->id = id;            
    }
    // overriding getInfo method
    string getInfo(){
        ostringstream str1;
        str1 << "Hello, Information about HDFC is listed below" 
             << "\n Name: " << name
             << "\n Established Date: " << getEstablisedDate()
             << "\n Bank Type: " << banktypes_list[banktype]
             << "\n Branch Name: " << branchname
             << "\n Id: " << id
             << "\n Interest rate: " << getInterestRate() << endl
             << getAvailableLoans()
             << "\n Required Documents: " << getDocumentsRequiredForLoan();
        return str1.str();
    }

};

class SBI : public Bank, public Loan{
    private:
        string id;

    public:
    SBI(string bn, float ir, string id) : 
        Bank("SBI", "01-01-1900", PUBLIC, bn), 
        Loan(vector<loanType>({goldloan, personalloan}), ir, vector<string>({"aadhar", "pan card"})){
            this->id = id; }

    // overriding getInfo method
    string getInfo(){
        ostringstream str1;
        str1 << "Greeting from SBI bank" 
             << "\n Name: " << name
             << "\n Established Date: " << getEstablisedDate()
             << "\n Bank Type: " << banktypes_list[banktype]
             << "\n Branch Name: " << branchname
             << "\n Id: " << id
             << "\n Interest rate: " << getInterestRate() << endl
             << getAvailableLoans()
             << "\n Required Documents: " << getDocumentsRequiredForLoan();
        return str1.str();
    }
        

};

class ICICI : public Bank, public Loan{
    private:
        string customerNumber;
        string customerType;

    public:
    ICICI(string bn, float ir, string ct, string cn) : 
        Bank("ICICI", "01-04-1970", PRIVATE, bn), 
        Loan(vector<loanType>({personalloan}), ir, vector<string>({"aadhar card", "collateral", "pan card"})){
            this->customerNumber = cn;
            this-> customerType = ct; }

    // overriding getInfo method
    string getInfo(){
        ostringstream str1;
        str1 << "Welcome to ICICI bank, Particulars are listed below" 
             << "\n Name: " << name
             << "\n Established Date: " << getEstablisedDate()
             << "\n Bank Type: " << banktypes_list[banktype]
             << "\n Customer Type: " << customerType
             << "\n Customer Number: " << customerNumber
             << "\n Branch Name: " << branchname
             << "\n Interest rate: " << getInterestRate() << endl
             << getAvailableLoans()
             << "\n Required Documents: " << getDocumentsRequiredForLoan();
        return str1.str();
    }
        

};

class IndianBank : public Bank, public Loan{
    private:
        string customerNumber;

    public:
    IndianBank(string bn, float ir, int cn) : 
        Bank("Indian Bank", "01-04-1870", PUBLIC, bn), 
        Loan(vector<loanType>({personalloan}), ir, vector<string>({"aadhar card", "collateral", "pan card"})){
            this->customerNumber = cn; }
    
    // overriding getInfo method
    string getInfo(){
        ostringstream str1;
        str1 << "Welcome to ICICI bank, Particulars are listed below" 
             << "\n Name: " << name
             << "\n Established Date: " << getEstablisedDate()
             << "\n Bank Type: " << banktypes_list[banktype]
             << "\n Customer Number: " << customerNumber
             << "\n Branch Name: " << branchname
             << "\n Interest rate: " << getInterestRate() << endl
             << getAvailableLoans()
             << "\n Required Documents: " << getDocumentsRequiredForLoan();
        return str1.str();
    }
     


};

// broker class to compare banks
class Broker{
    public:
    Loan compare(Loan l1, Loan l2){
        return l1.getInterestRate()<l2.getInterestRate()?l1:l2;
    }

    Loan compare(Loan l1, Loan l2, Loan l3){
        float i1 = l1.getInterestRate();
        float i2 = l2.getInterestRate();
        float i3 = l3.getInterestRate();
        if(i1<=i2 && i1<=i3) return l1;
        if(i2<=i1 && i2<=i3) return l2;
        if(i3<=i2 && i3<=i1) return l3;
        else cout << "error";
    }

    int compare(Loan l[], int n){
        int min = 0;
        for(int i=0; i< n ;i++){
            min = l[min].getInterestRate()>l[i].getInterestRate()? i : min;
        }
        return min;
    }

};

int main(){
    // creating bank and loan objects
    Bank b1("SBI", "01-01-1900", PUBLIC, "Potheri");
    vector<loanType> avail_lt({goldloan, landloan});
    vector<string> doc_req({"aadharcard", "pancard", "incomecertificate"});
    Loan l1(avail_lt , 6.5, doc_req);
    cout << b1.getInfo() << endl;

    // creating objects for different bank classes and getting its info
    HDFC h1("Guduvancheri", 15, "HDFC00103242");
    cout << h1.getInfo()<< endl << endl;

    IndianBank i1("Tambaram", 8, 54125674);
    cout << i1.getInfo() << endl << endl;

    SBI s1("Guindy", 10, "TNCHG478512");
    cout << s1.getInfo()<< endl << endl;

    ICICI ic1("South Gate", 12, "Student", "MDUSG14527851");
    cout << ic1.getInfo()<< endl << endl;

    // creating broker object
    Broker brk1 = Broker();
     
    // comparing objects using broker object 
    cout << "Among " << s1.getName() << " and " << i1.getName() 
     << " least interest rate is " << brk1.compare(s1,i1).getInterestRate() << endl;

    cout << "Among " << s1.getName() << ", " << i1.getName() << " and " << ic1.getName() 
     << " least interest rate is " << brk1.compare(s1,i1,ic1).getInterestRate() << endl;


    Loan l[] = {s1,i1,ic1,h1};
    string names[] = {s1.getName(), i1.getName(), ic1.getName(), h1.getName()};
    int n = sizeof(l)/sizeof(l[0]);
    
    cout << "Among " ;
    for(int i=0; i<n;i++){cout << names[i] << " ,";}
    cout << names[brk1.compare(l,n)] << " has the minimum interest rate"; 
    

    return 0;

}
