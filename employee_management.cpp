#include <iostream>
#include <vector>
#include <algorithm>
#include <numeric>
#include <iterator>

using namespace std;

struct Employee
{
    int id;
    string name;
    double salary;
};

void displayEmployee(const Employee &emp)
{
    cout << "ID: " << emp.id << "\nName: " << emp.name << "\nSalary: $" << emp.salary << endl;
    cout << endl;
};

int main()
{
    // sample data
    vector<Employee> employees = {
        {10, "Hmm", 1000000},
        {12, "Hmmm", 300000},
        {18, "Hmm", 2000000},
        {18, "Hmm", 800000},
        {02, "Hmm", 990000},
    };

    sort(employees.end(), employees.begin(), [](Employee &e1, Employee &e2)
         { return e1.salary > e2.salary; });

    cout << "Employees sorted by salary highest to lowest" << "\n";
    for_each(employees.begin(), employees.end(), displayEmployee);

    vector<Employee> highEarners;
    copy_if(
        employees.begin(),
        employees.end(),
        back_inserter(highEarners),
        [](const Employee &e)
        { return e.salary > 75000; });

    cout << "Employees who are high earners" << "\n";
    for_each(highEarners.begin(), highEarners.end(), displayEmployee);

    double totalSalary = accumulate(
        employees.begin(),
        employees.end(),
        0.0,
        [](double sum, const Employee &e) {
            return sum + e.salary;
        });

        double averageSalary = totalSalary/employees.size();


    return 0;
}