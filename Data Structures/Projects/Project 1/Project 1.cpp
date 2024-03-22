#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void insertionSortLinear(int arr[], int size)
{
    int shifts = 0;
    int comparisons = 0;
    for (int i  = 1; i < size;i++)
    {
        int key = arr[i];
        int j = i - 1;
        while (j >= 0 && arr[j] > key)
        {
            ++comparisons;
            arr[j + 1] = arr[j];
            --j;
            ++shifts;
        

        }
        if (j>= 0) {

            comparisons++;
        }

        arr[j + 1] = key;

        }
    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of shifts: " << shifts << endl;
}

void insertionSortBinary(int arr[], int n)
{
    int comparisons = 0;
    int shifts = 0;

    for (int i = 1; i < n; ++i) {
        int key = arr[i];
        int low = 0;
        int high = i - 1;
        int j;


        while (low <= high) {
            int mid = low + (high - low) / 2;
            if (arr[mid] > key) {
                high = mid - 1;
            } else {
                low = mid + 1;
            }
            comparisons++;
        }


        for (j = i - 1; j >= low; --j) {
            arr[j + 1] = arr[j];
            shifts++;
        }

        arr[j + 1] = key;
    }

    cout << "Number of comparisons: " << comparisons << endl;
    cout << "Number of shifts: " << shifts << endl;
}


