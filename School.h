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
#include "Worker.h"
#include "Pupil.h"

#ifndef PERSON_CPP_SCHOOL_H
#define PERSON_CPP_SCHOOL_H


class School {
private:
    School();
    vector<Worker*> Workers;
    vector<const Pupil*> Pupils;
public:
    void menu();
    static School ret_school();

    //float Salary(){}
    //bool outstanding(){}

    Pupil add_pupil();
    School & operator+=(const Pupil &pupil);
    ~School(){}
};


#endif //PERSON_CPP_SCHOOL_H
