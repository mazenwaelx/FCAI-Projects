#include <iostream>
#include <fstream>
#include <algorithm>
using namespace std;

template<class T>
class MultiArray
{
private:
    struct Array
    {
        string name;
        T* data;
        int size;

        Array() : data(nullptr), size(0) {}

        Array(string n, int s) : name(n), size(s)
        {
            data = new T[size];
        }

        ~Array()
        {
            delete[] data;
        }
    };

    Array* arrays;
    int numArrays;
    int mergedSize;

public:
    MultiArray(int numA, int* sizes, string* names) : numArrays(numA), mergedSize(0)
    {
        arrays = new Array[numA];
        for (int i = 0; i < numA; i++)
        {
            arrays[i] = Array(names[i], sizes[i]);
        }
    }

    ~MultiArray()
    {
        for (int i = 0; i < numArrays; ++i)
        {
            delete[] arrays[i].data;
        }
        delete[] arrays;
    }

    MultiArray(const MultiArray& other) : numArrays(other.numArrays), mergedSize(other.mergedSize)
    {
        arrays = new Array[numArrays]();
        for (int i = 0; i < numArrays; ++i)
        {
            arrays[i] = Array(other.arrays[i]);
        }
    }

    int getMergedSize() const
    {
        return mergedSize;
    }

    void loadFromFile(string arrName, string fileName)
    {
        for (int i = 0; i < numArrays; i++)
        {
            if (arrays[i].name == arrName)
            {
                ifstream file(fileName);
                if (file.is_open())
                {
                    for (int j = 0; j < arrays[i].size; ++j)
                    {
                        file >> arrays[i].data[j];
                    }
                    file.close();
                }
                else
                {
                    cout << "Unable to open file: " << fileName << endl;
                }
                return;
            }
        }

        cout << "Array with name: " << arrName << " not found." << endl;
    }

    T* subArray(string name, int startIndex, int endIndex, int step = 1)
    {
        for (int i = 0; i < numArrays; i++)
        {
            if (arrays[i].name == name)
            {
                int subSize = (endIndex - startIndex) / step + 1;
                T* result = new T[subSize];

                int resultIndex = 0;
                for (int j = startIndex; j <= endIndex; j += step)
                {
                    result[resultIndex++] = arrays[i].data[j];
                }

                return result;
            }
        }

        cout << "Array with name: " << name << " not found." << endl;
        return nullptr;
    }

    void reverse(std::string name)
    {
        for (int i = 0; i < numArrays; i++)
        {
            if (arrays[i].name == name)
            {
                int start = 0;
                int end = arrays[i].size - 1;

                while (start < end)
                {
                    T temp = arrays[i].data[start];
                    arrays[i].data[start] = arrays[i].data[end];
                    arrays[i].data[end] = temp;

                    start++;
                    end--;
                }

                return;
            }
        }

        cout << "Array with name " << name << " not found." << endl;
    }

    void sort(string name)
    {
        for (int i = 0; i < numArrays; i++)
        {
            if (arrays[i].name == name)
            {
                for (int j = 0; j < arrays[i].size - 1; j++)
                {
                    for (int k = 0; k < arrays[i].size - j - 1; k++)
                    {
                        if (arrays[i].data[k] > arrays[i].data[k + 1])
                        {
                            T temp = arrays[i].data[k];
                            arrays[i].data[k] = arrays[i].data[k + 1];
                            arrays[i].data[k + 1] = temp;
                        }
                    }
                }
                return;
            }
        }

        cout << "Array with name " << name << " not found." << endl;
    }

    bool search(T item)
    {
        for (int i = 0; i < numArrays; i++)
        {
            for (int j = 0; j < arrays[i].size; ++j)
            {
                if (arrays[i].data[j] == item)
                {
                    return true;
                }
            }
        }
        return false; // Add a return statement for the case when item is not found
    }

