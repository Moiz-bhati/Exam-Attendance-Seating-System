#include <iostream>
#include <string>
using namespace std;
struct Student {
    int rollNo;
    string name;
    bool present;
    Student* next;
};
Student* top = nullptr;
// Function to add a student
void addStudent() {
    Student* newNode = new Student();
    cout << "Enter roll number: ";
    cin >> newNode->rollNo;
    cin.ignore(); 
    cout << "Enter student name: ";
    getline(cin, newNode->name); 
    newNode->present = false;
    newNode->next = top;
    top = newNode;

    cout << "Student added successfully.\n";
}

// Function to mark attendance
void markAttendance() {
    if (top == nullptr) {
        cout << "No students available.\n";
        return;
    }

    int roll;
    cout << "Enter roll number to mark present: ";
    cin >> roll;

    Student* temp = top;
    while (temp != nullptr) {
        if (temp->rollNo == roll) {
            temp->present = true;
            cout << "Attendance marked PRESENT.\n";
            return;
        }
        temp = temp->next;
    }
    cout << "Student not found.\n";
}

// Function to remove last added student
void removeStudent() {
    if (top == nullptr) {
        cout << "No students to remove.\n";
        return;
    }
    Student* temp = top;
    top = top->next;
    delete temp;
    cout << "Last added student removed.\n";
}

// Function to show attendance
void showAttendance() {
    if (top == nullptr) {
        cout << "No students available.\n";
        return;
    }

    cout << "\nAttendance List:\n";
    Student* temp = top;
    while (temp != nullptr) {
        cout << "Roll No: " << temp->rollNo
             << ", Name: " << temp->name
             << ", Status: " << (temp->present ? "Present" : "Absent") << endl;
        temp = temp->next;
    }
}

// Function to arrange seats
void arrangeSeats() {
    if (top == nullptr) {
        cout << "No students available.\n";
        return;
    }

    int rows, cols;
    cout << "Enter number of rows: ";
    cin >> rows;
    cout << "Enter number of columns: ";
    cin >> cols;

    Student* temp = top;
    cout << "\nExam Seating Arrangement:\n\n";

    for (int i = 1; i <= rows; i++) {
        for (int j = 1; j <= cols; j++) {
            if (temp != nullptr) {
                cout << temp->name << "(" << temp->rollNo << ")";
                cout << (temp->present ? "[P]" : "[A]");
                temp = temp->next;
            } else {
                cout << "Empty Seat";
            }
            cout << "\t";
        }
        cout << endl;
    }
}

int main() {
    int choice;
    do {
        cout << "\n===== Exam Attendance & Seating System =====\n";
        cout << "1. Add a student\n";
        cout << "2. Mark attendance\n";
        cout << "3. Remove last added student\n";
        cout << "4. Show attendance list\n";
        cout << "5. Arrange exam seats\n";
        cout << "6. Exit\n";
        cout << "Enter your choice: ";
        cin >> choice;

        switch (choice) {
            case 1: addStudent(); break;
            case 2: markAttendance(); break;
            case 3: removeStudent(); break;
            case 4: showAttendance(); break;
            case 5: arrangeSeats(); break;
            case 6: cout << "Program closed.\n"; break;
            default: cout << "Invalid choice, try again.\n";
        }
    } while (choice != 6);

    return 0;
}
