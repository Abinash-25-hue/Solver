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

double number_returner (string st, int start)
{
    stack <int> stuc;
    double final = 0, divid = 0.1;
    int ascii = st[start], mult = 1;

    while (ascii >= 48 && ascii <= 57)\
    {
        int num = ascii - 48;
        stuc.push(num);
        ascii = st[++start];
    }
    while (stuc.empty() == false)
    {
        int temp = stuc.top();
        final += (temp * mult);
        mult *= 10;
        stuc.pop();
    }

    if (ascii == 46)
    {
        ascii = st[++start];
        while (ascii >= 48 && ascii <= 57)
        {
            int num = ascii - 48;
            stuc.push(num);
            ascii = st[++start];
        }
        stack <int> deci;
        while (stuc.empty() == false)
        {
            deci.push(stuc.top());
            stuc.pop();
        }
        while (deci.empty() == false)
        {
            int temp = deci.top();
            final += (temp * divid);
            divid /= 10;
            deci.pop();
        }
    }

    return final;
}

int precedence_giver (char symbol)
{
    if (symbol == '^')
    {
        return 5;
    }
    else if (symbol == '*' || symbol == '/')
    {
        return 3;
    }
    else if (symbol == '+' || symbol == '-')
    {
        return 1;
    }
    return 0;
}

int main ()
{
    vector <string> test_1;
    test_1.push_back("(2+3)*4");
    test_1.push_back("(2+3*(4))");
    test_1.push_back("(2+3*(4)");
    test_1.push_back("2+3*(4))");
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

    double six_eight = number_returner("68", 0), d = number_returner("12.345", 0);
    cout<< endl<< six_eight<< endl;
    cout<< d<< endl;

    return 0;
}