    T& operator()(const std::string& name, int index)
    {
        for (int i = 0; i < numArrays; i++)
        {
            if (arrays[i].name == name)
            {
                if (index < 0 || index >= arrays[i].size)
                {
                    // Handle index out of bounds
                    cerr << "Index out of bounds for array " << name << endl;

                    return arrays[i].data[0];
                }
                return arrays[i].data[index];
            }
        }

        cerr << "Array with name " << name << " not found." << endl;

        return arrays[0].data[0];
    }


    void setArrayData(string name, T* data, int index = 0)
    {
        for (int i = 0; i < numArrays; i++)
        {
            if (arrays[i].name == name)
            {
                arrays[i].data = data;
                for (int j = 0; j < arrays[i].size; j++)
                {
                    arrays[i].data[j] = data[j + index];
                }
                return;
            }
        }
        cout << "Array with name " << name << " not found. " << endl;
    }


MultiArray split(string name)
{
    for (int i = 0; i < numArrays; i++)
    {
        if (arrays[i].name == name)
        {
            int firstSize = arrays[i].size / 2;
            int secondSize = arrays[i].size - firstSize;

            // Use the same names for the split arrays
            MultiArray result(2, new int[2]{firstSize, secondSize}, new string[2]{arrays[i].name + "_First", arrays[i].name + "_Second"});

            // Copy data to the split arrays
            for (int j = 0; j < firstSize; j++)
            {
                result(arrays[i].name + "_First", j) = arrays[i].data[j];
            }

            for (int j = 0; j < secondSize; j++)
            {
                result(arrays[i].name + "_Second", j) = arrays[i].data[firstSize + j];
            }

            // Update mergedSize
            result.mergedSize = arrays[i].size;

            return result;
        }
    }

    cout << "Array with name " << name << " not found. " << endl;
    return MultiArray(0, nullptr, nullptr);
}




    T* merge()
    {
        int totalSize = 0;

        for (int i = 0; i < numArrays; i++)
        {
            totalSize += arrays[i].size;
        }

        mergedSize = totalSize;

        T* merged = new T[totalSize];

        int currentIndex = 0;

        for (int i = 0; i < numArrays; i++)
        {
            for (int j = 0; j < arrays[i].size; j++)
            {
                merged[currentIndex++] = arrays[i].data[j];
            }
        }

        return merged;
    }

    void applyToArray(string name, void (*func)(T&))
    {
        for (int i = 0; i < numArrays; i++)
        {
            if (arrays[i].name == name)
            {
                for (int j = 0; j < arrays[i].size; j++)
                {
                    func(arrays[i].data[j]);
                }
                return;
            }
        }

        cout << "Array with name " << name << " not found." << endl;
    }

    friend ostream& operator<<(ostream& os, const MultiArray<T>& ms)
    {
        for (int i = 0; i < ms.numArrays; i++)
        {
            os << "Array name: " << ms.arrays[i].name << endl;
            os << "Array elements: " << endl;
            for (int j = 0; j < ms.arrays[i].size; j++)
            {
                os << ms.arrays[i].data[j] << " ";
            }
            os << endl;
            os << endl;
        }
        return os;
    }
};

template <class T2>
void square(T2& x)
{
    x *= x;
}

