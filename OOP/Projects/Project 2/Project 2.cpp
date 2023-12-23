#include <iostream>
#include <string>

using namespace std;

class Point
{
private:
    int x;
    int y;

public:

    //defult constructor
    Point():x(0), y(0) {}
    // paramterized constructor
    Point(int a, int b)
    {
        x = a;
        y = b;
    }

    void setx(int a) // setter for x
    {
        x = a;
    }

    void sety(int b) // setter for y
    {
        y = b;
    }

    int getx() const // getter for x
    {
        return x;
    }

    int gety() const // getter for y
    {
        return y;
    }

    void displayinfo() const
    {
        cout << "(" << x << ", " << y << ")";
    }
};

class PointsArray
{
private:
    Point **array; // 2D dynamic array
    int rows;
    int columns;

public:
    // 0-setpoint func
    void setpoint(int,int, Point&);
    // 1-constructor
    PointsArray(int numrows, int numcols)
    {
        rows = numrows;
        columns = numcols;

        array = new Point *[rows];
        for (int i = 0; i < rows; i++)
        {
            array[i] = new Point[columns];
        }
    }

    // 2-copy constructor
    PointsArray(const PointsArray &array2)
    {
        rows = array2.rows;
        columns = array2.columns;

        array = new Point *[rows];
        for (int i = 0; i < rows; i++)
        {
            array[i] = new Point[columns];

            // copy the elements
            for (int j = 0; j < columns; j++)
            {
                array[i][j] = array2.array[i][j];
            }
        }
    }

    // destructor
    ~PointsArray()
    {
        for (int i = 0; i < rows; i++)
        {
            delete[] array[i];
        }
        delete[] array;
    }

    //3-Getter for the rows
    int getRows() const
    {
        return rows;
    }
    //3-Getter for the columns
    int getColumns()
    {
        return columns;
    }
    // 7-overloading operator=
    PointsArray& operator= (const PointsArray& array3)
    {
        if (this == &array3)
        {
            return *this;
        }
            for (int i = 0; i < rows; i++)
            {
                delete[] array[i];
            }
            delete[] array;
            rows = array3.rows;
            columns = array3.columns;

        array = new Point*[rows];
        for (int i = 0; i < rows; i++)
        {
            array[i] = new Point[columns];
            for (int j = 0; j < columns; j++)
            {
                array[i][j] = array3.array[i][j];
            }
        }

        return *this;
    }

    friend istream &operator>>(istream &is, PointsArray &pointsArray);
    friend ostream &operator<<(ostream &os, PointsArray &pointsArray);

//9- operator+ overload
    PointsArray operator+(int);

// 10- swap rows func
    void swapRows(int,int);

// 11- delete column func
    void deleteColumn(int);

//12- add column function
void addColumn(int, Point*);

//13- print matrix func
void printMatrix() const;

};

// 5-input values by istream (overloaded)
istream &operator>>(istream &is, PointsArray &pointsArray)
{
    for (int i = 0; i < pointsArray.getRows(); i++)
    {
        for (int j = 0; j < pointsArray.getColumns(); j++)
        {
            cout << "Put the coordinates of element [" << i << " , " << j << "]: ";
            int x;
            int y;
            is >> x >> y;

            pointsArray.array[i][j] = Point(x, y);
        }
    }
    return is;
}

//6- output values by ostream (overloaded)
ostream &operator<<(ostream &os, PointsArray &pointsArray)
{
    for (int i = 0; i < pointsArray.getRows(); i++)
    {
        for (int j = 0; j < pointsArray.getColumns(); j++)
        {
            os << "( " << pointsArray.array[i][j].getx() << " , " << pointsArray.array[i][j].gety() << " ) ";
        }
        os << endl;
    }
    return os;
}
// 8- setpoint function
void PointsArray::setpoint(int numrows,int numcols, Point& point)
{
    if (numrows >= 0 && numrows < rows && numcols >= 0 && numcols < columns) {
        array[numrows][numcols] = point;
    }
}
// 9-operator+ overloading
PointsArray PointsArray:: operator+(int value)
{
    PointsArray result(rows,columns);
    for(int i = 0; i < rows; i++)
    {
        for (int j = 0; j < columns; j++)
        {
            result.array[i][j].setx(array[i][j].getx() + value);
            result.array[i][j].sety(array[i][j].gety() + value);

        }
    }
    return result;
}
// 10- swap rows func
void PointsArray::swapRows(int numrow1, int numrow2)
{
    if (numrow1 >= 0 && numrow1 < rows && numrow2 >= 0 && numrow2 < rows)
    {
        Point *temp = array[numrow1];
        array[numrow1] = array[numrow2];
        array[numrow2] = temp;
    }
}


