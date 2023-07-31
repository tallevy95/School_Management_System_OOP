/* Assignment C++: 3
Author: Tal Levy, ID: 314966359
Author2: Guy Zalsman, ID:312488794
*/

#include <iostream>
using namespace std;
#include <string.h>
#include <string>
#include <stdlib.h>
#include <cstring>
#include <vector>
#include <cassert>


#include "School.h"
#include "Manager.h"
#include "Pupil.h"
#include "Secretary.h"
#include "VecAnalyser.h"
#include "VecAnalyser.cpp"
#include "Tutor.h"

School* School::school = 0;

School* School::getSchool()  {
    if (!school)
        return school = new School();
    return school;
}   //Returns a school-type object if it does not already exist

School::School() {}

char School::check_layer(char ch){
    char all_layers[6] = {'a','b','c','d','e','f'};
    bool run = true;
    while (run) {
        for (char all_layer : all_layers) {
            if (ch == all_layer) {
                run = false;
                break;
            }
        }
        if (run) {
            cout << "Invalid Layer... Please try again" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> ch;
        }
    }

    return ch;
}   //check the if the Layer input correct


int School::check_class(int number) {
    int all_class[3] = {1,2,3};
    bool run = true;
    while (run) {
        for(int all_clas : all_class){
            if(number == all_clas){
                run = false;
                break;
            }
        }
        if (run){
            cout << "Invalid Class... Please try again" << endl;
            cin.clear();
            cin.ignore(1000, '\n');
            cin >> number;
        }
    }
    return number;
}   //check the if the class input correct

void School::check_cl_la_exists(int cl, char la, Pupil pupil)
{
    vector<Class *> class_vec;

    int PupilNumbers = 0;

    for (int i = 0; i < m_layer.size(); i++)
    {

        // check if the layer exists int the school
        if (la == m_layer[i]->getLayerName())
        {
            //get the class vec from the layer
            class_vec = m_layer[i]->getClass();

            for (int j = 0; j < class_vec.size(); j++)
            {
                // check if the class exists int the layer
                if (cl == class_vec[i]->getClassName())
                {
                    //push the pupil to the class
                    class_vec[i]->InsertPupil(&pupil);

                    //Updates the number of students in the class
                    PupilNumbers = class_vec[i]->getPupilNumbers();
                    PupilNumbers += 1;
                    class_vec[i]->setPupilNumbers(PupilNumbers);
                } else {
                    //check if there is already 3 classes
                    if (class_vec.size() > 3)
                    {
                        cout << "Sorry full layer, it's already with 3 classes" << endl;

                        cout << "please choose one of this classes:" << endl;

                        for (int p = 0 ; p < class_vec.size(); p++)
                        {
                            cout << class_vec[p]->getClassName() << ",";
                        }

                        cin.clear();
                        cin.ignore(1000, '\n');
                        cin >> cl;

                    }
                    else
                        {
                        //create class and push the pupil to the class
                        Class create_class(la, cl);
                        create_class.InsertPupil(&pupil);

                        //Updates the number of students in the class
                        PupilNumbers = class_vec[i]->getPupilNumbers();
                        PupilNumbers += 1;
                        class_vec[i]->setPupilNumbers(PupilNumbers);

                        //push the class to the class vector of the layer
                        class_vec.push_back(&create_class);
                    }
                }

            }
        }
        // if the layer is not exists
        else
        {
            //check if  the number layers in the school smaller than 6
            if (m_layerNumber > 6)
            {
                cout << "Sorry full school, it's already with 6 layers" << endl;

                cout << "please choose one of this layer:" << endl;

                for (int p = 0 ; p < m_layer.size(); p++)
                {
                    cout << m_layer[p]->getLayerName() << ",";
                }

                cin.clear();
                cin.ignore(1000, '\n');
                cin >> la;
            }
            else
            {
                //create layer and push the layer to the layer vector
                Layer layer(la);
                m_layerNumber += 1;
                m_layer.push_back(&layer);

                //create class and push the class to the class vector
                Class create_class(la, cl);

                class_vec = layer.getClass();
                class_vec.push_back(&create_class);

                // push the student to the class
                create_class.InsertPupil(&pupil);

                //Updates the number of students in the class
                PupilNumbers = class_vec[i]->getPupilNumbers();
                PupilNumbers += 1;
                class_vec[i]->setPupilNumbers(PupilNumbers);


            }
        }
    }
}
string School::firstname() {
    string firstName;
    cout << "First name: " << endl;
    cin.clear();
    cin.ignore(1000, '\n');
    getline (cin,firstName);

    return firstName;
}   //get the first name from the user

