#include <iostream>
#include <string>
using namespace std;

#define MAX 100

class BookStack {
private:
    string stackArr[MAX];
    int top;
public:
    BookStack() { top = -1; }

    bool isEmpty() {
        return (top == -1);
    }

    bool isFull() {
        return (top == MAX - 1);
    }

    void pushBook(string book) {
        if(isFull()) {
            cout << "Stack is full! Cannot add more books.\n";
        } else {
            stackArr[++top] = book;
            cout << "'" << book << "' added to stack.\n";
        }
    }

    void popBook() {
        if(isEmpty()) {
            cout << "Stack is empty! Nothing to remove.\n";
        } else {
            cout << "'" << stackArr[top] << "' removed from stack.\n";
            top--;
        }
    }

    void peekBook() {
        if(isEmpty()) {
            cout << "Stack is empty!\n";
        } else {
            cout << "Top book: '" << stackArr[top] << "'\n";
        }
    }

    void displayStack() {
        if(isEmpty()) {
            cout << "No books in stack.\n";
        } else {
            cout << "\nBooks in Stack (Top ? Bottom):\n";
            for(int i = top; i >= 0; i--) {
                cout << " - " << stackArr[i] << "\n";
            }
        }
    }
};

int main() {
    BookStack bs;
    int choice;
    string bookName;

    do {
        cout << "       Book Management System "<<endl;
        cout << "1. Add Book (Push)"<<endl;
        cout << "2. Remove Book (Pop)"<<endl;
        cout << "3. View Top Book (Peek)"<<endl;
        cout << "4. Display All Books"<<endl;
        cout << "5. Check if Stack is Empty"<<endl;
        cout << "6. Exit"<<endl;
        cout << "Enter your choice: ";
        cin >> choice;
        cin.ignore();  

        switch(choice) {
            case 1:
                cout << "Enter book name: ";
                getline(cin, bookName);
                bs.pushBook(bookName);
                break;

            case 2:
                bs.popBook();
                break;

            case 3:
                bs.peekBook();
                break;

            case 4:
                bs.displayStack();
                break;

            case 5:
                if(bs.isEmpty())
                    cout << "Stack is empty!\n";
                else
                    cout << "Stack is NOT empty.\n";
                break;

            case 6:
                cout << "Exiting...\n";
                break;

            default:
                cout << "Invalid choice! Try again.\n";
        }

    } while(choice != 6);

    return 0;
}
