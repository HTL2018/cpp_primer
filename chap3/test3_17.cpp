#include <iostream>
#include <vector>
using std::cin;
using std::cout;
using std::string;
using std::endl;
using std::vector;

int main()
{
    string word;
    vector<string> text;
    while (cin >> word){
        text.push_back(word);
    }
    for (auto &word1 : text)
    {
        for (auto &c : word1)
        {c = toupper(c);}
        cout << word1 << endl;
    }
    return 0;
}
