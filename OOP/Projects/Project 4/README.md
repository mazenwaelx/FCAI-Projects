MultiArray Library
Overview
The MultiArray library provides a template class MultiArray that allows you to work with multiple arrays of a specified data type. The library includes functionalities such as loading data from files, reversing arrays, sorting arrays, searching for items, applying functions to array elements, extracting subarrays, merging arrays, and splitting arrays.

Usage
To use the library, include the MultiArray class template and its associated functions in your C++ program. The provided main function demonstrates the usage of the library with two integer arrays.

cpp
Copy code
#include <iostream>
#include <fstream>
#include <algorithm>

// MultiArray class template definition goes here...

template <class T2>
void square(T2& x) {
    x *= x;
}

int main() {
    // Example usage of MultiArray
    // ...

    return 0;
}
Class: MultiArray
Constructor
cpp
Copy code
MultiArray(int numA, int* sizes, string* names);
numA: Number of arrays.
sizes: An array containing the sizes of each array.
names: An array containing names for each array.
Destructor
cpp
Copy code
~MultiArray();
Member Functions
int getMergedSize() const: Get the total size of merged arrays.

void loadFromFile(string arrName, string fileName): Load data from a file into a specified array.

T* subArray(string name, int startIndex, int endIndex, int step = 1): Extract a subarray from a specified array.

void reverse(string name): Reverse the elements of a specified array.

void sort(string name): Sort the elements of a specified array.

bool search(T item): Search for a specified item in all arrays.

T& operator()(const std::string& name, int index): Access array elements using parentheses.

void setArrayData(string name, T* data, int index = 0): Set data for a specified array.

MultiArray split(string name): Split a specified array into two arrays.

T* merge(): Merge all arrays into a single array.

void applyToArray(string name, void (*func)(T&)): Apply a function to all elements of a specified array.

Friend Functions
friend ostream& operator<<(ostream& os, const MultiArray<T>& ms): Output the contents of all arrays.
Example Usage
cpp
Copy code
int sizes[] = {5, 3};
string names[] = {"Array1", "Array2"};
MultiArray<int> myArrays(2, sizes, names);

// Load data from files
myArrays.loadFromFile("Array1", "file1.txt");
myArrays.loadFromFile("Array2", "file2.txt");

// Perform operations on arrays
// ...

// Display arrays
cout << "MultiArrays:" << endl;
cout << myArrays;
Menu-Driven Example
The provided main function demonstrates a menu-driven example for various operations on the MultiArray library. The user can choose operations like reversing arrays, sorting arrays, searching for items, applying square function, extracting subarrays, merging arrays, and splitting arrays.
