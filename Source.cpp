#include <iostream>
#include <string>
using namespace std;

// Maximum number of contacts stored in the address book
#define Max 1000 // maximum number

// Define a structure for a contact
struct Contacts
{
    string cName;       // Name
    int cGender = 1;    // Gender
    int cAge = 0;       // Age
    string cPhone;      // Phone number
    string cAdd;        // Address
};

// Define a structure for the address book
struct AddressBooks
{
    Contacts contactsArray[Max];    // Array of contact information in the address book
    int aCount = 0;                  // Number of people in the address book
};

// Display the main menu
void showMenu()
{
    cout << "********************************" << endl;
    cout << "***** Address Book Management System *****" << endl;
    cout << "********************************" << endl;
    cout << "*****      1. Add Contact      *****" << endl;
    cout << "*****      2. Show Contacts    *****" << endl;
    cout << "*****      3. Delete Contact   *****" << endl;
    cout << "*****      4. Search Contact   *****" << endl;
    cout << "*****      5. Modify Contact   *****" << endl;
    cout << "*****      6. Clear Contacts   *****" << endl;
    cout << "*****      0. Exit Address Book *****" << endl;
    cout << "********************************" << endl;
    cout << "*********** Version 1.0 *********" << endl;
    cout << "********************************" << endl;
}

// Add a contact
void AddContacts(AddressBooks* abs)
{
    // Check if the address book is full
    if (abs->aCount == Max)
    {
        cout << "Address book is full, cannot add more!" << endl;
        return;
    }
    else
    {
        // Name
        string name;
        cout << "Enter name: " << endl;
        cin >> name;
        abs->contactsArray[abs->aCount].cName = name;

        // Gender
        int gender;
        cout << "Enter gender: " << endl;
        cout << "1 ---- Male " << endl;
        cout << "2 ---- Female " << endl;

        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                abs->contactsArray[abs->aCount].cGender = gender;
                break;
            }
            cout << "Invalid input, please try again!" << endl;
        }

        // Age
        int age;
        cout << "Enter age: " << endl;
        cin >> age;
        abs->contactsArray[abs->aCount].cAge = age;

        // Phone number
        string phone;
        cout << "Enter phone number: " << endl;
        cin >> phone;
        abs->contactsArray[abs->aCount].cPhone = phone;

        // Address
        string add;
        cout << "Enter address: " << endl;
        cin >> add;
        abs->contactsArray[abs->aCount].cAdd = add;

        // Increment count
        abs->aCount += 1;
        cout << "Added successfully!" << endl;
        system("pause");
        system("cls");
    }
}

// Display contacts
void ShowContacts(AddressBooks* abs)
{
    if (abs->aCount == 0)
    {
        cout << "No contacts, please add some!" << endl;
    }
    else
    {
        // Display all contacts
        for (int i = 0; i < abs->aCount; i++)
        {
            cout << "Name: " << abs->contactsArray[i].cName << " Gender: " << (abs->contactsArray[i].cGender != 2 ? "Male" : "Female") << " Age: " << abs->contactsArray[i].cAge << " Phone: " << abs->contactsArray[i].cPhone << " Address: " << abs->contactsArray[i].cAdd << endl;
        }
    }
    system("pause");
    system("cls");
}

// Check if a person exists
int IsExit(AddressBooks* abs, string name)
{
    for (int i = 0; i < abs->aCount; i++)
    {
        if (abs->contactsArray[i].cName == name)
        {
            return i;
        }
    }
    return -1;
}

// Delete a contact
void DeleteContacts(AddressBooks* abs)
{
    // Record the name entered by the user
    string name;
    cout << "Enter the name of the user you want to delete: " << endl;
    cin >> name;
    // Check if the contact exists
    int index = IsExit(abs, name);
    // If it exists
    if (index > -1)
    {
        for (int i = index; i < abs->aCount - 1; i++)
        {
            // Shift operation to the front
            Contacts temp = abs->contactsArray[i];
            abs->contactsArray[i] = abs->contactsArray[i + 1];
            abs->contactsArray[i + 1] = temp;
        }
        // Decrease the count
        abs->aCount--;
        cout << "Deleted successfully!" << endl;
    }
    else// If it does not exist
    {
        cout << "No such person found" << endl;
    }
    system("pause");
    system("cls");
}

