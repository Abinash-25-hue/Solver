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

bool valid_operators (string st)
{
    bool is_number = false, is_operator = false, was_bracket_open = false, was_bracket_closed = false;
    if (st[0] >= '0' && st[0] <= '9')
    {
        is_number = true;
    }
    else if (st[0] == '+' || st[0] == '*' || st[0] == '/')
    {
        return false;
    }
    else if (st[0] == '-')
    {
        is_operator = true;
    }
    for (int index = 1; index < st.size(); index++)
    {
        char c = st[index];
        if (c == '+' || c == '*' || c == '-' || c == '/')
        {
            if (is_operator == true)
            {
                return false;
            }
            else
            {
                is_operator = true;
                if (is_number == true)
                {
                    is_number = false;
                }
                if (was_bracket_open == true)
                {
                    return false;
                }
                
            }
        }
        if (c >= '0' && c <= '9')
        {
            if (is_operator == true)
            {
                is_operator = false;
            
            }
            else if (is_operator == false)
            {
                return false;
            }
            is_number = true;
        }
        if (c == '(')
        {
            was_bracket_open = true;
            was_bracket_closed = false;
            if (is_number == true)
            {
                return false;
            }
            is_operator = false;
        }
        if (c == ')')
        {   
            was_bracket_closed = true;
            was_bracket_open = false;
            if (is_operator == true)
            {
                return false;
            }
        }
    }
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

string postfixer (string eq)
{
    stack <char> stacc;
    string output = "";

    for (int index = 0; index < eq.size(); index++)
    {
        char c = eq[index], temp;
        if (c == '(')
        {
            stacc.push('(');
        }
        else if (c == ')')
        {
            while (stacc.top() != '(')
            {
                output += stacc.top();
                output += ' ';
                stacc.pop();
            }
            stacc.pop();
        }
        else if (c == '^')
        {
            stacc.push('^');
        }
        else if (c == '*' || c == '/')
        {
            if (stacc.empty() == false)
            {
                while (precedence_giver(stacc.top()) >= precedence_giver(c))
                {
                    output += stacc.top();
                    output += ' ';
                    stacc.pop();
                }
            }
            stacc.push(c);
        }
        else if (c == '+' || c == '-')
        {
            if (stacc.empty() == false)
            {
                while (precedence_giver(stacc.top()) >= precedence_giver(c))
                {
                    output += stacc.top();
                    output += ' ';
                    stacc.pop();
                }
            }
            stacc.push(c);
        }
        else if ((c >= '0' && c <= '9') || c == '.')
        {
            int till = number_selector(eq, index);
            string number = string_slicer(eq, index, till);
            output += number;
            output += ' ';
        }
    }
    while (stacc.empty() == false)
    {
        output += stacc.top();
        output += ' ';
        stacc.pop();
    }
    return output;
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
    cout<< endl;
    
    vector <string> test_5;
    test_5.push_back("^");
    test_5.push_back(",");
    test_5.push_back("(2+3)*4");
    test_5.push_back("(2 + 3)* 4");
    test_5.push_back("(2+x)*4");

    for (string s : test_5)
    {   
        if (valid_symbol(s))
        {
            cout<< "True";
        }
        else
        {
            cout<< "False";
        }
        cout<< endl;
    }


    vector <string> test_6;
    test_6.push_back("(2+3)*4");
    test_6.push_back("(2++3)*4");
    test_6.push_back("(2+ +3)*4");
    test_6.push_back("(2 3)*4");
    test_6.push_back("(2 +)*4");
    test_6.push_back("(2 + )*4");
    test_6.push_back("3 (2 +5)*4");
    test_6.push_back("3(2 +5)*4");
    test_6.push_back("3+(2 +5)*4"); 


    cout<< endl;
    for (string s : test_6)
    {
        if (valid_operator(s))
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