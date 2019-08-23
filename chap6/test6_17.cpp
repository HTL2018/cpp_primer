#include <iostream>

using std::cin;
using std::cout;
using std::endl;
using std::string;

      bool is_upper(const string &str)
      {
          for (auto i : str)
          {
              if (isupper(i))
              {
                  return 1;
              }
          }
          return 0;
      }

void to_lower(string &str1)
{
    for (int i=0; i <str1.size(); ++i)
    {
        str1[i]= tolower(str1[i]);
    }
}

int main()
{
    string str1;
    cin >> str1;
    to_lower(str1);

    cout << str1 << endl;
    return 0;
}
