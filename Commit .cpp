#include <iostream>
#include <vector>
using namespace std;

struct Record {
    int id;
    string name;
};

void createRecord(vector<Record> &records) {
    Record newRecord;
    cout << "Enter ID: ";
    cin >> newRecord.id;
    cout << "Enter Name: ";
    cin >> newRecord.name;
    records.push_back(newRecord);
    cout << "Record added successfully!\n";
}

void readRecords(const vector<Record> &records) {
    for (const auto &rec : records) {
        cout << "ID: " << rec.id << ", Name: " << rec.name << endl;
    }
}

void updateRecord(vector<Record> &records) {
    int id;
    cout << "Enter ID to update: ";
    cin >> id;
    for (auto &rec : records) {
        if (rec.id == id) {
            cout << "Enter new name: ";
            cin >> rec.name;
            cout << "Record updated!\n";
            return;
        }
    }
    cout << "Record not found.\n";
}

void deleteRecord(vector<Record> &records) {
    int id;
    cout << "Enter ID to delete: ";
    cin >> id;
    for (auto it = records.begin(); it != records.end(); ++it) {
        if (it->id == id) {
            records.erase(it);
            cout << "Record deleted!\n";
            return;
        }
    }
    cout << "Record not found.\n";
}

int main() {
    vector<Record> records;
    createRecord(records);
    readRecords(records);
    updateRecord(records);
    readRecords(records);
    deleteRecord(records);
    readRecords(records);
    return 0;
}