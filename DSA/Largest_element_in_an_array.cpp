//Program for fixed- size array

#include <bits/stdc++.h>
using namespace std;

int findLargestElement(int arr[], int size) {
    int largest = INT_MIN; // Initialize largest with the smallest possible integer value

    for (int i = 0; i < size; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}

int main() {
    int arr[] = {10, 20, 30, 50, 60};
    int size = sizeof(arr) / sizeof(arr[0]);

    int largestElement = findLargestElement(arr, size);

    cout << "Largest element in the array is: " << largestElement << std::endl;

    return 0;
}


// Time complexity - >  O(n)

////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////////


//Program for dynamic array


#include <bits/stdc++.h>
using namespace std;

int findLargestElement(int *arr, int size) {
    int largest = INT_MIN; // Initialize largest with the smallest possible integer value

    for (int i = 0; i < size; ++i) {
        if (arr[i] > largest) {
            largest = arr[i];
        }
    }

    return largest;
}

int main() {
    int size;
    cout << "Enter the size of the dynamic array: ";
    cin >> size;

    // Dynamically allocate memory for the array
    int *arr = new int[size];

    // Input elements into the dynamic array
    cout << "Enter " << size << " elements of the array:" << endl;
    for (int i = 0; i < size; ++i) {
        cin >> arr[i];
    }

    // Find the largest element in the dynamic array
    int largestElement = findLargestElement(arr, size);

    // Output the result
    cout << "Largest element in the dynamic array is: " << largestElement << std::endl;
    return 0;
}

// Time complexity - > O(n)