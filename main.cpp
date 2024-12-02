#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <conio.h>


using namespace std;
using json = nlohmann::json;


class Custumer {
    private:
        Component_data component_data;
        Customer_Data customer_data;
        Component_data smoke_detector[2];
        Component_data breaker[10];
    
    public:
    Customer_Data retrieveCustomerData() {
        return customer_data;
    }
    
    void writeCustomerData(Customer_Data customer_data) {
        this->customer_data = customer_data;
    }
    Component_data retrieveComponentData() {
        return component_data;
    }
    void writeComponentData(Component_data component_data) {
        this->component_data = component_data;
    }
    void printCustomer_and_components() {
        cout << "Customer Data: " << customer_data.getName() << endl;
        cout << "Component Data: " << component_data.getName() << endl;
    }
};


class Customer_Data {
    private:
        string ID;
        string name;
        string adress;
        string PIN;
        string tag_ID;
        string verification_phrase;
    public:
    Customer_Data(string name, int adress) {
            this->ID = ID;
            this->name = name;
            this->adress = adress;
            this->PIN = PIN;
            this->tag_ID = tag_ID;
            this->verification_phrase = verification_phrase;

    }
    void setID(string ID) {
            cout << name;
        }
    string getID() {
            cout << ID;
        }
    void setName (string name) {
            cout << name;
        }
    string getName() {
            return name;
        }
    void setAdress(string adress) {
            cout << adress;
        }
    string getAdress() {
            cout << adress;
        }
    void setPIN(string PIN) {
            cout << PIN;
        }
    string getPIN() {
            cout << PIN;
        }
    void setTagID(string tag_ID) {
            cout << tag_ID;
        }
    string getTagID() {
            cout << tag_ID;
        }
    void setVerificationPhrase(string verification_phrase) {
            cout << verification_phrase;
        }
    string getVerificationPhrase() {
            cout << verification_phrase;
        }
};
class Component_data {
    private:
        string name;
        string ID;
    
    public:
    Component_data(string name, string ID) {
            this->name = name;
            this->ID = ID;
    }
    string getName() {
            return name;
        }

    void getID() {
            cout << ID;
        }

    void setName(string name) {
            this->name = name;
        }

    void setID(string ID) {
            this->ID = ID;
        }
};



void menuManager () {
    bool running = true;
    do {
        int choice;
        cout << "Please select an option:" << endl;
        cout << "1. Register new customer" << endl;
        cout << "2. Edit customer" << endl;
        cout << "3. Remove customer" << endl;
        cout << "4. View customers" << endl;
        cout << "5. Quit" << endl;
        cout << endl << endl;
        cout << "Choice: ";

        choice = getch();
        cout << endl << endl;
        switch (choice) {
            case 1:
                system("cls");
                cout << "Customer ID" << endl;
                cout << "Customer name" << endl;
                cout << "Customer adress" << endl;
                cout << "Customer PIN code" << endl;
                cout << "Customer Tag-ID" << endl;
                cout << "Customer verification phrase" << endl;
                cout << "Customer equipment:" << endl;
                cout << "\tSmoke detector:" << endl;
                cout << "\t\tID:" << endl;
                cout << "\t\tName:" << endl;
                break;
            case 2:
                system("cls");
                cout << "1. Edit ID" << endl;
                cout << "2. Edit name" << endl;
                cout << "3. Edit adress" << endl;
                cout << "4. Edit PIN code" << endl;
                cout << "5. Edit Tag-ID" << endl;
                cout << "6. Edit verification phrase" << endl;
                cout << "7. Edit equipment" << endl;
                cout << "8. Exit" << endl;
                break;
            case 3:
                system("cls");
                cout << "Något" << endl;
                break;
            case 4:
                system("cls");
                cout << "Något" << endl;
                break;
            case 5:
                running = false;
                break;
        }
    } while (!running == false);
};



int main () {

   menuManager();
    

    cout << "Goodbye!" << endl;
    return 0;
}


/*class Customer {
    private:
        string name;
        int adress;
    
    public:
    Customer(string name, int adress) {
            this->name = name;
            this->adress = adress;
    }
    void getName() {
            cout << name;
        }

    void getAdress() {
            cout << adress;
        }

    void setName(string name) {
            this->name = name;
        }

    void setAdress(int adress) {
            this->adress = adress;
        }
};


class user {
    private:
        string name;
        int adress;
        int ID;
        int code;
        string tagID;
        string stringForDeactivation;

    public:
    user(string name, int adress) {
            this->name = name;
            this->adress = adress;
            this->ID = ID;
            this->code = code;
            this->tagID = tagID;
            this->stringForDeactivation = stringForDeactivation;
    }
    
}; */