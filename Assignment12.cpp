/*Billy Peo
Data Strcutures
Professor Wu*/

#include <iostream>
using namespace std;

// Binary search function (returns index or -1 if not found)
int binarySearch(int arr[], int size, int target) {
    int left = 0;
    int right = size - 1;

    while (left <= right) {
        int mid = left + (right - left) / 2;

        if (arr[mid] == target)
            return mid; // found
        else if (arr[mid] < target)
            left = mid + 1; // search right half
        else
            right = mid - 1; // search left half
    }

    return -1; // not found
}

void printArray(int arr[], int size) {
    for (int i = 0; i < size; i++)
        cout << arr[i] << " ";
    cout << endl;
}

int main() {
    int arr[] = { 1, 3, 5, 7, 9, 11, 13 };
    int size = sizeof(arr) / sizeof(arr[0]);
    int target;

    cout << "Array: ";
    printArray(arr, size);

    cout << "Enter a number to search: ";
    cin >> target;

    int result = binarySearch(arr, size, target);

    if (result != -1)
        cout << "Element found at index: " << result << endl;
    else
        cout << "Element not found in the array." << endl;

    return 0;
}
