#include <iostream>
#include <string>
using namespace std;

class Employee {
protected:
    string name;
    int id;
    int salary;

public:
    void setDetails(const string& n, int i, int s) {
        name = n;
        id = i;
        salary = s;
    }

    virtual void calculateEarnings() = 0;
    virtual ~Employee() {}
};

class Manager : public Employee {
private:
    int rating;

public:
    void setRating(int r) {
        rating = r;
    }

    void calculateEarnings() override {
        int bonus = salary * (rating * 0.1);
        cout << "Employee: " << name << " (ID: " << id << ")\n";
        cout << "Role: Manager\n";
        cout << "Base Salary: " << salary << "\n";
        cout << "Bonus: " << bonus << "\n";
        cout << "Total Earnings: " << (salary + bonus) << endl;
    }
};

class Developer : public Employee {
private:
    int extraHours;

public:
    void setExtraHours(int hours) {
        extraHours = hours;
    }

    void calculateEarnings() override {
        int overtime = extraHours * 500;
        cout << "Employee: " << name << " (ID: " << id << ")\n";
        cout << "Role: Developer\n";
        cout << "Base Salary: " << salary << "\n";
        cout << "Overtime Compensation: " << overtime << "\n";
        cout << "Total Earnings: " << (salary + overtime) << endl;
    }
};

int main() {
    int employeeType;
    cout << "Enter employee type (1 for Manager, 2 for Developer): ";
    cin >> employeeType;

    if (employeeType == 1) {
        string name;
        int id, salary, rating;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter salary: ";
        cin >> salary;
        cout << "Enter performance rating (1-5): ";
        cin >> rating;

        if (salary < 10000 || salary > 1000000 || rating < 1 || rating > 5) {
            cout << "Invalid input values." << endl;
            return 1;
        }

        Manager manager;
        manager.setDetails(name, id, salary);
        manager.setRating(rating);
        manager.calculateEarnings();
    } else if (employeeType == 2) {
        string name;
        int id, salary, extraHours;
        cout << "Enter name: ";
        cin.ignore();
        getline(cin, name);
        cout << "Enter ID: ";
        cin >> id;
        cout << "Enter salary: ";
        cin >> salary;
        cout << "Enter extra hours worked: ";
        cin >> extraHours;

        if (salary < 10000 || salary > 1000000 || extraHours < 0 || extraHours > 100) {
            cout << "Invalid input values." << endl;
            return 1;
        }

        Developer developer;
        developer.setDetails(name, id, salary);
        developer.setExtraHours(extraHours);
        developer.calculateEarnings();
    } else {
        cout << "Invalid employee type." << endl;
    }

    return 0;
}