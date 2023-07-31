#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#include "AdministrationPersonal.h"


AdministrationPersonal::AdministrationPersonal() {}

AdministrationPersonal::~AdministrationPersonal() {}

void AdministrationPersonal::Admin_details() {

    Worker::W_details();                  // get Administration Personal's Worker details | func in class Worker
    cout << "Office location: " << office_location << endl;

}

void AdministrationPersonal::set_AdministrationPersonal() {

    Worker::set_worker_name();                  // set Administration Personal's name | func in class Worker
    Worker::set_worker_exec_seniority();       // set Administration Personal's seniority | func in class Worker

    cout << "What is the office location?" << endl;
    cin.clear();
    cin >> office_location;

}

float AdministrationPersonal::Salary() {
    return 0;
}

bool AdministrationPersonal::outstanding() {
    return false;
}


