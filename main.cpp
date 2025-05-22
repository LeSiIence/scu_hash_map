#include "hashmap_custom.h"
#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

// Function to display the menu
void displayMenu() {
    cout << "\n--- HashMap Test Menu ---" << endl;
    cout << "1. Insert Key-Value Pair" << endl;
    cout << "2. Find Value by Key" << endl;
    cout << "3. Check if Key Exists" << endl;
    cout << "4. Remove Key" << endl;
    cout << "5. Display HashMap" << endl;
    cout << "6. Run Random Data Test" << endl;
    cout << "7. Exit" << endl;
    cout << "Enter your choice: ";
}

int main() {
    HashMap<string, int> hashmap;

    int choice;
    string key;
    int value;

    srand(static_cast<unsigned int>(time(0))); // Seed for random number generation

    do {
        displayMenu();
        cin >> choice;

        switch (choice) {
            case 1:
                cout << "Enter key (string): ";
                cin >> key;
                cout << "Enter value (int): ";
                cin >> value;
                hashmap[key] = value;
                cout << "Inserted (" << key << ", " << value << ")" << endl;
                break;

            case 2:
                cout << "Enter key to find (string): ";
                cin >> key;
                try {
                    cout << "Value for key '" << key << "' is: " << hashmap.at(key) << endl;
                } catch (const out_of_range& e) {
                    cout << "Error: Key not found!" << endl;
                }
                break;

            case 3:
                cout << "Enter key to check (string): ";
                cin >> key;
                if (hashmap.contains(key)) {
                    cout << "Key '" << key << "' exists." << endl;
                } else {
                    cout << "Key '" << key << "' does not exist." << endl;
                }
                break;

            case 4:
                cout << "Enter key to remove (string): ";
                cin >> key;
                if (hashmap.erase(key)) {
                    cout << "Key '" << key << "' removed successfully." << endl;
                } else {
                    cout << "Key '" << key << "' not found. Removal failed." << endl;
                }
                break;

            case 5:
                cout << "Current HashMap:" << endl;
                hashmap.debug();
                break;

            case 6: {
                const int testSize = 10; // Number of random entries to insert
                cout << "Running random data test with " << testSize << " entries..." << endl;
                for (int i = 0; i < testSize; ++i) {
                    key = "key" + to_string(rand() % 100); // Generate a random key
                    value = rand() % 100;                 // Generate a random value
                    hashmap[key] = value;
                    cout << "Inserted (" << key << ", " << value << ")" << endl;
                }

                cout << "\nFinal HashMap after random insertion:" << endl;
                hashmap.debug();

                cout << "Clearing HashMap after test..." << endl;
                hashmap.clear();
                break;
            }

            case 7:
                cout << "Exiting program. Goodbye!" << endl;
                break;

            default:
                cout << "Invalid choice. Please try again." << endl;
                break;
        }
    } while (choice != 7);

    return 0;
}