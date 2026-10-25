// Keshav Yanamandra
// COMSC-210-5293, Fall 2026
// Lab 27

#include <iostream>
#include <map>
#include <vector>
#include <tuple>

using namespace std;

int main() {
    // declarations
    map<string, tuple<int, string, string>> villagerData;

    villagerData["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagerData["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagerData["Raymond"] = make_tuple(8, "Cat", "Nice fit");

    int choice =0;
    int friendship;
    string name;
    string species;
    string catchphrase;

    //menu
    while (choice != 6) {

        cout << endl;
        cout << "1. Add Villager" << endl;
        cout << "2. Delete Villager" << endl;
        cout << "3. Increase Friendship" << endl;
        cout << "4. Decrease Friendship" << endl;
        cout << "5. Search for Villager" << endl;
        cout << "6. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;


        if (choice == 1) {
            cout << "Villager name: ";
            cin >> name;

            cout << "Friendship level: ";
            cin >> friendship;

            cout << "Species: ";
            cin >> species;

            cout << "Catchphrase: ";
            cin.ignore();
            getline(cin, catchphrase);

            villagerData[name] = make_tuple(friendship, species, catchphrase);

            cout << name << " added." << endl;
        }
        
        if (choice == 2) {
            cout << "Villager name: ";
            cin >> name;

            auto it = villagerData.find(name);

            if (it != villagerData.end()) {
                villagerData.erase(name);
            }
            else {
                cout << name << " not found." << endl;
            }
        }
        
        
        
        if (choice == 3) {
            cout << "Villager name: ";
            cin >> name;

            auto it = villagerData.find(name);

            if (it != villagerData.end()) {
                get<0>(it->second)++;
            }
            else {
                cout << name << " not found." << endl;
            }
        }

        else if (choice == 4) {
            cout << "Villager name: ";
            cin >> name;

            auto it = villagerData.find(name);

            if (it != villagerData.end()) {
                if (get<0>(it->second) > 0) {
                    get<0>(it->second)--;
                }
            }
            else {
                cout << name << " not found." << endl;
            }
        }

        else if (choice == 5) {
            cout << "Villager name: ";
            cin >> name;

            auto it = villagerData.find(name);

            if (it != villagerData.end()) {
                cout << it->first << " [" << get<0>(it->second) << ", "  << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
            }
            else {
                cout << name << " not found." << endl;
            }
        }

        if (choice != 6) {
            cout << endl;
            cout << "Villager details:" << endl;

            for (auto pair : villagerData) {
                cout << pair.first << " ["  << get<0>(pair.second) << ", " << get<1>(pair.second) << ", "  << get<2>(pair.second) << "]" << endl;
            }
        }

    }

    return 0;
}
