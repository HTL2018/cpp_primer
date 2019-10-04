#ifndef CP5_test7_22_h
#define CP5_test7_22_h

#include <string>
#include <iostream>

using std::string;

class Person {
    friend std::istream &read(std::istream &is, Person &per);
    friend std::ostream &print(std::ostream &is, const Person &per);

    public:
        string get_name() const { return this->name; }
        string get_address() const { return this->address; }
        Person() = default;
        Person(const string &sname, const string &saddr) : name(sname), address(saddr) {};
        Person(std::istream &is) { read(is, *this); };

    private:
        string name;
        string address;
};

//std::istream &read(std::istream &is, Person &per);
//std::ostream &print(std::ostream &is, Person &per);

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
