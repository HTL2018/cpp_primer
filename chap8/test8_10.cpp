#include <iostream>
#include <fstream>
#include <sstream>
#include <stdio.h>
#include <vector>

using std::cin;
using std::cout;
using std::endl;
using std::istringstream;
using std::ifstream;
using std::istream;
using std::vector;
using std::cerr;
using std::string;

int main()
{
    ifstream ifs("./data1.txt");

    if(!ifs)
    {
        cerr << "No data?!" << endl;
        return -1;
    }

    vector<string> vecline;
    string line;
    while(ifs >> line)
    {
        vecline.push_back(line);
    }

    for (auto &s : vecline)
    {
        istringstream iss(s);
        string word;
        while (iss >> word)
        {
            cout << word << endl;
        }
    }

    return 0;
}
