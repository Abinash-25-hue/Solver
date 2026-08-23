#pragma once

#include<iostream>
#include<bits/stdc++.h>
using namespace std;

bool valid_brackets(string st)
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

bool valid_symbol (string st)
{
    for (int index = 0; index < st.size(); index++)
    {
        if ((st[index] < '(' || st[index] > '9') || st[index] == ',')
        {
            if (st[index] != '^' && st[index] != ' ')
            {
                return false;
            }
        }
    }
    return true;
}