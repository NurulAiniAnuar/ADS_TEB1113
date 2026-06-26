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

class LinkedList {
public:
    Node* head; 
    LinkedList() {
        head = nullptr; 
    }

    void insertEnd(string name) { 
        Node* newNode = new Node(name);

        if (head == nullptr) {
            head = newNode;
            return;
        }

        Node* current = head;
        while (current->next != nullptr) {
            current = current->next;
        }
        current->next = newNode;
    }

    void insertAfter(string afterName, string newName) {
        Node* current = head;
        
        while (current != nullptr && current->name != afterName) {
            current = current->next;
        }

        if (current == nullptr) {
            cout << afterName << "not found." << endl;
            return;
        }

        Node* newNode = new Node(newName);
        newNode->next = current->next;
        current->next = newNode; 
    }

    void deleteByName (string name) {
        if (head == nullptr) {
            return;
        }
        if (head->name == name) {
            Node* temp = head;
            head = head->next;
            delete temp; 
            return;
        }
        Node* current = head;
        while (current->next != nullptr) {
            if (current->next->name == name) {
                Node* temp = current->next; 
                current->next = temp->next; 
                delete temp; 
                return;
            }
            current = current->next; 
        }
    }
    
    void display() {
        Node* current = head;
        if (current == nullptr) {
            cout << "The list is empty." << endl;
            return;
        }
        while (current != nullptr) {
            cout << current->name << endl;
            current = current->next;
        }
    }
};

int main() {
    LinkedList list;

    list.insertEnd("Aimar");
    list.insertEnd("Anjana");
    list.insertEnd("Jessy");

     cout << "Initial list:" << endl;
    list.display();

    list.insertAfter("Anjana","Ali");

    list.insertEnd("Jane");

    list.deleteByName("Jessy");

    cout << "\nFinal list:" << endl;
    list.display();
    // Node node1, node2, node3; //cannot use this because this is sharing the same address
    // Node* node1 = new Node(); //Node() is new node address, not the node itself
    // Node* node2 = new Node();
    // Node* node3 = new Node();

    // node1->name = "Ali";
    // node1->next = node2; //memory address of node2
    // node2->name = "Ahmet";
    // node2->next = node3; //memory address of node3
    // node3->name = "Ayse";
    // node3->next = nullptr; //end of the list

    // //traverse 
    // Node* current = node1;
    // while (current != nullptr) {
    //     cout << current->name << endl;
    //     current = current->next;
    // }

    // //pick by number 
    // Node* arr[] = {node1, node2, node3};
    // int choice;
    // cout << "Enter 1-3 to print the name:" << endl;
    // cin >> choice;
    // cout << arr[choice - 1]->name << endl; 
    // because arr[3-1] = arr[2] = &node3.

    // Node nodes[] = {node1, node2, node3};

    // int current = 0;
    // while (current != -1) {
    //     cout << current->name << endl;
    //     current = current->next;
    // }
    //insert 

    //delete 

    //display linkedlist

    
}

