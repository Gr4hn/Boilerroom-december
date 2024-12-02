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
class Database {
private:
    json data;
    string filename;

public:
    Database(const string& file) : filename(file) {
        // Försök att ladda data vid instansiering
        loadData();
    }

    void loadData() {
        ifstream file(filename);
        if (file.is_open()) {
            file >> data;
            file.close();
        }
    }

    void saveData() {
        ofstream file(filename);
        if (file.is_open()) {
            file << data.dump(4);  // Skriver ut JSON med indrag
            file.close();
        }
    }

    void addCustomer(const Customer& customer) {
        json customerJson = {
            {"customer_id", customer.customer_id},
            {"name", customer.name},
            {"address", customer.address},
            {"PIN", customer.PIN},
            {"tag_id", customer.tag_id},
            {"verification_phrase", customer.verification_phrase}
        };
        data["customers"].push_back(customerJson);
        saveData();
    }

    void addEquipment(const string& type, const Equipment::Component& component) {
        json componentJson = {
            {"id", component.id},
            {"name", component.name}
        };

        if (type == "smoke_detector") {
            data["equipment"]["smoke_detector"].push_back(componentJson);
        } else if (type == "breaker") {
            data["equipment"]["breaker"].push_back(componentJson);
        }

        saveData();
    }

    json getData() const {
        return data;
    }
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