/*Billy Peo
Data Structures
2/26/2025
Spring Semester*/

#include <iostream>
using namespace std;

// Define a doubly linked list node
struct Node {
    int data;
    Node* prev;
    Node* next;
};


    // Function to insert a node at a given index
    int DoubleLinkedlistInsert(int data, int index, Node** head) {
        Node* newNode = new Node();
        newNode->data = data;
        newNode->prev = nullptr;
        newNode->next = nullptr;

        if (index < 0) return -1; // Invalid index

        if (*head == nullptr) { // If list is empty
            if (index == 0) {
                *head = newNode;
                return 0;
            }
            else {
                delete newNode;
                return -1; // Index out of bounds
            }
        }

        Node* temp = *head;
        for (int i = 0; i < index && temp->next != nullptr; i++) {
            temp = temp->next;
        }

        if (index == 0) { // Insert at head
            newNode->next = *head;
            (*head)->prev = newNode;
            *head = newNode;
        }
        else if (temp->next == nullptr && index > 0) { // Insert at end
            temp->next = newNode;
            newNode->prev = temp;
        }
        else { // Insert at middle
            newNode->prev = temp->prev;
            newNode->next = temp;
            if (temp->prev) temp->prev->next = newNode;
            temp->prev = newNode;
        }
        return 0;
    }

    // Function to delete a node at a given index
    int DoubleLinkedlistDelete(int index, Node** head) {
        if (*head == nullptr || index < 0) return -1; // Empty list or invalid index

        Node* temp = *head;
        for (int i = 0; i < index && temp != nullptr; i++) {
            temp = temp->next;
        }

        if (temp == nullptr) return -1; // Index out of bounds

        if (temp->prev) temp->prev->next = temp->next;
        if (temp->next) temp->next->prev = temp->prev;

        if (index == 0) *head = temp->next; // Update head if necessary

        delete temp;
        return 0;
    }

// Helper function to print the list
void printList(Node* head) {
    Node* temp = head;
    while (temp) {
        cout << temp->data << ", ";
        temp = temp->next;
    }
    cout << "NULL" << endl;
}

int main() {
    Node* head = nullptr;

    // Insert some elements
    DoubleLinkedlistInsert(15, 0, &head);
    DoubleLinkedlistInsert(27, 1, &head);
    DoubleLinkedlistInsert(31, 2, &head);
    DoubleLinkedlistInsert(44, 1, &head);
    DoubleLinkedlistInsert(74, 2, &head);

    cout << "List after insertions: ";
    printList(head);

    // Delete some elements
    DoubleLinkedlistDelete(1, &head);
    cout << "List after deleting index 1: ";
    printList(head);
    //Delete more elements
    DoubleLinkedlistDelete(1, &head);
    cout << "List after deleting index 1: ";
    printList(head);

    return 0;
}