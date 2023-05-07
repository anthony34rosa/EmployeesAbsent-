/*
 Pseudocode or Algorithm for the program:
  1. Start
  2. Define functions in the program
  3. Define constants and output stream object for the program
  4. declare function int main()
  5. Define the variables in the program
  6. Have the program open file.
  7. Obtain the number of employees from function in the program NumOfEmployees()
  8. Obtain total absences from the function TotDaysAbsent()
  9. Obtain average absences from the function in the program called AverageAbsent()
  10. Have program output total absences to file
  11. Have program Output average absences to file
  12. Have program Output programmer name to file
  13. Have program Close file
  14. Have program Display outro statements
  15. End
  (For specifics, see flowchart)
*/
#include<iostream>
#include<fstream>
#include <iomanip>
#include<string>
using namespace std;
ofstream reportFile;
// Here I am defineing function prototypes
int NumOfEmployees();
int TotalDaysAbsent(int);
double AverageAbsent(int, int);
// Here I am defineing global output stream object and constants that ill be using
// these are the outro stamentsts being defined
const string name = "Anthony Rosario", projectNum = "4";
// Main function.
int main()
{
    // Here I am defining variables
    int employees, total;
 
    double average;
    reportFile.open("employeeAbsences.txt"); // Here I Open file with output comand
    // Here i am Obtain variables from functions
   employees = NumOfEmployees();
 
    total = TotalDaysAbsent(employees);
 
 
    average = AverageAbsent(employees, total);
    // Output obtained variables neatly into file:
    reportFile << "\nTotal number of employee absent days: " << total << std::endl;
 
    reportFile << "\nAverage number of employee absent days: " << fixed <<
 
        setprecision(1) << average << std::endl;
 
    reportFile << "\nProgrammer: " << name << std::endl;
 
    reportFile.close();
 
    // Close file
 
 
    // outro statements
    cout << "Thank you for testing my program.\n\nProgrammer Name: " << name << endl;
    cout << "CMSC 140 Common Project " << projectNum << endl;
    cout << "Due Date: " << due << endl << endl;
    return 0; // Return 0
}
int NumOfEmployees() // Function to obtain number of employees and check if input is correct
{
    int employees;
 
    cout << "Calculate the average number of days a compony's employees are absent.\n\n";
    do // this Loop is to check if the input is correct.
    {
        cout << "please enter the number of employees in the company: ";
 
 
        cin >> employees;
 
        if (employees < 1)
            cout << "The number entered can not be 0 or negtive. please try agian.\n";
        
    } while (employees < 1);
    return employees; // Return employees
}
int TotalDaysAbsent(int employees)
{
    int employeeId, abscences, total = 0;
;
 
    reportFile << "Employee Id | Days Absent\t"  << endl;
 
 
    for (int a = 1; a <= employees; a++)
    {
        cout << "Enter an employee ID: ";
 
        cin >> employeeId;
 
        reportFile << left << setw(14) << employeeId;
        do
        {
            cout << "Enter the number of abscences for that employee during the last year: ";
            cin >> abscences;
            if (abscences < 0)
                cout << "The number of abscences can not be negative. Please try again.\n";
        } while (abscences < 0);
        reportFile << left << "\t" << abscences << endl;
        total += abscences;
    }
    
    return total;
}
double AverageAbsent(int employees, int total)
{
    double averageAbsent;
    averageAbsent = (double)(total) / employees;
    return(averageAbsent);
}

