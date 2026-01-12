#include <iostream>
using namespace std;

struct Node {
    int id;
    Node* next;
};

Node* head = NULL;


void insert(int id) {
    Node* n = new Node();
    n->id = id;

    if (head == NULL) {
        head = n;
        n->next = head;
    } else {
        Node* temp = head;
        while (temp->next != head)
            temp = temp->next;

        temp->next = n;
        n->next = head;
    }
    cout << "Inserted: " << id << endl;
}

void del(int id) {
    if (head == NULL) {
        cout << "List empty"<<endl;
        return;
    }

    Node *cur = head, *prev = NULL;

    do {
        if (cur->id == id) {

            
            if (cur->next == head && cur == head) {
                head = NULL;
            }
            
            else if (cur == head) {
                Node* temp = head;
                while (temp->next != head)
                    temp = temp->next;

                head = head->next;
                temp->next = head;
            }
           
            else {
                prev->next = cur->next;
            }

            delete cur;
            cout << "Deleted: " << id << endl;
            return;
        }

        prev = cur;
        cur = cur->next;

    } while (cur != head);

    cout << "ID not found"<<endl;
}


void display() {
    if (head == NULL) {
        cout << "List empty"<<endl;
        return;
    }

    Node* temp = head;
    cout << "Playlist: ";
    do {
        cout << temp->id << " ";
        temp = temp->next;
    } while (temp != head);

    cout << endl;
}

int main() {
    int ch, id;

    do {
        cout << "\n1.Insert  2.Delete  3.Display  4.Exit"<<endl;
        cout << "Choice: ";
        cin >> ch;

        switch (ch) {
        case 1:
            cout << "Enter ID: ";
            cin >> id;
            insert(id);
            break;

        case 2:
            cout << "Enter ID: ";
            cin >> id;
            del(id);
            break;

        case 3:
            display();
            break;

        case 4:
            cout << "Exit"<<endl;
            break;

        default:
            cout << "Invalid choice"<<endl;
        }
    } while (ch != 4);

    return 0;
}

