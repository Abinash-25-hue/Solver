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

bool valid_decimal (string st)
{
    bool is_number = false;
    int ascii, count = 0;

    for (int index = 0; index < st.size(); index++)
    {
        ascii = st[index];
        if (ascii >= 48 && ascii <= 57)
        {
            is_number = true;
        }
        else if (ascii == 46)
        {
            int temp_ascii = st[index + 1];
            if (is_number == false && (temp_ascii < 48 || temp_ascii > 57))
            {
                return false;
            }
            count++;
        }
        else if (ascii < 48 || ascii > 57)
        {
            if (is_number)
            {
                is_number = false;
                count = 0;
            }
        }

        if (count > 1)
        {
            return false;
        }
    }
    return true;
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

string string_slicer (string st, int start, int end)
{
    if (start > end)
    {
        return "";
    }
    if (start < 0)
    {
        start = 0;
    }
    string final = "";
    for (int index = start; index < end && index < st.size(); index++)
    {
        final += st[index];
    }
    return final;
}

int number_selector (string st, int start)
{
    int ascii = st[++start];
    while ((ascii >= 48 && ascii <= 57) || (ascii == 46))
    {
        ascii = st[++start];
    }
    return start;
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
        if (valid_brackets(str))
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

    vector <int> test_2;
    test_2.push_back(precedence_giver('^'));
    test_2.push_back(precedence_giver('*'));
    test_2.push_back(precedence_giver('+'));
    test_2.push_back(precedence_giver('a'));
    test_2.push_back(precedence_giver(' '));

    cout<< endl;
    for (int x : test_2)
    {
        cout<< x<< endl;
    }

    vector <string> test_3;
    test_3.push_back(string_slicer("abcde", 1, 4));
    test_3.push_back(string_slicer("abcde", 0, 0));
    test_3.push_back(string_slicer("abcde", 1, 9));
    test_3.push_back(string_slicer("abcde", -7, 4));
    test_3.push_back(string_slicer("abcde", 4, 1));

    cout<< endl;
    for (string x : test_3)
    {
        cout<< x<< endl;
    }
    
    vector <string> test_4;
    test_4.push_back("(2+3)*4");
    test_4.push_back("(2.3 + 4)* 5.7");
    test_4.push_back(" 2.3.4 + (5 * 3.4)");
    test_4.push_back("2.3 + 5. - 6");
    test_4.push_back("3* (.5 + 7)");
    test_4.push_back(" (4 -9) * . + 7");
    test_4.push_back("");

    for (string s : test_4)
    {
        if (valid_decimal(s))
        {
            cout<< "True"<< endl;
        }
        else
        {
            cout<< "False"<< endl;
        }
    }

    return 0;
}