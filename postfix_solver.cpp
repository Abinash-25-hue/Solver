#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool validity_checker (string st)
{
    stack <char> s;
    for (int index = 0; index < st.size(); index++)
    {
        if (st[index] == '(' || st[index] == '{' || st[index] == '[')
        {
            s.push(st[index]);
        }
        if (st[index] == ')' || st[index] == '}' || st[index] == ']')
        {
            if (s.empty())
            {
                return false;
            }
            if (s.top() == '(' && st[index] == ')')
            {
                s.pop();
            }
            else if (s.top() == '{' && st[index] == '}')
            {
                s.pop();
            }
            else if (s.top() == '[' && st[index] == ']')
            {
                s.pop();
            }
            else
            {
                return false;
            }
        }
    }
    if (s.empty())
    {
        return true;
    }
    return false;
}

int main ()
{
    vector <string> test_1;
    test_1.push_back("(2+3)*4");
    test_1.push_back("(2+3*(4))");
    test_1.push_back("((()(())))");
    test_1.push_back("{}[]()");
    test_1.push_back("{[[]]({}[])}");
    test_1.push_back("{(})");
    test_1.push_back("");

    for (string str : test_1)
    {
        if (validity_checker(str))
        {
            cout<< "True";
        }
        else
        {
            cout<< "False";
        }
        cout<< endl;
    }

    return 0;
}