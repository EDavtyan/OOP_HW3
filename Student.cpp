//
// Created by Edgar Davtyan  on 4/17/18.
//

#include "Student.h"

int Student::m_count = 0;

Student::Student(std::string name1, std::string name2, std::string faculty) {
    idNum = ++m_count;
    m_firrstName = name1;
    m_secondName = name2;
    m_faculty = faculty;
    m_id = "AUA_" + faculty + "_" + std::to_string(idNum);
}

Student::Student(const Student& p) {
    idNum = ++m_count;
    m_faculty = p.m_faculty;
    m_id = "AUA_" + p.m_faculty+"_" + std::to_string(idNum);
}


void Student::set_birth_date(int day, int month, int year) {
    m_birthDate.setDate(day, month, year);
}


void Student::set_name(std::string name1, std::string name2) {
    m_firrstName = name1;
    m_secondName = name2;
}

std::string Student::get_birth_date() {
    return m_birthDate.returnDate(4);
}


std::string Student::get_first_name() {
    return m_firrstName;
}


std::string Student::get_last_name() {
    return m_secondName;
}


std::string Student::get_id() {
    return m_id;
}