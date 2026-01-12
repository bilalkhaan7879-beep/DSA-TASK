#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class TicketQueue {
private:
    string queueArr[MAX];
    int front, rear;
public:
    TicketQueue() {
        front = -1;
        rear = -1;
    }

    bool isEmpty() {
        return (front == -1 || front > rear);
    }

    bool isFull() {
        return (rear == MAX - 1);
    }

    void enqueue(string ticket) {
        if (isFull()) {
            cout << "Queue is full! Cannot add more tickets."<<endl;
        } else {
            if (front == -1)  
                front = 0;
            queueArr[++rear] = ticket;
            cout << "Ticket '" << ticket << "' added."<<endl;
        }
    }

    void dequeue() {
        if (isEmpty()) {
            cout << "Queue is empty! No ticket to process."<<endl;
        } else {
            cout << "Processing ticket: '" << queueArr[front] <<endl;
            front++;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "No pending tickets."<<endl;
        } else {
            cout << "\nPending Tickets (Front ? Rear):\n";
            for (int i = front; i <= rear; i++) {
                cout << " - " << queueArr[i] <<endl;
            }
        }
    }

    void cancelTicket(string ticket) {
        if (isEmpty()) {
            cout << "Queue is empty! Nothing to cancel."<<endl;
            return;
        }

        bool found = false;
        int n = rear - front + 1;
        string temp[MAX];
        int idx = 0;

        for (int i = front; i <= rear; i++) {
            if (queueArr[i] == ticket && !found) {
                found = true;  
                continue;
            }
            temp[idx++] = queueArr[i];
        }

        if (!found) {
            cout << "Ticket '" << ticket << "' not found."<<endl;
            return;
        }

        
        rear = -1;
        front = -1;
        for (int i = 0; i < idx; i++)
            enqueue(temp[i]);

        cout << "Ticket '" << ticket << "' canceled."<<endl;
    }
};

int main() {
    TicketQueue tq;
    int choice;
    string ticket;

    do {
        cout << "         Customer Ticketing System "<<endl;
        cout << "1. Add Ticket (Enqueue)"<<endl;
        cout << "2. Process Ticket (Dequeue)"<<endl;
        cout << "3. Display Tickets"<<endl;
        cout << "4. Check if Empty"<<endl;
        cout << "5. Check if Full"<<endl;
        cout << "6. Cancel Ticket"<<endl;
        cout << "7. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();

        switch(choice) {
            case 1:
                cout << "Enter ticket name: ";
                getline(cin, ticket);
                tq.enqueue(ticket);
                break;
            case 2:
                tq.dequeue();
                break;
            case 3:
                tq.display();
                break;
            case 4:
                cout << (tq.isEmpty() ? "Queue is empty.\n" : "Queue is not empty.\n");
                break;
            case 5:
                cout << (tq.isFull() ? "Queue is full.\n" : "Queue is not full.\n");
                break;
            case 6:
                cout << "Enter ticket to cancel: ";
                getline(cin, ticket);
                tq.cancelTicket(ticket);
                break;
            case 7:
                cout << "Exiting..."<<endl;
                break;
            default:
                cout << "Invalid choice! Try again."<<endl;
        }
    } while (choice != 7);

    return 0;
}
