#include <iostream>
#include "Student.h"

using namespace std;

int main() {
    Student Bogos("Bogos", "foobarYan", "English-and-Communications");
    Student foo("wa","a,","af");
    cout<<Bogos.get_id()<<endl;
    cout<<foo.get_id()<<endl;
    cout<<Bogos.get_id()<<endl;
    cout<<Bogos.get_id()<<endl;
    cout<<foo.get_id()<<endl;
    Student Bedros(Bogos);
    Bedros.set_birth_date(12, 11, 2019);
    Bedros.set_name("Bedros", "BedrosovichevichYan");
    cout<<Bedros.get_birth_date()<<endl;
    cout<<foo.get_first_name();
}