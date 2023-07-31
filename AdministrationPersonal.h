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

#ifndef PERSON_CPP_ADMINISTRATIONPERSONAL_H
#define PERSON_CPP_ADMINISTRATIONPERSONAL_H


#include "Worker.h"

class AdministrationPersonal: public Worker{
protected:
    string office_location;

public:
    AdministrationPersonal();
    ~AdministrationPersonal();

    float Salary();
    bool outstanding();

    void Admin_details();
    void set_AdministrationPersonal();

};


#endif //PERSON_CPP_ADMINISTRATIONPERSONAL_H
