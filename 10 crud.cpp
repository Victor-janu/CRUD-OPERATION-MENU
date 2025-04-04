#include <iostream>
#include <vector>
#include <string>
using namespace std;

// Structure to store a person's data
struct Person {
    int id;
    string name;
    int age;
};

// Global vector to store data
vector<Person> people;
int nextId = 1;

// Function declarations
void createPerson();
void readPeople();
void updatePerson();
void deletePerson();

int main() {
    int choice;
    while (true) {
        cout << "\n--- CRUD MENU ---\n";
        cout << "1. Create\n2. Read\n3. Update\n4. Delete\n5. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: createPerson(); break;
            case 2: readPeople(); break;
            case 3: updatePerson(); break;
            case 4: deletePerson(); break;
            case 5: cout << "Exiting...\n"; return 0;
            default: cout << "Invalid choice. Try again.\n";
        }
    }
    return 0;
}

// CREATE
void createPerson() {
    Person p;
    p.id = nextId++;
    cout << "Enter name: ";
    cin.ignore();
    getline(cin, p.name);
    cout << "Enter age: ";
    cin >> p.age;
    people.push_back(p);
    cout << "Person added successfully.\n";
}

// READ
void readPeople() {
    if (people.empty()) {
        cout << "No records found.\n";
        return;
    }

    cout << "\n--- List of People ---\n";
    for (const auto& p : people) {
        cout << "ID: " << p.id << ", Name: " << p.name << ", Age: " << p.age << endl;
    }
}

// UPDATE
void updatePerson() {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;

    for (auto& p : people) {
        if (p.id == id) {
            cout << "Enter new name: ";
            cin.ignore();
            getline(cin, p.name);
            cout << "Enter new age: ";
            cin >> p.age;
            cout << "Record updated.\n";
            return;
        }
    }
    cout << "Person with ID " << id << " not found.\n";
}

// DELETE
void deletePerson() {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;

    for (auto it = people.begin(); it != people.end(); ++it) {
        if (it->id == id) {
            people.erase(it);
            cout << "Record deleted.\n";
            return;
        }
    }
    cout << "Person with ID " << id << " not found.\n";
}