//11- delete column function
void PointsArray::deleteColumn(int numcols)
{
if (numcols >= 0 && numcols < columns)
{
    for (int i  = 0; i < rows; i++)
    {
        for (int j = numcols; j < columns; j++)
        {
            array[i][j] = array[i][j + 1];
        }
    }
    columns--;
}
}


// 12- add column func

void PointsArray::addColumn(int numcols, Point* array5)
{
    if (numcols < 0 || numcols > columns)
    {
        return;
    }

    Point** newArray = new Point*[rows];
    for (int i = 0; i < rows; i++)
    {
        newArray[i] = new Point[columns + 1];
    }

    for (int i = 0; i < rows; i++)
    {
        int destColumn = 0;
        for (int j = 0; j <= columns; j++) {
            if (j == numcols)
            {
                newArray[i][j] = array5[i];
            } else
            {
                newArray[i][j] = array[i][destColumn++];
            }
        }
    }

    for (int i = 0; i < rows; i++)
    {
        delete[] array[i];
    }
    delete[] array;

    array = newArray;
    columns++;
}


//13- print matrix func
void PointsArray::printMatrix() const {
    for (int i = 0; i < rows; i++) 
    {
        for (int j = 0; j < columns; j++) {
            cout << "(" << array[i][j].getx() << ", " << array[i][j].gety() << ") ";
        }
        cout << endl;
    }
}






int main() {
    PointsArray Array1(0, 0);
    int choice;

    do {
        cout<<"\n\t Main Menu\t\n";

        cout<<"\n==========================\n";
        cout<<"\n==========================\n\n";

        cout<<"Note this application will close when you chose case 12\n";

        cout<<"1 - Initialize PointArray "<<endl;
        cout<<"2 - copy pointsArray "<<endl;
        cout<<"3 - Display Number of Rows "<<endl;
        cout<<"4 - Display NUmber of columns "<<endl;
        cout<<"5 - Enter PointsArray Elements "<<endl;
        cout<<"6 - Display PointArray Elements "<<endl;
        cout<<"7 - Add Integer to pointArray "<<endl;
        cout<<"8 - Swap Rows "<<endl;
        cout<<"9 - Delete Column "<<endl;
        cout<<"10 - Add Column "<<endl;
        cout<<"11 - Print PointArray as Matrix "<<endl;
        cout<<"12 - Exit"<<endl;

        cout<<"Enter the choice You want to see: ";
        cin>>choice;
        switch (choice) {
            case 1: {
                int rows, columns;
                cout << "Enter the number of rows: ";
                cin >> rows;
                cout << "Enter the number of columns: ";
                cin >> columns;
                Array1 = PointsArray(rows, columns);
                cout << "PointsArray initialized." << endl;
                break;
            }
            case 2: {
                PointsArray Array2 = Array1;
                cout << "Copy of PointsArray created:" << endl;
                cout << Array2 << endl;
                break;
            }
            case 3: {
                cout << "Number of rows: " << Array1.getRows() << endl;
                break;
            }
            case 4: {
                cout << "Number of columns: " << Array1.getColumns() << endl;
                break;
            }
            case 5: {
                cout << "Enter values for the PointsArray object:" << endl;
                cin >> Array1;
                break;
            }
            case 6: {
                cout << "your Array Elements:" << endl;
                cout << Array1 << endl;
                break;
            }
            case 7: {
                int value;
                cout << "Enter an integer value: ";
                cin >> value;
                Array1 = Array1 + value;
                cout << "Integer added to PointsArray." << endl;
                break;
            }
            case 8: {
                int row1, row2;
                cout << "Enter the row numbers to swap: ";
                cin >> row1 >> row2;
                Array1.swapRows(row1, row2);
                cout << "Rows swapped." << endl;
                break;
            }
            case 9: {
                int column;
                cout << "Enter the column to delete: ";
                cin >> column;
                Array1.deleteColumn(column);
                cout << "Column deleted." << endl;
                break;
            }
            case 10: {
                int column;
                cout << "Enter the column index to add: ";
                cin >> column;

                Point* newColumn = new Point[Array1.getRows()];
                cout << "Enter " << Array1.getRows() << " points for the new column:" << endl;
                for (int i = 0; i < Array1.getRows(); i++) {
                    int x, y;
                    cout << "Enter X coordinate for point " << i << ": ";
                    cin >> x;
                    cout << "Enter Y coordinate for point " << i << ": ";
                    cin >> y;
                    newColumn[i].setx(x);
                    newColumn[i].sety(y);
                }

                Array1.addColumn(column, newColumn);
                delete[] newColumn;
                cout << "Column added." << endl;
                break;
            }
            case 11: {
                cout << "PointsArray as Matrix:" << endl;
                Array1.printMatrix();
                break;
            }
            case 12: {
                cout << "Exiting..." << endl;
                break;
            }
            default: {
                cout << "Invalid choice. Please try again." << endl;
                break;
            }
        }

        cout << endl;

    } while (choice != 12);

    return 0;
}