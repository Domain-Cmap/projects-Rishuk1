#include<bits/stdc++.h>
using namespace std;

void salary(int stipe){
    cout<<"Intern Salary: "<<stipe<<endl;
}

void salary(int ebase , int ebonus){
    cout<<"Employee Salary: "<<ebase+ebonus<<endl;
}

void salary(int mbase ,int mbonus ,int mperf){
    cout<<"Manager Salary: "<<mbase+mbonus+mbonus<<endl;
}

int main()
{
    int stipeEnd, ebaseSalary , ebonus, mbaseSalary , mbonus , mperf;
    cin >> stipeEnd >> ebaseSalary >> ebonus >> mbaseSalary >> mbonus >> mperf;
    salary(stipeEnd);
    salary(ebaseSalary,ebonus);
    salary(mbaseSalary,mbonus,mperf);
    return 0;
}