#include <iostream>
#include <vector>
#include <fstream>
using namespace std;

struct Record {
    int id;
    string name;
};

void saveToFile(const vector<Record> &records) {
    ofstream file("records.txt");
    if (!file) {
        cout << "Error: Unable to open file for writing.\n";
        return;
    }
    for (const auto &rec : records) {
        file << rec.id << " " << rec.name << endl;
    }
    file.close();
}

void loadFromFile(vector<Record> &records) {
    ifstream file("records.txt");
    if (!file) {
        cout << "No previous records found.\n";
        return;
    }
    Record rec;
    while (file >> rec.id) {
        file.ignore(); // Ignore space before name
        getline(file, rec.name);
        records.push_back(rec);
    }
    file.close();
}

void createRecord(vector<Record> &records) {
    Record newRecord;
    cout << "Enter ID: ";
    cin >> newRecord.id;
    cin.ignore(); // Prevents input issues
    cout << "Enter Name: ";
    getline(cin, newRecord.name);
    records.push_back(newRecord);
    cout << "Record added successfully!\n";
}

void readRecords(const vector<Record> &records) {
    if (records.empty()) {
        cout << "No records found.\n";
        return;
    }
    cout << "\n--- Records ---\n";
    for (const auto &rec : records) {
        cout << "ID: " << rec.id << ", Name: " << rec.name << endl;
    }
}

int main() {
    vector<Record> records;
    loadFromFile(records);
    
    createRecord(records);
    readRecords(records);
    
    saveToFile(records);
    return 0;
}