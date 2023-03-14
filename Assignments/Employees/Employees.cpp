#include <iostream>
#include <cstdio>

using namespace std;

struct Employee {
    char name[100]{};
    int salary{};
};

void PrintEmployeeNames(Employee*, int);
void PrintAverageSalary(Employee*, int);

int main()
{
    int amountOfEmployees{ 5 };
    Employee employees[5]{};
    for (int i = 0; i < amountOfEmployees; ++i) {
        Employee employee{};
        cout << "Give me the name of one of the employees: ";
        scanf_s("%99[^\n]%*c", employee.name, 100);
        cout << "Now give me their salary: ";
        cin >> employee.salary;
        int removeNewLine = getchar();
        employees[i] = employee;
    }
    PrintEmployeeNames(employees, amountOfEmployees);
    PrintAverageSalary(employees, amountOfEmployees);
}

void PrintEmployeeNames(Employee* array, int size) {
    cout << "The names of the employees are ";
    for (int i = 0; i < size - 1; ++i) {
        Employee employee = array[i];
        cout << employee.name << ", ";
    }
    Employee employee = array[size - 1];
    cout << employee.name << "." << endl;
}

void PrintAverageSalary(Employee* array, int size) {
    float sum{};
    for (int i = 0; i < size; ++i) {
        Employee employee = array[i];
        sum += (float)employee.salary / size;
    }
    cout << "The average salaries of your employees is: " << sum << endl;
}
