// Assigment 4
// Name: Billy Peo
// Date: 03/10/2025
#include <iostream>
using namespace std;


class Node {
public:
    int data;
    Node* next;

    explicit Node(const int value) : data(value), next(nullptr) {}
};

class CircularQueue {
private:
    Node* rear;

public:
    CircularQueue() : rear(nullptr) {}

    [[nodiscard]] bool isEmpty() const;
    //Add to the Queue
    void enqueue(const int value) {
        const auto newNode = new Node(value);
        if (isEmpty()) {
            rear = newNode;
            rear->next = rear; 
        }
        else {
            newNode->next = rear->next;
            rear->next = newNode;
            rear = newNode;
        }
    }
    //Delete
    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty. Cannot dequeue." << endl;
            return;
        }

        if (rear->next == rear) {  
            delete rear;
            rear = nullptr;
        }
        else {
            const Node* front = rear->next;
            rear->next = front->next;
            delete front;
        }
    }

    void getFront() const
    {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
        }
        else {
            cout << "Front element: " << rear->next->data << endl;
        }
    }
    //Displays Queue Content
    void display() const
    {
        if (isEmpty()) {
            cout << "Queue is empty." << endl;
            return;
        }
        Node* current = rear->next;
        do {
            cout << current->data << " -> ";
            current = current->next;
        } while (current != rear->next);
        cout << "End" << endl;
    }
};

bool CircularQueue::isEmpty() const
{
    return rear == nullptr;
}

//Output Display
int main() {
    CircularQueue queue;

    queue.enqueue(3);
    queue.enqueue(2);
    queue.enqueue(1);
    queue.getFront();
    queue.display();    //Display

    queue.dequeue();
    queue.getFront();
    queue.display();    //Display

    return 0;
}