#include <iostream>
#include <stdio.h>
#include <string>
#include <vector>
#include <deque>
#include <list>

using std::cin;
using std::cout;
using std::endl;
using std::deque;
using std::string;
using std::list;

int main()
{
    string word;
    //deque<string> deque0;
    list<string> deque0;

    while (cin >> word)
    {
        deque0.push_back(word);
    }

    for (auto p : deque0)
    {
        cout << p << endl;
    }

    return 0;
}

