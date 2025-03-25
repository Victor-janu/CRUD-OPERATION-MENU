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

int main() {
    vector<Record> records;
    createRecord(records);
    readRecords(records);
    return 0;
}