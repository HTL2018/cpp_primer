  #include <iostream>
  #include <cstddef>
  #include <vector>
  #include <iterator>
  #include <cstring>

  using std::cin;
  using std::endl;
  using std::cout;
  using std::vector;
  using std::begin;
  using std::end;
  using std::string;

  int main()
{
    /* //比较两个字符串
    string s1 = "A string example";
    string s2 = "A different string";
    if (s1 < s2)
    {
        cout << " s1 < s2";
    }
    else
    {
        cout << " s1 > s2";
    }
    */

    const char ca1[] = "asdfghjkl ";
    const char ca2[] = "asdfghjkll ";
    const char ca3[] = "asdfghjkl ";
    const char ca4[] = "asdfghjk";

    if (strcmp(ca1, ca4) == 0)
    {
        cout << "equal." << endl;
    }
    else
    {
        if (strcmp(ca1, ca4) < 0)
            cout << ca1 << " < " << ca4 << endl;
        else
            cout << ca1 << ">" << ca4 << endl;
    }
    return 0;
}