// Search for a contact
void GetContacts(AddressBooks* abs)
{
    // Record the name entered by the user
    string name;
    cout << "Enter the name of the user you want to search for: " << endl;
    cin >> name;
    // Check if the contact exists
    int index = IsExit(abs, name);
    if (index > -1)
    {
        // If it exists
        cout << "Name: " << abs->contactsArray[index].cName << endl;
        cout << "Gender: " << abs->contactsArray[index].cGender << endl;
        cout << "Age: " << abs->contactsArray[index].cAge << endl;
        cout << "Phone: " << abs->contactsArray[index].cPhone << endl;
        cout << "Address: " << abs->contactsArray[index].cAdd << endl;
    }
    else
    {
        // If it does not exist
        cout << "No such person found" << endl;
    }
    system("pause");
    system("cls");
}

// Modify a contact
void ModefyContacts(AddressBooks* abs)
{
    // Record the name entered by the user
    string name;
    cout << "Enter the name of the user you want to modify: " << endl;
    cin >> name;
    // Check if the contact exists
    int index = IsExit(abs, name);
    if (index > -1)
    {
        // If it exists
        // Name
        string name;
        cout << "Enter the modified name: " << endl;
        cin >> name;
        abs->contactsArray[index].cName = name;

        // Gender
        int gender;
        cout << "Enter the modified gender: " << endl;
        cout << "1 ---- Male " << endl;
        cout << "2 ---- Female " << endl;

        while (true)
        {
            cin >> gender;
            if (gender == 1 || gender == 2)
            {
                abs->contactsArray[index].cGender = gender;
                break;
            }
            cout << "Invalid input, please try again!" << endl;
        }

        // Age
        int age;
        cout << "Enter the modified age: " << endl;
        cin >> age;
        abs->contactsArray[index].cAge = age;

        // Phone
        string phone;
        cout << "Enter the modified phone number: " << endl;
        cin >> phone;
        abs->contactsArray[index].cPhone = phone;

        // Address
        string add;
        cout << "Enter the modified address: " << endl;
        cin >> add;
        abs->contactsArray[index].cAdd = add;
        cout << "Modification successful!" << endl;
    }
    else
    {
        // If it does not exist
        cout << "No such person found" << endl;
    }
    system("pause");
    system("cls");
}

// Clear contacts
void ClearContacts(AddressBooks* abs)
{
    string choose = "N";
    cout << "Are you sure you want to clear the address book? (Y for Yes/N for No)" << endl;

    while (true)
    {
        cin >> choose;
        if (choose == "Y" || choose == "N")
        {
            break;
        }
        else
        {
            cout << "Invalid input, please try again!" << endl;
        }
    }

    if (choose == "Y")
    {
        abs->aCount = 0;
        cout << "Cleared successfully!" << endl;
    }
    else
    {
        cout << "Operation canceled!" << endl;
    }
    system("pause");
    system("cls");
}


int main()
{
    // Record user input information
    int select = 0;
    // Define an address book structure
    AddressBooks abs;
    // Set current count to zero
    abs.aCount = 0;

    while (true)
    {
        // Display main menu
        showMenu();

        cin >> select;
        switch (select)
        {
        case 1://1. Add contact
            AddContacts(&abs);  // Pass by address
            break;
        case 2://2. Show contacts
            ShowContacts(&abs); // Pass by address
            break;
        case 3://3. Delete contact
            DeleteContacts(&abs);
            break;
        case 4://4. Search contact
            GetContacts(&abs);
            break;
        case 5://5. Modify contact
            ModefyContacts(&abs);
            break;
        case 6://6. Clear contacts
            ClearContacts(&abs);
            break;
        case 0://0. Exit address book
            cout << "Welcome back, goodbye!" << endl;
            system("pause");
            return 0;
            break;
        default:
            break;
        }
    }

    system("pause");// Press any key to continue
    return 0;
}
