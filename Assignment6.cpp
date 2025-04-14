/*Billy Peo
Data Structures
Assignment 6
*/
#include <iostream>
using namespace std;

const int TABLE_SIZE = 907;
const int EMPTY = -1;
const int DELETED = -2;

class HashTable {
private:
    int table[TABLE_SIZE];

    int hash(int key, int i) {
        return (key % TABLE_SIZE + i) % TABLE_SIZE;
    }

public:
    HashTable() {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            table[i] = EMPTY;
        }
    }

    int HashInsertion(int key) {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            int index = hash(key, i);
            if (table[index] == EMPTY || table[index] == DELETED) {
                table[index] = key;
                return index;
            }
        }
        return -1;
    }

    int HashDeletion(int key) {
        for (int i = 0; i < TABLE_SIZE; ++i) {
            int index = hash(key, i);
            if (table[index] == key) {
                table[index] = DELETED;
                return index;
            }
            else if (table[index] == EMPTY) {
                return -1;
            }
        }
        return -1;
    }

    void display() const {
        cout << "\nCurrent Hash Table:\n";
        for (int i = 0; i < TABLE_SIZE; ++i) {
            if (table[i] != EMPTY && table[i] != DELETED)
                cout << "Index " << i << ": " << table[i] << endl;
        }
    }
};

int main() {
    HashTable ht;
    int choice, key;

    do {
        cout << "\n--- Hash Table Menu ---\n";
        cout << "1. Insert a key\n";
        cout << "2. Delete a key\n";
        cout << "3. Display table\n";
        cout << "0. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
        case 1:
            cout << "Enter key to insert: ";
            cin >> key;
            {
                int index = ht.HashInsertion(key);
                if (index != -1)
                    cout << "Inserted at index " << index << ".\n";
                else
                    cout << "Insertion failed: Table is full.\n";
            }
            break;

        case 2:
            cout << "Enter key to delete: ";
            cin >> key;
            {
                int index = ht.HashDeletion(key);
                if (index != -1)
                    cout << "Deleted from index " << index << ".\n";
                else
                    cout << "Deletion failed: Key not found.\n";
            }
            break;

        case 3:
            ht.display();
            break;

        case 0:
            cout << "Exiting.\n";
            break;

        default:
            cout << "Invalid choice. Try again.\n";
        }

    } while (choice != 0);

    return 0;
}
