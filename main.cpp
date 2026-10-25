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

    // insert elements into the map
    // note how the right-hand side of the assignment are the vector elements
    // villagerColors["Audie"] = {"Orange", "Yellow", "Red"};
    // villagerColors["Raymond"] = {"Black", "Gray", "White"};
    // villagerColors.insert({"Marshal", {"Blue", "White", "Black"}});

    cout << "Villager details:" << endl;

    for (auto pair : villagerData) {
        cout << pair.first << " [" << get<0>(pair.second) << ", " << get<1>(pair.second) << ", " << get<2>(pair.second) << "]" << endl;
    }

    // access the map using a range-based for loop
    // cout << "Villagers and their favorite colors (range-based for loop):" << endl;
    // for (auto pair : villagerData) {
    //     cout << pair.first << ": ";
    //     for (auto color : pair.second)
    //         cout << color << " ";
    //     cout << endl;
    // }

    // access the map using iterators
    cout << "\nVillagers and their favorite colors (iterators):" << endl;
    
    // for (map<string, vector<string>>::iterator it = villagerColors.begin(); 
    //                                            it != villagerColors.end(); ++it) {
    //     cout << it->first << ": ";
    //     for (auto color : it->second) {
    //         cout << color << " ";
    //     }
    //     cout << endl;
    // }

    for (map<string, tuple<int, string, string>>::iterator it =
        villagerData.begin();
        it != villagerData.end(); ++it) {

        cout << it->first << " ["<< get<0>(it->second) << ", " << get<1>(it->second) << ", " << get<2>(it->second) << "]" << endl;
    }

    // delete an element
    //villagerColors.erase("Raymond");
    villagerData.erase("Raymond");

    // search for an element using .find() to avoid errors
    string searchKey = "Audie";
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
    cout << "\nSize before clear: " << villagerData.size() << endl;
    villagerData.clear();
    cout << "Size after clear: " << villagerData.size() << endl;

    return 0;
}
