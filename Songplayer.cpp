# Song player
#include <iostream>
#include <string>
using namespace std;

// Node structure
struct Node
{
    string song;
    Node* next;
    Node* prev;
};

Node* head = NULL;


// Function to add a new song
void addSong()
{
    string songName;

    cout << "Enter song name: ";
    cin >> songName;

    Node* newNode = new Node;
    newNode->song = songName;

    // If playlist is empty
    if (head == NULL)
    {
        head = newNode;

        newNode->next = head;
        newNode->prev = head;
    }
    else
    {
        // Find last node
        Node* last = head->prev;

        newNode->next = head;
        newNode->prev = last;

        last->next = newNode;
        head->prev = newNode;
    }

    cout << "Song added successfully.\n";
}


// Function to delete a song
void deleteSong()
{
    if (head == NULL)
    {
        cout << "Playlist is empty.\n";
        return;
    }

    string songName;
    cout << "Enter song name to delete: ";
    cin >> songName;

    Node* temp = head;

    // Search for the song
    do
    {
        if (temp->song == songName)
        {
            break;
        }

        temp = temp->next;

    } while (temp != head);


    // Song not found
    if (temp->song != songName)
    {
        cout << "Song not found.\n";
        return;
    }


    // Only one song
    if (temp->next == temp)
    {
        delete temp;
        head = NULL;
    }
    else
    {
        temp->prev->next = temp->next;
        temp->next->prev = temp->prev;

        // If first song is deleted
        if (temp == head)
        {
            head = temp->next;
        }

        delete temp;
    }

    cout << "Song deleted successfully.\n";
}


// Display playlist in forward direction
void displayForward()
{
    if (head == NULL)
    {
        cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = head;

    cout << "\nPlaylist (Forward):\n";

    do
    {
        cout << temp->song << " <-> ";
        temp = temp->next;

    } while (temp != head);

    cout << "(Back to " << head->song << ")\n";
}


// Display playlist in backward direction
void displayBackward()
{
    if (head == NULL)
    {
        cout << "Playlist is empty.\n";
        return;
    }

    Node* temp = head->prev;

    cout << "\nPlaylist (Backward):\n";

    Node* last = temp;

    do
    {
        cout << temp->song << " <-> ";
        temp = temp->prev;

    } while (temp != last);

    cout << "(Back to " << last->song << ")\n";
}


// Main function
int main()
{
    int choice;

    do
    {
        cout << "\n========== SMART MUSIC PLAYER ==========\n";
        cout << "1. Add New Song\n";
        cout << "2. Delete Song\n";
        cout << "3. Display Playlist Forward\n";
        cout << "4. Display Playlist Backward\n";
        cout << "5. Exit\n";
        cout << "========================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
            case 1:
                addSong();
                break;

            case 2:
                deleteSong();
                break;

            case 3:
                displayForward();
                break;

            case 4:
                displayBackward();
                break;

            case 5:
                cout << "Program terminated.\n";
                break;

            default:
                cout << "Invalid choice! Please try again.\n";
        }

    } while (choice != 5);

    return 0;
}