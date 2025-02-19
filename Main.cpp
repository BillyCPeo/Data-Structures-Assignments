/*Billy Peo
DataStructures
2/18/2025*/
//Libraries
#include <cstdio>
#include <iostream>

using namespace std;

struct Node {
    int data;
    Node* next;
};

class LinkedList {
public:
    Node* head;

    LinkedList() { head = nullptr; }
    //Insert
    int LinkedlistInsert(int data, int index, Node** Ptr) {
        Node* newNode = new Node{ data, nullptr };
        if (!newNode) return -1; // Memory allocation failure

        if (index == 0) {
            newNode->next = *Ptr;
            *Ptr = newNode;
            return 0;
        }

        Node* temp = *Ptr;
        for (int i = 0; temp != nullptr && i < index - 1; i++) {
            temp = temp->next;
        }

        if (!temp) return -1; // Index out of bounds

        newNode->next = temp->next;
        temp->next = newNode;
        return 0;
    }
    //Delete
    int LinkedlistDelete(int index, Node** Ptr) {
        if (*Ptr == nullptr) return -1; // Empty list

        Node* temp = *Ptr;

        if (index == 0) {
            *Ptr = temp->next;
            delete temp;
            return 0;
        }

        Node* prev = nullptr;
        for (int i = 0; temp != nullptr && i < index; i++) {
            prev = temp;
            temp = temp->next;
        }

        if (!temp) return -1; // Index out of bounds

        prev->next = temp->next;
        delete temp;
        return 0;
    }

    void display(Node* Ptr) {
        while (Ptr) {
            std::cout << Ptr->data << " -> ";
            Ptr = Ptr->next;
        }
        std::cout << "NULL" << std::endl;
    }
};

int main() {
    LinkedList list;
    list.LinkedlistInsert(10, 0, &list.head);
    list.LinkedlistInsert(20, 1, &list.head);
    list.LinkedlistInsert(30, 1, &list.head);
    list.display(list.head);

    list.LinkedlistDelete(1, &list.head);
    list.display(list.head);

    return 0;
}