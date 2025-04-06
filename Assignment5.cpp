// Assigment 5: Data Structures
// Name: Billy Peo
// Date: 03/20/2025
#include <iostream>
#include <vector>

class MaxHeap {
private:
    std::vector<int> heap;

    //Function methods to find parent and children index location
    static int parent(const int index) {
        return (index - 1) / 2;
    }

    static int leftChild(int index) {
        return 2 * index + 1;
    }

    static int rightChild(int index) {
        return 2 * index + 2;
    }

    //Heapify (up) after insertion
    void heapifyUp(int index) {
        while (index > 0 && heap[parent(index)] < heap[index]) {
            std::swap(heap[parent(index)], heap[index]);
            index = parent(index);
        }
    }

    //Heapify (down) after removal
    void heapifyDown(int index);

    //Function to ensure all numbers are rounded to the nearest multiple of 5
    static int toNearestMultipleOfFive(const int value) {
        return (value + 2) / 5 * 5;
    }

public:
    //Insert a new value into the heap
    void insert(int value) {
        value = toNearestMultipleOfFive(value);
        std::cout << "Inserting value: " << value << std::endl;
        heap.push_back(value);  //Add to the end of the heap
        std::cout << "Heap size after insertion: " << heap.size() << std::endl;
        heapifyUp(heap.size() - 1);  //Rehears the new added element
    }

    //Remove and return the root element (the max)
    int remove() {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }

        //Swaps the root with the last element
        int rootValue = heap[0];
        heap[0] = heap.back();
        heap.pop_back();  //Removes the last element

        heapifyDown(0);  //Rehears the new root
        return rootValue;
    }

    //Peek at the root element (max)
    [[nodiscard]] int peek() const {
        if (heap.empty()) {
            throw std::out_of_range("Heap is empty");
        }
        return heap[0];
    }

    //Display the current heap
    void display() const {
        for (const int value : heap) {
            std::cout << value << " ";
        }
        std::cout << std::endl;
    }

    //Function to check if the heap is empty
    [[nodiscard]] bool isEmpty() const {
        return heap.empty();
    }

    //Return the size of the heap
    [[nodiscard]] int size() const {
        return heap.size();
    }
};

void MaxHeap::heapifyDown(int index) {
    int size = heap.size();
    int largest = index;
    int left = leftChild(index);
    int right = rightChild(index);

    //Function to check left child is greater than the current largest
    if (left < size && heap[left] > heap[largest]) {
        largest = left;
    }

    //Function to check right child is greater than the current largest
    if (right < size && heap[right] > heap[largest]) {
        largest = right;
    }

    //If the largest is not the current index, swap and continue heapify
    if (largest != index) {
        std::swap(heap[largest], heap[index]);
        heapifyDown(largest);
    }
}

int main() {
    MaxHeap maxHeap;

    //Output Function Insertions
    maxHeap.insert(11);
    maxHeap.insert(12);
    maxHeap.insert(14);
    maxHeap.insert(25);
    maxHeap.insert(7);
    maxHeap.insert(40);

    std::cout << "Heap after insertions: ";
    maxHeap.display();  //prints the heap in a list

    //removal function output
    std::cout << "Removed root: " << maxHeap.remove() << std::endl;
    std::cout << "Heap after removal: ";
    maxHeap.display();  //Heap will be adjusted after removal

    //peeking at the root function output
    std::cout << "Root element (peek): " << maxHeap.peek() << std::endl;

    return 0;
}