//
// Created by Edgar Davtyan  on 4/17/18.
//

#ifndef STUDENT_STUDENT_H
#define STUDENT_STUDENT_H

#include <string>
#include "Date.h"

class Student {
public:
    Student(std::string, std::string, std::string);
    Student(const Student&);
    void set_birth_date(int, int, int);
    void set_name(std::string, std::string);
    std::string get_birth_date();
    std::string get_first_name();
    std::string get_last_name();
    std::string get_id();
private:
    static int m_count;
    int idNum;
    std::string m_id;
    std::string m_firrstName;
    std::string m_secondName;
    Date m_birthDate;
    std::string m_faculty;
};


#endif //STUDENT_STUDENT_H
