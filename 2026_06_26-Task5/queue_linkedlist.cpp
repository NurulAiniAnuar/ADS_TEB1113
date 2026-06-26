#include <iostream>
#include <string>

using namespace std;

class Node {
public:
    string name;
    Node* next;

    Node(string n) {
        name = n;
        next = nullptr;
    }
};

class Queue {
public:
    Node* front;
    Node* rear;

    Queue() {
        front = nullptr;
        rear = nullptr;
    }

    // Insert (enqueue)
    void enqueue(string name) {
        Node* newNode = new Node(name);

        if (rear == nullptr) {
            front = rear = newNode;
            return;
        }

        rear->next = newNode;
        rear = newNode;
    }

    // Delete (dequeue)
    void dequeue() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* temp = front;
        cout << "Removed: " << temp->name << endl;

        front = front->next;

        if (front == nullptr) {
            rear = nullptr;
        }

        delete temp;
    }

    // Display queue
    void display() {
        if (front == nullptr) {
            cout << "Queue is empty." << endl;
            return;
        }

        Node* current = front;
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    Queue q;

    q.enqueue("Aimar");
    q.enqueue("Anjana");
    q.enqueue("Jessy");

    cout << "Initial Queue:" << endl;
    q.display();

    q.enqueue("Ali");
    q.enqueue("Jane");

    q.dequeue();

    cout << "\nFinal Queue:" << endl;
    q.display();

    return 0;
}
