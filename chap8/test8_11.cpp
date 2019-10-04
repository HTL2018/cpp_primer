#include <iostream>
#include <stdio.h>
#include <fstream>
#include <sstream>
#include <string>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::vector;
using std::fstream;
using std::istringstream;

struct PersonInfo {
    string name;
    vector<string> phones;
};

int main()
{
    string line, word;
    vector<PersonInfo> people;
    istringstream record(line);

    while(getline(cin, line))
    {
        PersonInfo Info;
        record.clear();
        record.str(line);
        record >> Info.name;
        while (record >> word)
        {
            Info.phones.push_back(word);
        }
        people.push_back(Info);
    }

    for (auto &p: people)
    {
        cout << p.name << endl;
        for (auto &s : p.phones)
        {
            cout << s << endl;
        }
        cout << endl;
    }

    return 0;
}
