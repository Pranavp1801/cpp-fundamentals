#include <iostream>
using namespace std;

/*
 Stack implementation using array

 Time Complexity:
 Push   -> O(1)
 Pop    -> O(1)
 Peek   -> O(1)
 Display-> O(n)
*/

class Stack {
public:
    int size;
    int top;
    int* stk;

    Stack(int n) {
        size = n;
        top = 0;                  // top points to next free position
        stk = new int[size];
    }

    ~Stack() {
        delete[] stk;
    }

    bool isFull() {
        return top == size;
    }

    bool isEmpty() {
        return top == 0;
    }

    void push(int value) {
        if (isFull()) {
            cout << "Stack is already full" << endl;
            return;
        }
        stk[top] = value;
        top++;
        cout << "Added successfully" << endl;
    }

    void pop() {
        if (isEmpty()) {
            cout << "Stack is empty. Nothing to pop" << endl;
            return;
        }
        top--;
        cout << stk[top] << " popped" << endl;
    }

    void peek() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
        } else {
            cout << "Top element: " << stk[top - 1] << endl;
        }
    }

    void display() {
        if (isEmpty()) {
            cout << "Stack is empty" << endl;
            return;
        }
        cout << "Stack elements: ";
        for (int i = 0; i < top; i++) {
            cout << stk[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice;
    cout << "Enter size of stack: ";
    cin >> size;

    Stack obj(size);

    while (true) {
        cout << "\nChoose operation:\n";
        cout << "1. Push\n2. Pop\n3. Peek\n4. Display\n5. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter value: ";
            cin >> value;
            obj.push(value);
            break;
        }
        case 2:
            obj.pop();
            break;
        case 3:
            obj.peek();
            break;
        case 4:
            obj.display();
            break;
        case 5:
            cout << "Thank You!" << endl;
            return 0;
        default:
            cout << "Enter valid choice" << endl;
        }
    }
}
