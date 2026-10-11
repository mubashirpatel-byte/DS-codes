#multiplayer game
#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node
{
    string name;
    Node* next;
};

Node* current = NULL;


// Add a player
void addPlayer()
{
    string name;

    cout << "Enter player name: ";
    cin >> name;

    Node* newNode = new Node;
    newNode->name = name;

    // If list is empty
    if (current == NULL)
    {
        current = newNode;
        newNode->next = current;
    }
    else
    {
        Node* temp = current;

        // Find last node
        while (temp->next != current)
        {
            temp = temp->next;
        }

        newNode->next = current;
        temp->next = newNode;
    }

    cout << "Player added successfully.\n";
}


// Remove a player
void removePlayer()
{
    if (current == NULL)
    {
        cout << "No players in the game.\n";
        return;
    }

    string name;
    cout << "Enter player name to remove: ";
    cin >> name;

    Node* temp = current;
    Node* prev = NULL;

    // Search for player
    do
    {
        if (temp->name == name)
        {
            break;
        }

        prev = temp;
        temp = temp->next;

    } while (temp != current);

    // Player not found
    if (temp->name != name)
    {
        cout << "Player not found.\n";
        return;
    }

    // Only one player
    if (temp == current && temp->next == current)
    {
        delete temp;
        current = NULL;
    }
    else
    {
        // Find previous node if deleting current
        if (prev == NULL)
        {
            prev = current;

            while (prev->next != current)
            {
                prev = prev->next;
            }
        }

        prev->next = temp->next;

        // If current player is removed,
        // move current to next player
        if (temp == current)
        {
            current = temp->next;
        }

        delete temp;
    }

    cout << "Player removed successfully.\n";
}


// Move to next player
void nextPlayer()
{
    if (current == NULL)
    {
        cout << "No players in the game.\n";
        return;
    }

    current = current->next;

    cout << "Turn moved to next player.\n";
}


// Display current turn
void displayCurrentTurn()
{
    if (current == NULL)
    {
        cout << "No players in the game.\n";
    }
    else
    {
        cout << "Current Turn: " << current->name << endl;
    }
}


// Display all players
void displayPlayers()
{
    if (current == NULL)
    {
        cout << "No players in the game.\n";
        return;
    }

    Node* temp = current;

    cout << "\nPlayers in the game:\n";

    do
    {
        cout << temp->name << " -> ";
        temp = temp->next;

    } while (temp != current);

    cout << "(back to " << current->name << ")\n";
}


// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n========== GAME TURN MANAGEMENT ==========\n";
        cout << "1. Add Player\n";
        cout << "2. Remove Player\n";
        cout << "3. Move to Next Player\n";
        cout << "4. Display Current Turn\n";
        cout << "5. Display All Players\n";
        cout << "6. Exit\n";
        cout << "==========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addPlayer();
                break;

            case 2:
                removePlayer();
                break;

            case 3:
                nextPlayer();
                break;

            case 4:
                displayCurrentTurn();
                break;

            case 5:
                displayPlayers();
                break;

            case 6:
                cout << "Game terminated.\n";
                break;

            default:
                cout << "Invalid choice!\n";
        }

    } while (choice != 6);

    return 0;
}