int main() {
    int sizes[] = {5, 3};
    string names[] = {"Array1", "Array2"};
    MultiArray<int> myArrays(2, sizes, names);

    myArrays.loadFromFile("Array1", "file1.txt");
    myArrays.loadFromFile("Array2", "file2.txt");

    cout << "Original MultiArrays:" << endl;
    cout << myArrays;
    int arraynumber;

    do {
        cout << "\tMenu\t";
        cout << "\n========================\n";
        int choice;
        cout << "1-Reverse Array";
        cout << "\n===================\n";
        cout << "2-Sorting  Array";
        cout << "\n===================\n";
        cout << "3-Search for an item";
        cout << "\n===================\n";
        cout << "4-Apply Square function";
        cout << "\n===================\n";
        cout << "5-Sub Array";
        cout << "\n===================\n";
        cout << "6-Merged Array";
        cout << "\n===================\n";
        cout << "7-split Array";
        cout << "\n===================\n";
        cout << "8-exit";
        cout << "\n===================\n";
        cout << "Enter the number You want to test : " ;
        cin >> choice;

        switch (choice) {
            // Reverse array
            case 1: {
                cout << "what array you want to reverse? (1/2)" << endl;
                cin >> arraynumber;
                // choose the array number
                if (arraynumber == 1) {
                    myArrays.reverse("Array1");
                } else if (arraynumber == 2) {
                    myArrays.reverse("Array2");
                } else {
                    cout << "Invalid array number. Please enter 1 or 2." << endl;
                }
                cout << "Array1 and Array 2 after reversal:" << endl;
                cout << myArrays;
                break;
            }
            case 2: {
                int startindex, endindex;
                cout << "Enter the array number you want to sort (1/2): " << endl;
                cin >> arraynumber;

                // Assuming arraynumber is either 1 or 2
                if (arraynumber == 1) {
                    cout << "Enter the start index: ";
                    cin >> startindex;
                    cout << "Enter the end index: ";
                    cin >> endindex;
                    myArrays.sort("Array1");
                    cout << "Array1 after sorting:" << endl;
                    cout << myArrays;
                } else if (arraynumber == 2) {
                    cout << "Enter the start index: ";
                    cin >> startindex;
                    cout << "Enter the end index: ";
                    cin >> endindex;
                    myArrays.sort("Array2");
                    cout << "Array2 after sorting:" << endl;
                    cout << myArrays;
                } else {
                    cout << "Invalid array number. Please enter 1 or 2." << endl;
                }
                break;
            }
            case 3: {
                cout << "Enter an integer to search for it in arrays: ";
                int number;
                cin >> number;
                if (myArrays.search(number)) {
                    cout << "Item " << number << " found in one of the arrays." << endl;
                } else {
                    cout << "Item " << number << " not found in any of the arrays." << endl;
                }
                break;
            }
            case 4: {
                cout << "Choose what Array do you want to Square (1/2): " << endl;
                cin >> arraynumber;
                if (arraynumber == 1) {
                    cout << "Array one before square is" << endl;
                    cout << myArrays << endl;
                    myArrays.applyToArray("Array1", square<int>);
                    cout << "Array one after square is: " << endl;
                    cout << myArrays << endl;
                } else if (arraynumber == 2) {
                    cout << "Array two before square is" << endl;
                    cout << myArrays << endl;
                    cout << "Array two after square is: " << endl;
                    myArrays.applyToArray("Array2", square<int>);
                    cout << myArrays;
                } else {
                    cout << "Wrong input, Please Try Again " << endl;
                }
                break;
            }
            case 5: {
                int startindex, endindex;
                cout << "Choose what subarray you want to choose: (1/2)";
                cin >> arraynumber;
                cout << "Enter the start index: ";
                cin >> startindex;
                cout << "Enter the end index: ";
                cin >> endindex;
                int* subArr = myArrays.subArray("Array1", startindex, endindex);
                cout << "Subarray of Array:" << endl;
                for (int i = 0; i < (endindex - startindex) + 1; i++) {
                    cout << subArr[i] << " ";
                }
                cout << endl;
                delete[] subArr;
                break;
            }
            case 6: {
                int* mergedArr = myArrays.merge();
                cout << "Merged Array:" << endl;
                for (int i = 0; i < myArrays.getMergedSize(); i++) {
                    cout << mergedArr[i] << " ";
                }
                cout << endl;
                delete[] mergedArr;
                break;
            }
            case 7: {
            cout << "Choose what array you want to split: (Array1/Array2)";
                string arrayname;
                cin >> arrayname;
                MultiArray<int> splitArrays = myArrays.split(arrayname);
                cout << "Split Arrays:" << endl;
                cout << splitArrays;
                break;
            }
            case 8: {
                cout << "Thanks for using the program" << endl;
                break;
            }
            default:
                cout << "Error wrong input " << endl;
                break;
        }
    } while (arraynumber != 8);

    return 0;
}