#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#include "Manager.h"
/*
int main(){
    Manager x = Manager::ret_manager();
    x.set_Manager();
    x.printDetails();
}
*/
Manager* Manager::NumOfManager = NULL;

float Manager::Salary(){
    float x = 0, y = 0;
    if(AdministrationPersonal::seniority[0] != "-"){     // if manager have Teaching Seniority | info from class AdministrationPersonal
        x = Teacher::Salary();                           // get manager's teaching Salary | func in class AdministrationPersonal
    }
    y = (float)basis*2 + (float)stoi(AdministrationPersonal::seniority[1])*500; // Executive Seniority

    return x + y;
}

void Manager::set_Manager() {

    cout << "For adding a new Manager, Please enter the next details:" << endl;
    AdministrationPersonal::set_AdministrationPersonal();       // set manager's Administration details | func in class AdministrationPersonal
    string choice;
    cout << "Does the manager also teach? (Y/N)" << endl;
    cin.clear();
    cin >> choice;
    if(choice == "Y" || choice == "y"){     // if manager also teach
        Teacher::set_teacher_det();       // set manager's classes | func in class Teacher
    }

    NumOfManager = this;        // now the static NumOfManager will not be NULL and no more managers can be added
}

bool Manager::outstanding(){
    bool exel = false;
    if(stoi(AdministrationPersonal::seniority[1]) > 3){      // check Executive Seniority | info from class AdministrationPersonal
        exel = true;
    }
    return exel;
}

void Manager::Manager_details() {

    cout << "The details of the manager:" << endl;
    AdministrationPersonal::Admin_details();       // get manager's Administration details | func in class AdministrationPersonal
    float salary = Salary();                       // get manager's Salary
    cout << "Salary: " << salary << endl;
    bool is_outstanding = outstanding();          // check if manager is outstanding as a manager
    if(is_outstanding){
        cout << "Outstanding: Yes" << endl;
    }
    if(!is_outstanding){
        cout << "Outstanding: NO " << endl;
    }
    if(AdministrationPersonal::seniority[0] != "-"){     // if manager have Teaching Seniority
        cout << "\nTeaching Seniority: " << AdministrationPersonal::seniority[0] << endl;       // print Teaching Seniority

        // here we need to print all the class details (include the pupils names!!)

    }
}

Manager::Manager() {}

Manager::~Manager() {}

bool Manager::check_manager(){
    if(NumOfManager == NULL){
        return true;
    } else{
        cout << "****************************************" << endl;
        cout << "Sorry, but there can be only one manager." << endl;
        cout << "As long as the current manager keeps he's job we can't register a new one." << endl;
        cout << "****************************************" << endl;
        return false;
    }
}

Manager Manager::ret_manager() {

        return Manager();
}




