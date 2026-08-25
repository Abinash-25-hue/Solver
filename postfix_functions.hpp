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

bool valid_operator (string str)
{
    bool was_operator = false;
    bool was_number = false;
    bool was_space = false;
    bool was_bracket_open = false;
    bool was_bracket_closed = false;

    char c = str[0];
    for (int index = 0; index < str.size(); index++)
    {
        c = str[index];
        if (c == '+' || c == '*' || c == '/')
        {
            if (was_operator == true)
            {
                //cout<< c<< "-1, ";
                return false;
            }
            else
            {
                //cout<< c<< "-2, ";
                was_operator = true;
                was_number = false;
                was_space = false;
            }
        }
        if (c >= '0' && c <= '9')
        {
            if (was_number && was_space && was_operator == false)
            {
                //cout<< c<< "-3, ";
                return false;
            }
            if (was_number == false)
            {
                //cout<< c<< "-4, ";
                was_number = true;
                was_space = false;
                was_operator = false;
            }
        }
        if (c == ' ')
        {
            //cout<< c<< "5, ";
            was_space = true;
        }
        if (c == '(')
        {
            was_bracket_open = true;
            was_number = false;
            was_space = false;
            was_operator = false;
        }
        if (c == ')')
        {
            if (was_operator)
            {
                return false;
            }
            else
            {
                was_bracket_closed = true;
                was_number = false;
                was_space = false;
                was_operator = false;
            }
        }

    }
    return true;
}

bool valid_exponent (string eq)
{
    bool symbol_appeared = false;
    bool number_appeared = false;
    for (int index = 0; index < eq.size(); index++)
    {
        if (eq[index] == '^')
        {
            symbol_appeared = true;
        }
        if (eq[index] == '+' || eq[index] == '-' || eq[index] == '*' || eq[index] == '/')
        { 
            symbol_appeared = false;
            number_appeared = false;
        }
        if ((eq[index] >= '0' && eq[index] <= '9') || (eq[index] == '.'))
        {
            number_appeared = true;
        }//if (eq[index] == ' ' || eq[index] == '(' || eq[index] == ')')
        else
        {
            number_appeared = false;
        }

        if (eq[index] == '.' && symbol_appeared == true && number_appeared == true)
        {
            return false;
        }
    }
    return true;
}
