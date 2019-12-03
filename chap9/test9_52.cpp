#include <iostream>
#include <string>
#include <stack>

using std::cin;
using std::cout;
using std::endl;
using std::stack;
using std::stack;
using std::string;

int main()
{
    string expression{"This is (pezy)."};
    bool bSeen = false;
    stack<char> stk;
    for (const auto &s : expression)
    {
        if ( s == '(' ) { bSeen = true; continue; }
        else if (s == ')') bSeen = false;

        if (bSeen) stk.push(s);
    }

    //将栈中的元素转化为字符串repstr
    string repstr;
    while(!stk.empty())
    {
        repstr += stk.top();
        stk.pop();
    }

    //将栈中元素转化得到的字符串放入表达式中并输出
    expression.replace(expression.find("(") + 1, repstr.size(), repstr);

    cout << expression << endl;

    return 0;

}
