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
    //map<string, vector<string>> villagerColors;
    map<string, tuple<int, string, string>> villagerData;

    villagerData["Drago"] = make_tuple(5, "Alligator", "Snap to It!");
    villagerData["Kyle"] = make_tuple(10, "Wolf", "Hubba hubba!");
    villagerData["Raymond"] = make_tuple(8, "Cat", "Nice fit");

    int choice =0;
    string name;

    //menu
    while (choice != 4) {

        cout << endl;
        cout << "1. Increase Friendship" << endl;
        cout << "2. Decrease Friendship" << endl;
        cout << "3. Search for Villager" << endl;
        cout << "4. Exit" << endl;
        cout << "Enter choice: ";
        cin >> choice;

        if (choice == 1) {
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

        else if (choice == 2) {
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

        else if (choice == 3) {
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

        if (choice != 4) {
            cout << endl;
            cout << "Villager details:" << endl;

            for (auto pair : villagerData) {
                cout << pair.first << " ["  << get<0>(pair.second) << ", " << get<1>(pair.second) << ", "  << get<2>(pair.second) << "]" << endl;
            }
        }


    }
    
    
    cout << "Villager details:" << endl;

    for (auto pair : villagerData) {
        cout << pair.first << " [" << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << "]" << endl;
    }

    // access the map using iterators
    cout << "\nVillager details:" << endl;    


    for (map<string, tuple<int, string, string>>::iterator it =
        villagerData.begin();
        it != villagerData.end(); ++it) {

        cout << it->first << " ["<< get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
    }

    // delete an element
    //villagerData.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Drago";

    //auto it = villagerColors.find(searchKey);
    auto it = villagerData.find(searchKey);

    if (it != villagerData.end()) {  // the iterator points to beyond the end of the map
                                       // if searchKey is not found
        cout << "\nFound " << searchKey << ": [" << get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
        cout << endl;
    } 
    else
        cout << endl << searchKey << " not found." << endl;

    // report size, clear, report size again to confirm map operations
    // cout << "\nSize before clear: " << villagerData.size() << endl;
    // villagerData.clear();
    // cout << "Size after clear: " << villagerData.size() << endl;

    return 0;
}
