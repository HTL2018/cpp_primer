#include <stdio.h>
#include <iostream>
#include <vector>

using std::vector;

bool find_val(vector<int>::const_iterator begin, vector<int>::const_iterator end, int val)
{
    bool flag = 0;
    for (; begin != end; ++begin)
    {
        if (*begin == val)
        {
            flag = 1;
            return flag;
        }

    }
    return flag;
}

int main()
{
    int final_flag = 0;
    vector<int> vec1 = {1,2,3,3,4,5};
    final_flag = find_val(vec1.begin(), vec1.end(), 5);
    std::cout << final_flag << std::endl;

    return 0;
}