string School::lastname() {
    string lastName;
    cout << "Last name: " << endl;
    cin.clear();
    //cin.ignore(1000, '\n');
    getline (cin,lastName);

    return lastName;
}   //get the last name from the user

int School::WorkerSeniority() {
    int seniority;
    cout << "Enter the years of seniority: " << endl;
    cin.clear();
    cin >> seniority;

    return seniority;
}//get the Worker seniority from the user

void School::menu(){
    int  choice=0, number_of_manager=0;
    //create objects
    Pupil pupil;
    Teacher teacher;
    Tutor tutor;
    Secretary secretary;


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
            // Add pupil
            case 1: {
                char pupil_layer;
                int pupil_class, NumOfSubjects,grade;
                vector<pair<string,int>> grades;
                string pupil_firstname , pupil_lastname,subject;

                cout << "For adding a new pupil, Please enter the next details:" << endl;

                pupil_firstname = firstname();      //get name from the user
                pupil_lastname = lastname();


                pupil.setFirstName(pupil_firstname);    //set the name
                pupil.setLastName(pupil_lastname);

                cout << "Layer (Enter only one character from a - f): " << endl;
                cin.clear();
                cin >> pupil_layer;
                pupil_layer = check_layer(pupil_layer);
                pupil.setLayer(pupil_layer);        //set layer


                    cout << "Class (Enter only one digit from 1 - 3): " << endl;
                cin.clear();
                cin >> pupil_class;
                pupil_class = check_class(pupil_class);
                pupil.setClass(pupil_class);        //set class

                cin.clear();
                cout << "Please enter how many subjects the pupil take: (At least 1)" << endl;
                cin >> NumOfSubjects;        //set object of the pupil

                cout << "Enter your subject and grade: " << endl;
                for(int i=0;i<NumOfSubjects;i++) {        //create vector of grades
                    cout << i + 1 << ". " <<"Subject: ";
                    cin.clear();
                    cin.ignore(1000, '\n');
                    getline(cin, subject);
                    grades.push_back(make_pair(subject,0));

                    cout << "Grade: ";
                    cin >> grade;
                    grades[i].second = grade;
                    if (grades[i].second < 0 || grades[i].second > 100) {             // check if the grade is correct
                        cout << "Invalid Grade... Please try again" << endl;
                        cin.clear();
                        cin >> grade;
                        grades[i].second = grade;
                    }
                }
                pupil.setGrades(grades);

                m_pupil.push_back(&pupil);

                break;
            }
                // Add teacher
            case 2: {
                int teacher_seniority, teacher_numberOfClasses;
                vector<string> classNames;
                string teacher_firstname , teacher_lastname;
                cout << "For adding a new teacher, Please enter the next details:" << endl;

                teacher_firstname = firstname();        //get name from the user
                teacher_lastname = lastname();

                teacher.setFirstName(teacher_firstname);        //set name
                teacher.setLastName(teacher_lastname);

                cout << "How many classes does " << teacher.getfirstName() << " teach?" << endl;
                cin.clear();
                cin >> teacher_numberOfClasses;
                teacher.setNumberOfSubject(teacher_numberOfClasses);        // set number of classes

                classNames.resize(teacher_numberOfClasses);        // resize the vector size to as many classes he teach

                cout << "Please enter them here:" << endl;
                for(int i=0;i<teacher_numberOfClasses;i++){
                    cout << i+1 << ". ";
                    cin.clear();
                    cin >> classNames[i];             // set class name
                }
                teacher.setSubjectNames(classNames);

                teacher_seniority = WorkerSeniority();
                teacher.setTeacherSeniority(teacher_seniority);        // set teacher's seniority

                m_worker.push_back(&teacher);
                break;
            }
                // Add Tutor
            case 3: {

                int tutor_seniority, tutor_numberOfSubject;
                int ClassName;
                char Layername;
                vector<string> tutor_SubjectNames;
                vector<Class *> class_vec;
                string tutor_firstname , tutor_lastname;

                cout << "For adding a new Tutor, Please enter the next details:" << endl;

                //set the name
                tutor_firstname = firstname();
                tutor_lastname = lastname();

                tutor.setFirstName(tutor_firstname);
                tutor.setLastName(tutor_lastname);

                // set number of subject
                cout << "How many subject does " << tutor.getfirstName() << " teach?" << endl;
                cin.clear();
                cin >> tutor_numberOfSubject;
                tutor.setNumberOfSubject(tutor_numberOfSubject);

                // resize the vector size to as many classes he teach
                tutor_SubjectNames.resize(tutor_numberOfSubject);

                // set class name
                cout << "Please enter them here:" << endl;
                for(int i=0; i < tutor_numberOfSubject; i++){
                    cout << i+1 << ". ";
                    cin.clear();
                    cin >> tutor_SubjectNames[i];
                }
                teacher.setSubjectNames(tutor_SubjectNames);

                // set teacher's seniority
                tutor_seniority = WorkerSeniority();
                tutor.setTeacherSeniority(tutor_seniority);

                cout << "Please insert the name of the layer that the educator is educating in:" << endl;
                cin.clear();
                cin >> Layername;

                cout << "Please insert the number of the class that the educator is educating in:" << endl;
                cin.clear();
                cin >> Layername;

                for ( int j= 0; j< m_layer.size(); j++)
                {
                    if (m_layer[j]->getLayerName() == Layername) {
                        class_vec = m_layer[j]->getClass();
                        for (int p = 0; p < class_vec.size(); p++) {
                            if (class_vec[p]->getClassName() == ClassName) {
                                tutor.setClassTutor(m_layer[j]->getClass()[p]);
                            } else {
                                cout << "The class does not exist, please try again..." << endl;

                                cout << "please choose one of this classes:" << endl;

                                for (int p = 0 ; p < class_vec.size(); p++)
                                {
                                    cout << class_vec[p]->getClassName() << ",";
                                }

                                cin.clear();
                                cin.ignore(1000, '\n');
                                cin >> Layername;
                            }
                        }
                    }
                    else
                        {
                        cout << "The layer does not exist, please try again..." << endl;

                        cout << "please choose one of this layer:" << endl;

                        for (int p = 0 ; p < m_layer.size(); p++)
                        {
                                cout << m_layer[j]->getLayerName() << ",";
                        }

                        cin.clear();
                        cin.ignore(1000, '\n');
                        cin >> Layername;
                        }
                    }
                }

                m_worker.push_back(&tutor);

                break;
            }


                // Add manager
            case 4: {

                int managerWorker_seniority, manager_numberOfClasses,managerTeacher_seniority, manager_numberOfKids;
                string manager_firstname , manager_lastname, office_location;
                vector<string> manager_classNames;

                // static function that checks if there is a manager in the system
                Manager* m_manager = Manager::NumberOfmanager();
                if(number_of_manager == 0) { //need to check in the third time the menger enter;
                    number_of_manager = 1;
                    cout << "****************************************" << endl;
                    cout << "Remember, there can be only one manager in this school!" << endl;
                    cout << "****************************************" << endl;
                    cout << "For adding a Manager, Please enter the next details:" << endl;

                    //set the name
                    manager_firstname = firstname();
                    manager_lastname = lastname();

                    //manager->setLastName(manager_lastname);
                    //m_manager->AdministrationPersonal::setLastName(manager_lastname);
                    m_manager->AdministrationPersonal::setFirstName(manager_firstname);
                    m_manager->AdministrationPersonal::setLastName(manager_lastname);

                    managerWorker_seniority = WorkerSeniority();
                    m_manager->AdministrationPersonal::setWorkerSeniority(managerWorker_seniority);

                    cout << "What is the office location?" << endl;
                    cin.clear();
                    cin >> office_location;
                    m_manager->setOfficeLocation(office_location);

                    // if manager also teach
                    string m_choice;
                    cout << "Does the manager also teach? (Y/N)" << endl;
                    cin.clear();
                    cin >> m_choice;
                    if (m_choice == "Y" || m_choice == "y") {

                        // set number of classes
                        cout << "How many classes does " << teacher.getfirstName() << " teach?" << endl;
                        cin.clear();
                        cin >> manager_numberOfClasses;
                        m_manager->setNumberOfSubject(manager_numberOfClasses);

                        // resize the vector size to as many classes he teach
                        manager_classNames.resize(manager_numberOfClasses);

                        // set class name
                        cout << "Please enter them here:" << endl;
                        for (int i = 0; i < manager_numberOfClasses; i++) {
                            cout << i + 1 << ". ";
                            cin.clear();
                            cin >> manager_classNames[i];
                        }
                        m_manager->setSubjectNames(manager_classNames);

                        // set teacher's seniority
                        managerTeacher_seniority = WorkerSeniority();
                        m_manager->AdministrationPersonal::setTeacherSeniority(managerTeacher_seniority);
                    }

                    m_worker.push_back(m_manager);
                    cout << "****************************************" << endl;
                    cout << "Remember, there can be only one manager in this school" << endl;
                    cout << "****************************************" << endl;
                }
                break;
            }

                // Add Secretary
            case 5: {

                int secretary_seniority, secretary_numberOfKids;
                string secretary_firstname , secretary_lastname;

                cout << "For adding a new secretary, Please enter the next details:" << endl;

                //set the name
                secretary_firstname = firstname();
                secretary_lastname = lastname();


                secretary.setFirstName(secretary_firstname);
                secretary.setLastName(secretary_lastname);

                // set secretary's number of kids
                cout << "How many kids does " << secretary.getfirstName() << " have?" << endl;
                cin.clear();
                cin >> secretary_numberOfKids;       // set secretary's number of kids
                secretary.setNumOfKids(secretary_numberOfKids);

                //set the secretary
                secretary_seniority = WorkerSeniority();
                secretary.setWorkerSeniority(secretary_seniority);

                m_worker.push_back(&secretary);
                break;
            }

                // Print person details
            case 6:
                PrintPersonDetails();
                break;

                // Print outstanding people
            case 7:{

                bool Excellent = false;

                //print outstanding workers
                for (int i=0; i< m_worker.size(); i++)
                {
                    if (m_worker[i]->isExcelling()) {
                        m_worker[i]->printDetails();
                        Excellent = true;
                    }
                }

                //print outstanding pupils
                for (int i = 0; i<m_pupil.size(); i++ )
                {
                    if (m_pupil[i]->isExcelling())
                    {
                        m_pupil[i]->printDetails();
                        Excellent = true;
                    }
                }

                if(!Excellent)
                    cout << "Unfortunately there are no outstanding workers or pupils..." << endl;

                break;
            }
                // Print tutor's class
            case 8:{
                HighestPaidWorker();
                break;
            }
                // Highest paid worker
            case 9:{

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

void School::PrintPersonDetails() {
    VecAnalyser<Worker> worker_vec(m_worker);
    VecAnalyser<Pupil> pupil_vec(m_pupil);

    cout << "PUPILS LIST:" << endl;
    pupil_vec.printAll();

    cout << "WORKERS LIST:" << endl;
    worker_vec.printAll();
}

void School::HighestPaidWorker() {

    VecAnalyser<Worker> worker_vec(m_worker);

    worker_vec.printMax();
}

