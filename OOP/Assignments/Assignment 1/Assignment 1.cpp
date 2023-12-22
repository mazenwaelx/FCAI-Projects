#include <iostream>
#include <string>
using namespace std;

class PhoneBook
{
string* names;
string* phones;
int phoneBookSize;

bool validnum(string &phone)
{
    if (phone.length() != 11)
    {
        return false;
    }
    for (int i = 0; i < phone.length(); i++) {
    char c = phone[i];
    if (!isdigit(c))
    {
        return false;
    }
}
return true;
}
public:
void setSize(int); 
void copyPB(const PhoneBook&); 
bool addEntry(string& ,string&); 
bool displayEntryAtIndex(int);
void displayEntryAtIndices(int*);
void displayAll();
int* findByName(string);
string findByPhone(string);
bool updateNameAt(string, int);
bool updatePhoneAt(string, int);
void clear(); 
};

void PhoneBook::setSize(int size) {
    phoneBookSize = size;
    names = new string[size];
    phones = new string[size];
    
}
bool PhoneBook::addEntry(string& name, string& phone) 
{
    if (validnum(phone))
    {
    for (int i = 0; i < phoneBookSize; i++) {
    if (names[i] == "") 
      { // Check if entry is empty
        
        names[i] = name;
        phones[i] = phone;
        return true;
        
        }
    }
    }
    else
    {


    return false; // Phone book is full
    }
}

bool PhoneBook::displayEntryAtIndex(int index)
{
if (index >= 0 && index < phoneBookSize && names[index] != "")
{
    cout<< names[index] << " " << phones[index] << endl;
    return true;
}
return false; // if is empty or out of range
}

void PhoneBook::displayEntryAtIndices(int* indices)
{
    for (int i = 0; i < phoneBookSize; i++)
    {
        if (indices[i] == 1 && names[i] != "")
        {
            cout<< names[i] << " " << phones[i] << endl;
        }
    }
}

int* PhoneBook::findByName(string name)
{
int* arr = new int[phoneBookSize];
for (int i = 0; i < phoneBookSize; i++)
{
    
    if (names[i].find(name) != -1)
        arr[i] = 1;
    else
        arr[i] = 0;

}
return arr;
}

string PhoneBook::findByPhone(string phone)
{
    for (int i  = 0; i < phoneBookSize; i++)
    {
        if(phones[i] == phone)
        {
            return names[i];
        }
    }
    return "";
}
void PhoneBook::displayAll()
{
    for (int i = 0; i < phoneBookSize; i++)
    {
        if (names[i] != "")
        {
            cout << names[i] << " " << phones[i] << endl;
        }
}
}

bool PhoneBook::updateNameAt(string name, int index)
{
    if (index >= 0 && index < phoneBookSize)
    {
        names[index] = name;
        return true;
    }
    return false;
}


bool PhoneBook::updatePhoneAt(string phone, int index)
{
    if (index >= 0 && index < phoneBookSize)
    {
        phones[index] = phone;
        return true;
    }
    return false;
}


void PhoneBook::copyPB(const PhoneBook& pb)
{
    phoneBookSize = pb.phoneBookSize;
    names = new string[phoneBookSize];
    phones = new string[phoneBookSize];
for (int i  = 0; i < phoneBookSize; i++)
{
    names[i] = pb.names[i];
    phones[i] = pb.phones[i];
}
}
void PhoneBook::clear() {
    delete[] names;
    delete[] phones;
    names = nullptr;
    phones = nullptr;
    phoneBookSize = 0;
}




int main() {
int size;
cout << "Enter the size of the Phone Book: ";
cin >> size;

PhoneBook phonebook;
phonebook.setSize(size);

int choice;
string name, phone;
int index;
string searchString;


    
    for (int i = 0; i < size; i++)
    {
        cout<<"Enter name "<< i + 1 <<": ";
        cin.ignore();
        getline(cin,name);
        bool correctPhoneNumberEntered = false;
    do
    {
        cout<<"Enter phone "<< i + 1 <<": ";
        cin>> phone;

    if (phonebook.addEntry(name, phone)) 
        {
            correctPhoneNumberEntered = true;
        }   
    else 
        {
        cout << "Failed to add entry. Invalid phone number or phone book is full.\n";
        
        cout<<"Enter the right one "<<endl;

        
        }
            
        } while(!correctPhoneNumberEntered);
}




while(phonebook.addEntry(name, phone))
        {
            cout << "Enter your choice: "<<endl;
        cout << "1. Display Entry at Index\n";
        cout << "2. Display All Entries\n";
        cout << "3. Find by Name\n";
        cout << "4. Find by Phone\n";
        cout << "5.Update Name at Index\n";
        cout << "6. Update Phone at Index\n";
        cout << "7. Copy Phone Book\n";
        cout << "8. Exit\n";
        cout<<"choice:";
        
        cin >> choice;
    switch(choice)
    {
    case 1:
        cout << "\nEnter index: ";
        cin >> index;
        if (phonebook.displayEntryAtIndex(index)) 
        {
        cout << "Entry displayed successfully.\n";
        } 
        else 
        {
        cout << "Failed to display entry. Invalid index or entry is empty.\n";
        }
        break;
        case 2:
        phonebook.displayAll();
        break;
        case 3:
        cout << "\nEnter name or part of a name to search: ";
        cin >> searchString;
        int* nameMatches;
        nameMatches = phonebook.findByName(searchString);
        cout << "Name matches:\n";
        for (int i = 0; i < size; i++) {
        if (nameMatches[i] == 1) {
            phonebook.displayEntryAtIndex(i);
        }
        }
        delete[] nameMatches;
        break;
        case 4:
        cout << "\nEnter phone number to search: ";
        cin >> searchString;
        cout << "Name: " << phonebook.findByPhone(searchString) << endl;
        break;
        case 5:
        cout << "\nEnter new name: ";
        cin >> name;
        cout << "Enter index: ";
        cin >> index;
        if (phonebook.updateNameAt(name, index)) {
        cout << "Name updated successfully.\n";
        } else {
        cout << "Failed to update name. Invalid index.\n";
        }
        break;
    case 6:
        cout << "\nEnter new phone number: ";
        cin >> phone;
        cout << "Enter index: ";
        cin >> index;
        if (phonebook.updatePhoneAt(phone, index)) {
        cout << "Phone number updated successfully.\n";
        } else {
        cout << "Failed to update phone number. Invalid index or phone number.\n";
        }
        break;
    case 7:
        PhoneBook phoneBook2;
        phoneBook2.copyPB(phonebook);
        cout << "Phone Book copied successfully.\n";
        phoneBook2.displayAll();
        break;
    case 8:
        phonebook.clear();
        cout << "Phone Book cleared.\n";
        return 0;

    default:
        cout << "Invalid choice. Please try again.\n";
    }
        }
        
return 0;
}