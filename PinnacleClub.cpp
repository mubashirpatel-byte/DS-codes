# Pinnacle Club
#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node
{
    int PRN;
    string name;
    Node* next;
};

// Head pointer
Node* head = NULL;


// Create a new node
Node* createNode(int prn, string name)
{
    Node* newNode = new Node;

    newNode->PRN = prn;
    newNode->name = name;
    newNode->next = NULL;

    return newNode;
}


// Add President
void addPresident()
{
    int prn;
    string name;

    cout << "Enter President PRN: ";
    cin >> prn;

    cout << "Enter President Name: ";
    cin >> name;

    Node* newNode = createNode(prn, name);

    newNode->next = head;
    head = newNode;

    cout << "President added successfully.\n";
}


// Add Secretary
void addSecretary()
{
    int prn;
    string name;

    cout << "Enter Secretary PRN: ";
    cin >> prn;

    cout << "Enter Secretary Name: ";
    cin >> name;

    Node* newNode = createNode(prn, name);

    if (head == NULL)
    {
        head = newNode;
    }
    else
    {
        Node* temp = head;

        while (temp->next != NULL)
        {
            temp = temp->next;
        }

        temp->next = newNode;
    }

    cout << "Secretary added successfully.\n";
}


// Add member before Secretary
void addMember()
{
    int prn;
    string name;

    cout << "Enter Member PRN: ";
    cin >> prn;

    cout << "Enter Member Name: ";
    cin >> name;

    Node* newNode = createNode(prn, name);

    // If no members exist
    if (head == NULL)
    {
        head = newNode;
        cout << "Member added successfully.\n";
        return;
    }

    Node* temp = head;

    // Move to the node before secretary
    while (temp->next != NULL && temp->next->next != NULL)
    {
        temp = temp->next;
    }

    newNode->next = temp->next;
    temp->next = newNode;

    cout << "Member added successfully.\n";
}


// Delete President
void deletePresident()
{
    if (head == NULL)
    {
        cout << "Club is empty.\n";
        return;
    }

    Node* temp = head;
    head = head->next;

    delete temp;

    cout << "President deleted successfully.\n";
}


// Delete Secretary
void deleteSecretary()
{
    if (head == NULL)
    {
        cout << "Club is empty.\n";
        return;
    }

    // Only one node
    if (head->next == NULL)
    {
        delete head;
        head = NULL;

        cout << "Secretary deleted successfully.\n";
        return;
    }

    Node* temp = head;

    while (temp->next->next != NULL)
    {
        temp = temp->next;
    }

    delete temp->next;
    temp->next = NULL;

    cout << "Secretary deleted successfully.\n";
}


// Delete member using PRN
void deleteMember()
{
    if (head == NULL)
    {
        cout << "Club is empty.\n";
        return;
    }

    int prn;
    cout << "Enter PRN of member to delete: ";
    cin >> prn;

    // If first node is selected
    if (head->PRN == prn)
    {
        deletePresident();
        return;
    }

    Node* temp = head;

    while (temp->next != NULL && temp->next->PRN != prn)
    {
        temp = temp->next;
    }

    if (temp->next == NULL)
    {
        cout << "Member not found.\n";
        return;
    }

    Node* deleteNode = temp->next;
    temp->next = deleteNode->next;

    delete deleteNode;

    cout << "Member deleted successfully.\n";
}


// Count total members
void countMembers()
{
    int count = 0;

    Node* temp = head;

    while (temp != NULL)
    {
        count++;
        temp = temp->next;
    }

    cout << "Total number of club members: " << count << endl;
}


// Display all members
void displayMembers()
{
    if (head == NULL)
    {
        cout << "Club is empty.\n";
        return;
    }

    Node* temp = head;
    int count = 1;

    cout << "\n========== PINNACLE CLUB MEMBERS ==========\n";

    while (temp != NULL)
    {
        if (count == 1)
            cout << "President : ";
        else if (temp->next == NULL)
            cout << "Secretary : ";
        else
cout << "Member    : ";

        cout << "PRN = " << temp->PRN
             << ", Name = " << temp->name << endl;

        temp = temp->next;
        count++;
    }

    cout << "===========================================\n";
}


// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n========== PINNACLE CLUB ==========\n";
        cout << "1. Add President\n";
        cout << "2. Add Member\n";
        cout << "3. Add Secretary\n";
        cout << "4. Delete President\n";
        cout << "5. Delete Member\n";
        cout << "6. Delete Secretary\n";
        cout << "7. Count Members\n";
        cout << "8. Display Members\n";
        cout << "9. Exit\n";
        cout << "===================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addPresident();
                break;

            case 2:
                addMember();
                break;

            case 3:
                addSecretary();
                break;

            case 4:
                deletePresident();
                break;

            case 5:
                deleteMember();
                break;

            case 6:
                deleteSecretary();
                break;

            case 7:
                countMembers();
                break;

            case 8:
                displayMembers();
                break;

            case 9:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 9);

    return 0;
}