void PrintArray(int arr[],int size){
    for (int i = 0; i < size; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
}



void selectionSort(int arr[] , int n,int &c,int &swapss) //Task 2 functions starts from here
{
    int minIndex;
    c = 0;  swapss = 0;
    int tmp;
    for(int i = 0 ; i < n-1 ; i++) //0   1   2   3   4   5
    {                               //60  40  50  30  10  20
        minIndex  = i;

        for (int j = i + 1 ; j < n ; j++)
        {
            c++;
            if (arr[j] < arr[minIndex])
            {

                minIndex = j;

            }
        }
        tmp = arr[i];
        arr[i] = arr[minIndex];
        arr[minIndex] = tmp;
        swapss +=3;
    }
    cout << "Selection Comparisons: " << c << endl;
    cout << "Selection shifts: " << swapss<< endl;
}


void merge(int arr[], int l, int m, int r, int &comparisons, int &shifts)
{
    int i, j, k;
    int n1 = m - l + 1; // first subarray is arr[1..m]    "3-0+1 = 4"
    int n2 = r - m;     // second subarray is arr[m+1..r]     "6 - 3 = 3"
    int *L = new int[n1], *R = new int[n2];                    // dynamic array to pass the size

    for (i = 0; i < n1; i++)
        L[i] = arr[l + i];

    for (j = 0; j < n2; j++)
        R[j] = arr[m + 1 + j];

    i = j = 0;
    k = l; //0

    while (i < n1 && j < n2)
    {
        comparisons++;
        if (L[i] <= R[j])
        {
            arr[k] = L[i];
            i++;
        }
        else
        {
            arr[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1)
    {
        arr[k] = L[i];
        i++;
        k++;
    }
    while (j < n2)
    {
        arr[k] = R[j];
        j++;
        k++;
    }

    delete[] L;
    delete[] R;
}


void mergeSort(int arr[], int l, int r,int &comparisons, int &shifts ) // 60 10 20 5 60 70
{

    if (l < r)
    {
        int m = l + (r - l) / 2; //3

        mergeSort(arr, l, m, comparisons,shifts);     //for left array;
        mergeSort(arr, m + 1, r, comparisons,shifts); //for right array;

        merge(arr, l, m, r,comparisons, shifts);
    }
}

void shellSort(int arr[], int n, int & comparisons, int & swapss)
{
    comparisons = 0;
    swapss = 0;

    for (int gap = n / 2; gap > 0; gap /= 2)
    {
        for (int i = gap; i < n; i++)
        {
            int temp = arr[i];
            int j = i;

            while (j >= gap && arr[j - gap] > temp)
            {
                comparisons++;
                swapss++;   
                arr[j] = arr[j - gap];
                j -= gap;

            }
            comparisons++;
            arr[j] = temp;
        }
    }
    cout<<"Shell Comparisons: "<<comparisons<<endl;
    cout<<"Shell Shifts: "<<swapss<<endl;
}



int main()
{

    int choice1;



    do{

        cout<<"Choose between insertion by linear Or Binary: \n";
        cout<<"1.Linear\n";
        cout<<"2.Binary\n";
        cout<<"3.Exit First task\n";
        cin >> choice1;

    switch (choice1) {
        case 1: {

            int size2;
            cout << "Enter Size of the array to be sorted in Linear search: \n";
            cin >>size2;
            int arr2[size2];

            for (int i = 0;i<size2;i++) {
                cout<<"Enter element in index "<<i+1 <<" :";
                cin >>arr2[i];
            }

            cout<<"Array Unsorted: \n";
            PrintArray(arr2,size2);
            insertionSortLinear( arr2, size2);
            cout << "Array Sorted with Linear search: \n";
            PrintArray(arr2,size2);
            break;
        }

        case 2: {

            int size;
            cout << "Enter Size of the array to be sorted in Binary search: \n";
            cin >>size;
            int arr[size];

            for (int i = 0;i<size;i++) {
                cout<<"Enter element in index "<<i+1 <<" :";
                cin >>arr[i];
            }

            cout<<"Array Unsorted: \n";

            PrintArray(arr,size);
            insertionSortBinary(arr, size);
            cout << "Array Sorted with Binary search: \n";
            PrintArray(arr,size);
            break;
        }

        case 3: {

            cout<<"Thanks for using out Linear and Binary Search using Insertion Sort \n";
            cout<<"Welcome to task2 \n";
            break;
        }

    }

    }while(choice1 != 3);


    string FileName = "arrays.txt";
    ifstream file(FileName);

    if (file.is_open()) {

        string line;

        while (getline(file, line)) {
            int size = line[0] - '0';
            int *array1 = new int[size];
            int *array2 = new int[size];
            int *array3 = new int[size];


            int index = 2;
            int arrayIndex = 0;
            while (index < line.length()) {
                string digit = "";
                while (index < line.length() && line[index] != ' ') {
                    digit += line[index];
                    index++;
                }
                array1[arrayIndex] = stoi(digit);
                array2[arrayIndex] = stoi(digit);
                array3[arrayIndex] = stoi(digit);
                arrayIndex++;
                index++;
            }


                int selectionComparisons = 0, selectionShifts = 0;
                cout << "The array before sorting By Selection Sort: ";
                PrintArray(array1, size);
                selectionSort(array1, size, selectionComparisons, selectionShifts);
                cout << "The array after Sorting by Selection Sort: ";
                PrintArray(array1, size);


                cout<<"--------------------------------------------------------------------------------------------\n";

                int shellComparisons = 0, shellShifts = 0;
                cout << "The array before sorting By Shell Sort: " << endl;
                PrintArray(array2, size);
                shellSort(array2, size, shellComparisons, shellShifts);
                cout << "The array after sorting by Shell Sort: " << endl;
                PrintArray(array2, size);
                cout<<"--------------------------------------------------------------------------------------------\n";

                int mergeComparisons = 0, mergeShifts = 0;
                cout << "The array before sorting By Merge Sort: " << endl;
                PrintArray(array3, size);
                mergeSort(array3, 0, size - 1, mergeComparisons, mergeShifts);
                cout << "The array after sorting by Merge Sort: " << endl;
                PrintArray(array3, size);
                cout<<"Merge Comparisons: "<<mergeComparisons<<endl;
                cout<<"Merge Shifts: "<<mergeShifts<<endl;

                cout<<"--------------------------------------------------------------------------------------------\n";



                delete[] array1;
                delete[] array2;
                delete[] array3;

                }

                file.close();
            }


    return 0;
}