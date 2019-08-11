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
        (score < 60) ? (lettergrade=scores[0]):(lettergrade=scores[score/10 -5]);
        lettergrade += (score % 10 < 3 && score != 100) ? ('-') :(score % 10 > 7) ? '+': ' ' ;
        cout << lettergrade << endl;
    }
    return 0;
}
