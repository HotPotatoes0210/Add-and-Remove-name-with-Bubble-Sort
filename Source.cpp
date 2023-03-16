#include <iostream>
#include <string>

using namespace std;

void printList(string employees[], int count) {
    cout << "List of current employees:" << endl;
    for (int i = 0; i < count; i++) {
        cout << i + 1 << ". " << employees[i] << endl;
    }
}

void insertEmployee(string employees[], int& count, string name) {
    employees[count] = name;
    count++;

    for (int i = 0; i < count - 1; i++) {
        for (int j = 0; j < count - i - 1; j++) {
            if (employees[j] > employees[j + 1]) {
                string temp = employees[j];
                employees[j] = employees[j + 1];
                employees[j + 1] = temp;
            }
        }
    }
}

void removeEmployee(string employees[], int& count, string name) {
    int index = -1;
    for (int i = 0; i < count; i++) {
        if (employees[i] == name) {
            index = i;
            break;
        }
    }

    if (index != -1) {
        for (int i = index; i < count - 1; i++) {
            employees[i] = employees[i + 1];
        }
        count--;
    }
}

int main() {
    string name;
    int numEmployees;
    cout << "How many employees do you expect to have?" << endl;
    cin >> numEmployees;

    string* employees = new string[numEmployees];
    int count = 0;

    int choice;
    do {
        cout << "Menu:" << endl;
        cout << "1. Print full list of employees" << endl;
        cout << "2. Insert new employee" << endl;
        cout << "3. Remove employee from list" << endl;
        cout << "0. Exit" << endl;

        cin >> choice;

        switch (choice) {
        case 1:
            printList(employees, count);
            break;
        case 2:
            cout << "Input name of new employee: ";
            cin >> name;
            insertEmployee(employees, count, name);
            break;
        case 3:
            cout << "Enter name of employee to remove: ";
            cin >> name;
            removeEmployee(employees, count, name);
            break;
        case 0:
            break;
        default:
            cout << "Invalid choice. Please try again." << endl;
        }
    } while (choice != 0);

    delete[] employees;

    return 0;
}
