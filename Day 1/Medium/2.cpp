#include <bits/stdc++.h>
using namespace std;

class employee
{
    int eid;
    string name;
    int salary;

public:
    employee(int id, string n, int sal)
    {
        eid = id;
        name = n;
        salary = sal;
    }
    void display()
    {
        cout << "Employee ID: " << eid << endl;
        cout << "Employee Name: " << name << endl;
        cout << "Employee Salary: " << salary << endl;
    }
};

int main()
{
    int id, salary;
    string name;
    cin >> id >> name >> salary;
    employee e(id, name, salary);
    e.display();
    return 0;
}