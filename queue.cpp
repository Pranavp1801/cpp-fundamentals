#include <iostream>
using namespace std;

class queue {
public:
    int size, front, rear;
    int *q;

    queue(int n) {
        size = n;
        front = 0;
        rear = 0;
        q = new int[size];
    }

    ~queue() {
        delete[] q;
    }

    int isfull() {
        return rear == size;
    }

    int isempty() {
        return front == rear;
    }

    void enqueue(int value) {
        if (isfull()) {
            cout << "Queue is full" << endl;
            return;
        }
        q[rear] = value;
        rear++;
        cout << "Inserted successfully" << endl;
    }

    void dequeue() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << q[front] << " removed" << endl;
        front++;
    }

    void display() {
        if (isempty()) {
            cout << "Queue is empty" << endl;
            return;
        }
        cout << "Queue elements: ";
        for (int i = front; i < rear; i++) {
            cout << q[i] << " ";
        }
        cout << endl;
    }
};

int main() {
    int size, choice;
    cout << "Enter size of queue: ";
    cin >> size;

    queue obj(size);

    while (true) {
        cout << "\n1. Enqueue\n2. Dequeue\n3. Display\n4. Exit\n";
        cin >> choice;

        switch (choice) {
        case 1: {
            int value;
            cout << "Enter value: ";
            cin >> value;
            obj.enqueue(value);
            break;
        }
        case 2:
            obj.dequeue();
            break;
        case 3:
            obj.display();
            break;
        case 4:
            return 0;
        default:
            cout << "Invalid choice" << endl;
        }
    }
}
