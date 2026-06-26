#include <iostream>
#include <string>
#include <limits>
using namespace std;

struct Student {
    int id;
    string name;
    string course;
    int age;
};

int main() {

    Student students[5];

    cout << "Input\n\n";

    for (int i = 0; i < 5; i++) {

        cout << "Student " << i + 1 << "\n";

        cout << "ID: ";
        while (!(cin >> students[i].id)) {
            cout << "Invalid ID. Enter numbers only: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "Name: ";
        getline(cin, students[i].name);

        cout << "Course: ";
        getline(cin, students[i].course);

        cout << "Age: ";
        while (!(cin >> students[i].age)) {
            cout << "Invalid Age. Enter numbers only: ";
            cin.clear();
            cin.ignore(numeric_limits<streamsize>::max(), '\n');
        }
        cin.ignore(numeric_limits<streamsize>::max(), '\n');

        cout << "\n";
    }

    cout << "All Students\n\n";

    for (int i = 0; i < 5; i++) {
        cout << "ID: " << students[i].id << "\n";
        cout << "Name: " << students[i].name << "\n";
        cout << "Course: " << students[i].course << "\n";
        cout << "Age: " << students[i].age << "\n\n";
    }

    int searchID;

    cout << "Enter ID to search: ";
    while (!(cin >> searchID)) {
        cout << "Invalid ID. Enter numbers only: ";
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
    }

    bool searchFound = false;

    for (int i = 0; i < 5; i++) {
        if (students[i].id == searchID) {
            cout << "Found. Name: " << students[i].name << "\n";
            searchFound = true;
            break;
        }
    }

    if (!searchFound) {
        cout << "Student not found.\n";
    }

    string inputID;

    while (true) {

        cout << "\nEnter ID to update (or Q to quit): ";
        cin >> inputID;

        if (inputID == "Q" || inputID == "q") {
            cout << "Exiting update mode.\n";
            break;
        }

        int updateID;

        try {
            updateID = stoi(inputID);
        }
        catch (...) {
            cout << "Invalid ID.\n";
            continue;
        }

        string change;

        cout << "What do you want to change (id/name/course/age): ";
        cin >> change;

        bool updateFound = false;

        for (int i = 0; i < 5; i++) {

            if (students[i].id == updateID) {

                updateFound = true;

                if (change == "id") {

                    int newID;

                    cout << "Enter new ID: ";
                    while (!(cin >> newID)) {
                        cout << "Invalid ID. Enter numbers only: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    students[i].id = newID;
                    cout << "Updated.\n";
                }

                else if (change == "name") {

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter new name: ";
                    getline(cin, students[i].name);

                    cout << "Updated.\n";
                }

                else if (change == "course") {

                    cin.ignore(numeric_limits<streamsize>::max(), '\n');

                    cout << "Enter new course: ";
                    getline(cin, students[i].course);

                    cout << "Updated.\n";
                }

                else if (change == "age") {

                    int newAge;

                    cout << "Enter new age: ";
                    while (!(cin >> newAge)) {
                        cout << "Invalid Age. Enter numbers only: ";
                        cin.clear();
                        cin.ignore(numeric_limits<streamsize>::max(), '\n');
                    }

                    students[i].age = newAge;
                    cout << "Updated.\n";
                }

                else {
                    cout << "Invalid field. Use: id, name, course, or age.\n";
                }

                cout << "ID: " << students[i].id << "\n";
                cout << "Name: " << students[i].name << "\n";
                cout << "Course: " << students[i].course << "\n";
                cout << "Age: " << students[i].age << "\n";

                break;
            }
        }

        if (!updateFound) {
            cout << "Student not found.\n";
        }
    }

    return 0;
}