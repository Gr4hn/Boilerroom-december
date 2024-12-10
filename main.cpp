#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>
#include <conio.h>


using namespace std;
using json = nlohmann::json;





class Customer_Data {
    private:
        string ID;
        string name;
        string adress;
        string PIN;
        string tag_ID;
        string verification_phrase;
    public:

    Customer_Data() {
            this->ID = "";
            this->name = "";
            this->adress = "";
            this->PIN = "";
            this->tag_ID = "";
            this->verification_phrase = "";
    }

    Customer_Data(string name, int adress) {
            this->ID = ID;
            this->name = name;
            this->adress = adress;
            this->PIN = PIN;
            this->tag_ID = tag_ID;
            this->verification_phrase = verification_phrase;
    }

    Customer_Data(string id, string name, string adress, string pin, string tagID, string verificationPhrase)
        : ID(id), name(name), adress(adress), PIN(pin), tag_ID(tagID), verification_phrase(verificationPhrase) {}

    //Getters
    string getID() const { return ID; }
    string getName() const { return name; }
    string getAddress() const { return adress; }
    string getPIN() const { return PIN; }
    string getTagID() const { return tag_ID; }
    string getVerificationPhrase() const { return verification_phrase; }


    //Setters
    void setID(const string& id) { ID = id; }
    void setName(const string& name) { this->name = name; }
    void setAddress(const string& address) { this->adress = adress; }
    void setPIN(const string& pin) { PIN = pin; }
    void setTagID(const string& tagID) { tag_ID = tagID; }
    void setVerificationPhrase(const string& verificationPhrase) { verification_phrase = verificationPhrase; }

    static Customer_Data fromJson(const json& j) {
        return Customer_Data(
            j.at("customer_id").get<string>(),
            j.at("name").get<string>(),
            j.at("adress").get<string>(),
            j.at("PIN").get<string>(),
            j.at("tag_id").get<string>(),
            j.at("verification_phrase").get<string>()
        );
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

class Customer {
    private:
        vector<Customer_Data> customer_data;
        /* Component_data smoke_detector;
        Component_data breaker; */
    
    public:
        Customer() {
            this->customer_data = customer_data;
        }

        static vector<Customer_Data> retriveData(const string &dataBase) {
            vector<Customer_Data> currentCustomers;
            ifstream retrive(dataBase);
            if (!retrive) {
                cout << "Error opening file " << dataBase << endl;
                return {};
            }

            json jsonFile;
            retrive >> jsonFile;

            for (const auto& item : jsonFile) {
                currentCustomers.push_back(Customer_Data::fromJson(item));
            }

            cout << "Successfully loaded contacts" << endl;
            return currentCustomers;
        }


    /* Customer_Data retrieveCustomerData() {
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
    } */
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

        cin >> choice;
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
                //addCustomer(); //Tillfällig, inmplementeras senare.
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
                //editCustomer(); // Tillfällig, inmplementeras senare.
                break;
            case 3:
                system("cls");
                cout << "Något" << endl;
                //removeCustomer(); // Tillfällig, inmplementeras senare.
                break;
            case 4:
                system("cls");
                cout << "Något" << endl;
                //viewCustomers(); Tillfällig, inmplementeras senare.
                break;
            case 5:
                cout << "Qutting customer managment program";
                running = false;
                break;
            default: 
                cout << "Enter a choice from the list." << endl << endl;
                break;
        }
    } while (running == true);
};



int main () {
    vector<Customer_Data> customerList;

    string dataBase = "C:/users/eric/boilerroom-december/customers.json";

    try {
        customerList = Customer::retriveData(dataBase);
    }
    catch (const exception& e) {
            cout << "Error: " << e.what() << endl;
            return 1;
    }

    menuManager();

    cout << "Goodbye!" << endl;
    return 0;
}