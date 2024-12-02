#include "nlohmann/json.hpp"
#include <iostream>
#include <fstream>



using namespace std;
using json = nlohmann::json;

// Struktur för att representera en kund
struct Customer {
    int customer_id;
    string name;
    string address;
    string PIN;
    string tag_id;
    string verification_phrase;
};

//class Customer {};
//class User {};
//class Component {};

struct Equipment {
    struct Component {
        int id;
        string name;
    };

    vector<Component> smoke_detector;
    vector<Component> breaker;
};




void menuManager () {
    bool running = true;
    do {
        int choice;
        cout << "Please select an option:" << endl;
        cout << "1. Register a new customer" << endl;
        cout << "2. Register new equipment" << endl;
        cout << "3. Show customer info" << endl;
        cout << "4. Show equipment info" << endl;
        cout << "5. Quit" << endl;
        cout << endl << endl;
        cout << "Choice: ";

        cin >> choice;
        cout << endl << endl;
        switch (choice) {
            case 1:
                cout << "Något" << endl;
                break;
            case 2:
                cout << "Något" << endl;
                break;
            case 3:
                cout << "Något" << endl;
                break;
            case 4:
                cout << "Något" << endl;
                break;
            case 5:
                cout << "Quit" << endl;
        }
    } while (!running == false);
};

int main () {

   /*  try {
        contacts = ContactManager::loadContacts("contactDB.json");
    }
    catch (const exception& e) {
         cout << "Error: Could not open file" << endl;
         return 1;
    } */
   
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