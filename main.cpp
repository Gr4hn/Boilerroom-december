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

    Customer_Data(const string &ID, const string &name, const string &adress, const string &PIN, const string &tag_ID, const string &verification_phrase) {
            this->ID = ID;
            this->name = name;
            this->adress = adress;
            this->PIN = PIN;
            this->tag_ID = tag_ID;
            this->verification_phrase = verification_phrase;
    }

    Customer_Data(string name, int adress) {
            this->ID = ID;
            this->name = name;
            this->adress = adress;
            this->PIN = PIN;
            this->tag_ID = tag_ID;
            this->verification_phrase = verification_phrase;
    }
/*     void setID(string ID) {
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
        } */
    Customer_Data fromJson(const json& j) {
        return Customer_Data(
            j.at("ID").get<string>(),
            j.at("name").get<string>(),
            j.at("adress").get<string>(),
            j.at("PIN").get<string>(),
            j.at("tag_ID").get<string>(),
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
        Customer_Data customer_data;
        Component_data smoke_detector[2];
        Component_data breaker[10];
    
    public:
    Customer() {
            //this->customer_data = 0;
            //this->smoke_detector = nullptr;
            //this->breaker = nullptr;
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

    static Customer_Data retriveData(const string &filename) {
        ifstream file(filename);
        if (!file) {
            cout << "Error opening file " << filename << endl;
            return;
        }

        json jsonFile;
        file >> jsonFile;
        Customer_Data c = Customer_Data::fromJson(jsonFile); 

        
        for (const auto& person : jsonFile) {
            Customer_data.push_back({
                person["id"].get<string>(),
                person["name"].get<string>(),
                person["adress"].get<string>(),
                person["pin"].get<string>(),
                person["tag_id"].get<string>(),
                person["verification_phrase"].get<string>()
            });
        }

        cout << "Successfully loaded contacts" << endl;
        return c;
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

    Customer customer;
    Customer_Data customer_data;

    try {
        customer_data = Customer::retriveData("customers.json");
    }
    catch (const exception& e) {
            cout << "Error: Could not open file" << endl;
            return 1;
    }

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