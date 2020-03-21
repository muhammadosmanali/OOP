#include <iostream>
#include <iomanip>
using namespace std;
#define ARR 1000
#define NOE 2

struct Employee
{
 int id;
 char name[ARR];
 int salary;
 float height;
 char designation[ARR];
};

void printEmployee(const Employee& c);
Employee readEmployee();
int findEmployee(const Employee emp[],int id,int num);

int main()
{
 Employee E1[NOE];
 int i;
 int id;

 for (i = 0; i < NOE; i++)
  {
   E1[i] = readEmployee();
  }

 cout<<"\n\n------------------------------------------------------------\n";
  cout << "Details of Employees"; 
 cout<<"\n------------------------------------------------------------\n\n";
 
 cout << "ID" << setw(15) << "NAME" << setw(15) << "SALARY" << setw(15) << "DESIGNATION" << setw(15) << "HEIGHT";
 for (i = 0; i < NOE; i++)
  {
   printEmployee(E1[i]);
  }
 cout<<"\n\n------------------------------------------------------------\n";
 cout << "Enter the id to be search: " << endl;
 cin >> id;
 cout << endl;
 cout << "RESULT:";
 cout << endl;
 findEmployee(E1, id, NOE);
}

Employee readEmployee()
{
 Employee tempE1;
 
 cout << "Name of Employee: " << endl;
 cin.getline(tempE1.name, ARR);

 cout << "Enter the id of Employee: " << endl;
 cin >> tempE1.id;

 cout << "Enter the salary of Employee: " << endl;
 cin >> tempE1.salary;
 
 cin.ignore();

 cout << "Enter the designation of Employee: " << endl;
 cin.getline(tempE1.designation, ARR);

 cout << "Enter the height of Employee: " << endl;
 cin >> tempE1.height;

 cin.ignore();
 cout << endl;
  
 return tempE1;
}

void printEmployee(const Employee& c)
{
 cout << endl;
 cout << "\n" << c.id << setw(15) << c.name << setw(15) << c.salary << setw(15) << c.designation << setw(15) << c.height << endl;
 cout << endl;
}

int findEmployee(const Employee emp[],int id,int num)
{
 for(int i = 0; i < num; i++)
  {
   if (emp[i].id == id)
    {
     cout<< "Index # " << i + 1 << ": " << "ID FOUND" << endl;
     printEmployee(emp[i]);
     exit(0);
    }
   else
    {
     cout << "Index # " << i + 1 << ": " << "ID NOT FOUND" << endl;
    }
  }
}
