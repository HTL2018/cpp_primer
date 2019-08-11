#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;
using std::endl;
using std::string;

int main()
{
    int score = 0;
    string lettergrade = " ";
    while (cin >> score)
    {
        const vector<string> scores = {"F", "D", "C", "B", "A", "A++"};
        if (score < 60)
            lettergrade = scores[0];
        else
        {
            lettergrade = scores[score/10 - 5];
            if (score != 100)
            {
            if (score % 10 > 7)
                lettergrade += '+';
            else if(score % 10 < 3)
                lettergrade += '-';
            }
        }
        cout << lettergrade << endl;
    }
    return 0;
}
