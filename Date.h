//
// Created by Edgar Davtyan  on 4/10/18.
//

#ifndef DATE_DATE_H
#define DATE_DATE_H
#include <string>

class Date {
private:
    int m_day;
    int m_month;
    int m_year;
    int status;
    std::string monthArr[12] = {"January", "February", "March", "April", "May", "June", "July", "August", "September", "October", "November", "December"};
public:
    Date();
    void setDate(int, int, int);
    std::string returnDate(int);
    void printDate(int version);
    bool isLeap(int );
    bool isValidDate(int, int, int);
    void printStatus();
    void compare(Date, Date);
    int getDay();
    int getMonth();
    int getYear();
};


#endif //DATE_DATE_H
