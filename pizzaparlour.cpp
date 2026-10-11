# pizza parlour
#include <iostream>
using namespace std;

#define MAX 5

class PizzaQueue
{
    int queue[MAX];
    int front, rear;

public:
    // Constructor
    PizzaQueue()
    {
        front = -1;
        rear = -1;
    }

    // Add order
    void addOrder()
    {
        int order;

        // Check if queue is full
        if ((rear + 1) % MAX == front)
        {
            cout << "Pizza Parlor is FULL. Cannot accept more orders.\n";
            return;
        }

        cout << "Enter Order Number: ";
        cin >> order;

        // First order
        if (front == -1)
        {
            front = 0;
        }

        rear = (rear + 1) % MAX;
        queue[rear] = order;

        cout << "Order " << order << " accepted.\n";
    }

    // Serve order
    void serveOrder()
    {
        if (front == -1)
        {
            cout << "No orders to serve.\n";
            return;
        }

        cout << "Order " << queue[front] << " served.\n";

        // Only one order
        if (front == rear)
        {
            front = -1;
            rear = -1;
        }
        else
        {
            front = (front + 1) % MAX;
        }
    }

    // Display orders
    void displayOrders()
    {
        if (front == -1)
        {
            cout << "No pending orders.\n";
            return;
        }

        cout << "\nPending Orders:\n";

        int i = front;

        while (true)
        {
            cout << queue[i] << " ";

            if (i == rear)
                break;

            i = (i + 1) % MAX;
        }

        cout << endl;
    }
};

int main()
{
    PizzaQueue pizza;
    int choice;

    do
    {
        cout << "\n========== PIZZA PARLOR ==========\n";
        cout << "1. Accept Order\n";
        cout << "2. Serve Order\n";
        cout << "3. Display Pending Orders\n";
        cout << "4. Exit\n";
        cout << "==================================\n";

        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice)
        {
        case 1:
            pizza.addOrder();
            break;

        case 2:
            pizza.serveOrder();
            break;

        case 3:
            pizza.displayOrders();
            break;

        case 4:
            cout << "Program terminated.\n";
            break;

        default:
            cout << "Invalid choice!\n";
        }

    } while (choice != 4);

    return 0;
}