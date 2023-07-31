/* Assignment C++: 3
Author: Tal Levy, ID: 314966359
Author2: Guy Zalsman, ID:312488794
*/
#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#include "Secretary.h"

Secretary::Secretary() {}

Secretary::~Secretary() {}

float Secretary::Salary() {
    return (float)basis + (float)NumOfKids*200;
}

bool Secretary::outstanding() {
    bool exel = false;
    if(stoi(AdministrationPersonal::seniority[1]) > 10){      // check Executive Seniority | info from class AdministrationPersonal
        exel = true;
    }
    return exel;
}

void Secretary::set_secretary() {
    cout << "For adding a new secretary, Please enter the next details:" << endl;
    AdministrationPersonal::set_AdministrationPersonal();       // set secretary's Administration details | func in class AdministrationPersonal

    cout << "How many kids does " << First_name << " have?" << endl;
    cin.clear();
    cin >> NumOfKids;       // set secretary's number of kids
}

void Secretary::Sec_details() {
    cout << "The details of the secretary:" << endl;
    AdministrationPersonal::Admin_details();       // get secretary's Administration details | func in class AdministrationPersonal
    float salary = Salary();                      // get secretary's Salary
    cout << "Salary: " << salary << endl;
    cout << "Kids: " << NumOfKids << endl;
    bool is_outstanding = outstanding();          // check if secretary is outstanding as a secretary
    if(is_outstanding){
        cout << "Outstanding: Yes" << endl;
    }
    if(!is_outstanding){
        cout << "Outstanding: NO " << endl;
    }
}








