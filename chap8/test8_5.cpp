#include <iostream>
#include <vector>
#include <stdio.h>
#include <string.h>
#include <fstream>

using std::cin;
using std::cout;
using std::endl;
using std::vector;
using std::ifstream;
using std::string;

void read_file2vec(const string& filename, vector<string>& vec)
{
    ifstream ifs(filename);
    if (ifs)
    {
        string buf;
        while (ifs >> buf)
            vec.push_back(buf);
    }
}

int main()
{
    vector<string> vec;
    read_file2vec("./test8_2.cpp", vec);
    for (const auto &str : vec)
    {
        cout << str << endl;
    }
    return 0;
}
