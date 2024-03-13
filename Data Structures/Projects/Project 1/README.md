# Sorting Algorithms

This repository contains C++ code implementing various sorting algorithms such as Insertion Sort (linear and binary), Selection Sort, Shell Sort, and Merge Sort.

## Algorithms Implemented:

1. **Insertion Sort:**
   - Linear Insertion Sort: A simple insertion sort algorithm that iterates through the array linearly.
   - Binary Insertion Sort: An optimized version of insertion sort that uses binary search to find the correct position for the current element.

2. **Selection Sort:**
   - Selection Sort: A sorting algorithm that repeatedly finds the minimum element from the unsorted part and moves it to the beginning.

3. **Merge Sort:**
   - Merge Sort: A divide and conquer algorithm that divides the input array into two halves, recursively sorts them, and then merges the sorted halves.

4. **Shell Sort:**
   - Shell Sort: A variation of insertion sort that sorts elements at a specific interval.

## How to Use:

1. Clone the repository to your local machine.
2. Compile the `main.cpp` file using a C++ compiler.
3. Execute the compiled binary.
4. Follow the on-screen instructions to choose between different sorting algorithms and provide input arrays.

## Sample Input:

The program also reads input arrays from a file named `arrays.txt`. Each line of the file represents an input array. The first character of each line indicates the size of the array, followed by space-separated integers.

## Running the Program:

To run the program:
```
$ g++ main.cpp -o sorting
$ ./sorting
```

## Contributors:

- [Mazen Wael Mahmoud]

---