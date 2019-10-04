#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

struct Person {
    string name;
    string address;
    string get_name() const { return this->name; }
    string get_address() const { return this->address; }
};

int main()
{
    Person person1;
    while(cin >> person1.name >> person1.address)
    {
        cout << person1.get_name() << endl;
        cout << person1.get_address() << endl;
    }

    return 0;
}
