#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;
using std::isalpha;
using std::toupper;

int main()
{
    vector<string> text;//text必须是vector是容器;
    vector<int>::iterator it;//因为需要写入进行更改,所以不能变成congst_iterator
    for (string line; getline(cin, line); text.push_back(line));

    for (auto it = text.begin(); it != text.end() && !it->empty(); ++it)
    {
        for (auto &word : (*it))
        {
            if (isalpha(word)) word = toupper(word);
        }
        cout << *it << " ";
    }

    return 0;
}
