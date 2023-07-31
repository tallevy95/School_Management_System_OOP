#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <vector>

#include "Person.h"


#ifndef PERSON_CPP_WORKER_H
#define PERSON_CPP_WORKER_H


class Worker: public Person {
private:


protected:
    vector<string> seniority;
    static int basis;

public:
    Worker();
    ~Worker();
    void set_worker_name();
    void set_worker_teac_seniority();
    void set_worker_exec_seniority();

    void W_details();
    virtual float Salary() = 0;

};


#endif //PERSON_CPP_WORKER_H
