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

#include "AdministrationPersonal.h"

#ifndef PERSON_CPP_SECRETARY_H
#define PERSON_CPP_SECRETARY_H


class Secretary: public AdministrationPersonal {
private:
    int NumOfKids;

public:
    Secretary();
    ~Secretary();

    float Salary();
    bool outstanding();

    void set_secretary();

    void Sec_details();

};


#endif //PERSON_CPP_SECRETARY_H
