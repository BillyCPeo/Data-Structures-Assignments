// Assigment 3
// Name: Billy Peo
// Date: 03/05/2025
#include <iostream>
using namespace std;

#define MAX_SIZE 100

//Define Class to show the stack data structure
class Stack {
private:
    int arr[MAX_SIZE];  //Array for storing stack values
    int top;            //Index of the top element

public:
    //Constructor to set up the stack
    Stack() : arr{}
    {
        top = -1; //Set the stack to be empty
    }

    //Push function to add an element to the stack
    int push(int T) {
        if (top >= MAX_SIZE - 1) {
            cout << "Stack Overflow\n";
            return -1; //Shows a failure due to overflow
        }
        arr[++top] = T; //Function to add T to the stack and updates the top index by adding an element
        return 0; //Indicates solid functionality
    }

    //Top and pop function to return the top element and pop it
    int topandpop() {
        if (top == -1) {
            cout << "Stack Underflow\n";
            return -1; //Shows a failure due to underflow
        }
        const int topElement = arr[top]; //Top element
        top--; //Function that decreases the top index to pop the element needed
        return topElement; //Return Pop Statement
    }
};

int main() {
    Stack stack;

    //Push elements into the stack
    stack.push(20);
    stack.push(30);
    stack.push(50);

    //Verifying the top and pop functions
    cout << "Top and pop: " << stack.topandpop() << endl; //Prints 50
    cout << "Top and pop: " << stack.topandpop() << endl; //Prints 30
    cout << "Top and pop: " << stack.topandpop() << endl; //Prints 20
    cout << "Top and pop: " << stack.topandpop() << endl; //Prints Stack underflow and displays the return -1 statement
    return 0;
}