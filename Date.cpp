//
// Created by Edgar Davtyan  on 4/10/18.
//

#include <iostream>
#include "Date.h"
#include <string>

Date::Date() {
    m_day = 1;
    m_month = 1;
    m_year = 1900;
}

void Date::setDate(int day, int month, int year)
{
    if(isValidDate(day, month, year)){
        m_day = day;
        m_month = month;
        m_year = year;
    } else {
        printStatus();
    }
}

int Date::getDay(){
    return m_day;
}

int Date::getMonth() {
    return m_month;
}

int Date::getYear() {
    return m_year;
}

void Date::compare(Date d1, Date d2) {
    if(d1.getYear()<d2.getYear()) std::cout<<"first input date is earlier"<<std::endl;
    else if (d1.getYear()>d2.getYear()) std::cout<<"second input date is earlier"<<std::endl;
    else if (d1.getMonth()<d2.getMonth()) std::cout<<"first input date is earlier"<<std::endl;
    else if (d1.getMonth()>d2.getMonth()) std::cout<<"second input date is earlier"<<std::endl;
    else if (d1.getDay()<d2.getDay()) std::cout<<"first input date is earlier"<<std::endl;
    else if (d1.getDay()>d2.getDay()) std::cout<<"second input date is earlier"<<std::endl;
    else std::cout<<"Identical dates"<<std::endl;
}

void Date::printDate(int version)
{
    if(isValidDate(m_day,m_month,m_year) && version == 1){
        std::cout<<m_day<<" "<<monthArr[m_month-1]<<","<<m_year<<std::endl;
    } else if(isValidDate(m_day,m_month,m_year) && version == 2){
        std::cout<<monthArr[m_month-1]<<"/"<<m_day<<"/"<<m_year<<std::endl;
    } else if(isValidDate(m_day,m_month,m_year) && version == 3){
        std::cout<<m_day<<" | "<<monthArr[m_month-1]<<" | "<<m_year<<std::endl;
    } else if(isValidDate(m_day,m_month,m_year) && version == 4) {
        std::cout<<m_year<<", "<<monthArr[m_month-1]<<" - "<<m_day<<std::endl;
    } else {
        printStatus();
    }
}

std::string Date::returnDate(int version) {
    if (isValidDate(m_day, m_month, m_year) && version == 1) {
        return std::to_string(m_day) + " " + monthArr[m_month - 1] + "," + std::to_string(m_year);
    } else if (isValidDate(m_day, m_month, m_year) && version == 2) {
        return monthArr[m_month - 1] + "/" + std::to_string(m_day) + "/" + std::to_string(m_year);
    } else if (isValidDate(m_day, m_month, m_year) && version == 3) {
        return std::to_string(m_day) + " | " + monthArr[m_month - 1] + " | " + std::to_string(m_year);
    } else if (isValidDate(m_day, m_month, m_year) && version == 4) {
        return std::to_string(m_year) + ", " + monthArr[m_month - 1] + " - " + std::to_string(m_day);
    } else {
        return "invalid version";
    }
}


bool Date::isLeap(int year)
{
    // Return true if year is a multiple pf 4 and
    // not multiple of 100.
    // OR year is multiple of 400.
    return (((year%4==0) && (year%100!=0)) ||
            (year%400==0));
}
bool Date::isValidDate(int d, int m, int y)
{
    // If year, month and day are not in given range
    if (y < 1800 || y > 9999) {// setting minimal and minimal year
        std::cout<<"check ";
        status = 1;
        return false;
    }
    if (m < 1 || m > 12) {
        status = 2;
        return false;
    }
    if (d < 1 || d > 31) {
        status = 3;
        return false;
    }
    // Handle February month with leap year
    if (m == 2)
    {
        if (isLeap(y)) {
            status = 4;
            return (d <= 29);
        }
        else {
            status = 5;
            return (d <= 28);
        }
    }

    // Months of April, June, Sept and Nov
    // must have number of days less than
    // or equal to 30.
    if (m==4 || m==6 || m==9 || m==11) {
        status = 6;
        return (d <= 30);
    }
    status = 0;
    return true;
}

void Date::printStatus() {
    switch (status) {
        case 1:
            std::cout << "exceeded year limitations, valid year range is 1800 - 9999" << std::endl;
            break;
        case 2:
            std::cout << "invalid month" << std::endl;
            break;
        case 3:
            std::cout << "incorrect day, max 31" << std::endl;
            break;
        case 4:
            std::cout << "February has at max 29 days this year" << std::endl;
            break;
        case 5:
            std::cout << "February has at max 28 days this year" << std::endl;
            break;
        case 6:
            std::cout << "incorrect day, max 30" << std::endl;
            break;
    }
}