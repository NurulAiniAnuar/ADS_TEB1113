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

class CircularLinkedList {
public:
    Node* head;

    CircularLinkedList() {
        head = nullptr;
    }

    // ✅ Insert at end
    void insertEnd(string name) {
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            newNode->next = head; // circle
            return;
        }

        Node* current = head;
        while (current->next != head) {
            current = current->next;
        }

        current->next = newNode;
        newNode->next = head;
    }

    // ✅ Insert after a node
    void insertAfter(string afterName, string newName) {
        if (head == nullptr) return;

        Node* current = head;

        do {
            if (current->name == afterName) {
                Node* newNode = new Node(newName);
                newNode->next = current->next;
                current->next = newNode;
                return;
            }
            current = current->next;
        } while (current != head);

        cout << afterName << " not found." << endl;
    }

    // ✅ Delete by name
    void deleteByName(string name) {
        if (head == nullptr) return;

        Node* current = head;
        Node* prev = nullptr;

        // Case: delete head
        if (head->name == name) {
            // Only one node
            if (head->next == head) {
                delete head;
                head = nullptr;
                return;
            }

            // Find last node
            Node* last = head;
            while (last->next != head) {
                last = last->next;
            }

            Node* temp = head;
            head = head->next;
            last->next = head;
            delete temp;
            return;
        }

        do {
            prev = current;
            current = current->next;

            if (current->name == name) {
                prev->next = current->next;
                delete current;
                return;
            }

        } while (current != head);
    }

    // ✅ Display list
    void display() {
        if (head == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }

        Node* current = head;

        do {
            cout << current->name << endl;
            current = current->next;
        } while (current != head);
    }
};

int main() {
    CircularLinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

    cout << "Initial list:" << endl;
    list.display();

    list.insertAfter("Anjana", "Ali");
    list.insertEnd("Jane");
    list.deleteByName("Jessy");

    cout << "\nFinal list:" << endl;
    list.display();

    return 0;
}