#ifndef CP5_test7_09_h
#define CP5_test7_09_h

#include <string>
#include <iostream>

using std::string;

struct Person {
    string name;
    string address;
    string get_name() const { return this->name; }
    string get_address() const { return this->address; }
}; //此处分号必不可忘

std::istream &read(std::istream &is, Person &per)
{
    is >> per.name >> per.address;
    return is;
}

std::ostream &print(std::ostream &os, const Person &per)
{
    os << per.name << " " << per.address;
    return os;
}

#endif
