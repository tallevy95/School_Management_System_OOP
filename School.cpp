#include <iostream>
using namespace std;
#include <string.h>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <cassert>

#include "School.h"
#include "Manager.h"
#include "Pupil.h"
#include "Secretary.h"


int main(){
    School start = School::ret_school();
    start.menu();
}

School::School() {

}

void School::menu(){
    int workers = 0, pupils = 0, choice=0;
    Pupil Stu, *Stu_0 = NULL;
    Manager manager = Manager::ret_manager();
    AdministrationPersonal* admin_worker;
    Worker* worker_worker;
    School school = ret_school();
    bool run = true;

    while (run){
        cout << "Choose:" << endl;
        cout << "    1  - Add pupil."<< endl;
        cout << "    2  - Add teacher."<< endl;
        cout << "    3  - Add Tutor."<< endl;
        cout << "    4  - Add manager."<< endl;
        cout << "    5  - Add Secretary."<< endl;
        cout << "    6  - Print person details."<< endl;
        cout << "    7  - Print outstanding people."<< endl;
        cout << "    8  - Print tutor's class."<< endl;
        cout << "    9  - Highest paid worker."<< endl;
        cout << "    10 - Exit."<< endl;

        cin >> choice;

        switch (choice) {
            case 1: {     // Add pupil
                cin.ignore();
                //Stu_0 = new Pupil();
                Stu = add_pupil();
                //Stu_0 = &Stu;
                //school.Pupils.push_back(&Stu);
                school.operator+=(Stu);
                pupils++;
                break;
            }
            case 2: {     // Add teacher

                break;
            }
            case 3: {     // Add Tutor

                break;
            }
            case 4: {     // Add manager
                cout << "For your information, there can be only one manager." << endl;
                bool check;
                check = Manager::check_manager();      // static function that checks if there is a manager in the system
                if (check) {
                    cin.ignore();
                    manager.set_Manager();
                    workers++;
                    admin_worker = &manager;
                    worker_worker = admin_worker;
                    //Workers.resize(workers);
                    Workers.push_back(worker_worker);
                    break;
                }
                break;
            }
            case 5: {     // Add Secretary
                Secretary secretary;
                secretary.set_secretary();
                break;
            }
            case 6:     // Print person details

                break;

            case 7:{     // Print outstanding people

                break;
            }
            case 8:{     // Print tutor's class

                break;
            }
            case 9:{     // Highest paid worker

                break;
            }
            case 10: {
                cout << "Goodbye!" << endl;
                run = false;
                break;
            }
            default: {        // if the user input doesn't exists
                cout << "Not a Valid Choice." << endl;
                cout << "Choose again." << endl;
                break;
            }
        }
    }
}

Pupil School::add_pupil() {
    Pupil student;
    student.set_pupil();

    return student;
}

School School::ret_school() {
    return School();
}

School & School::operator+=(const Pupil &pupil) {
    const Pupil*temp = &pupil;
    Pupils.push_back(temp);
    assert(Pupils.back() == temp);
    //m_client_number++;

    return *this;
}

