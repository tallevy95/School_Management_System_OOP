#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#include "AdministrationPersonal.h"
#include "Teacher.h"


#ifndef PERSON_CPP_MANAGER_H
#define PERSON_CPP_MANAGER_H


class Manager: public AdministrationPersonal, public Teacher {
private:
    Manager();
    static Manager* NumOfManager;

public:
    ~Manager();

    float Salary();
    bool outstanding();

    void Manager_details();
    void set_Manager();

    static Manager ret_manager();
    static bool check_manager();

};


#endif //PERSON_CPP_MANAGER_H
