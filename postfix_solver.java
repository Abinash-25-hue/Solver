import java.util.*;

public class postfix_solver 
{
    String eq;
    String output = new String ("");

    public postfix_solver (String eq)
    {
        this.eq = eq;
    }

    public static boolean valid_brackets (String equation)
    {
        ArrayList <Character> stack = new ArrayList<>();
        int last = 0;

        //char [] eq_array = eq.toCharArray();
        char [] eq_array = equation.toCharArray();
        for (int index = 0; index < eq_array.length; index++)
        {
            char c = eq_array[index];
            if (c == '(' || c == '{' || c == '[')
            {
                stack.add(c);
                last++;
            }
            else if (c == ')' || c == ')' || c == ']')
            {
                if (stack.isEmpty() == true)
                {
                    return false;
                }
                if (c == ')' && stack.get(last) == '(')
                {
                    stack.remove(last);
                    last--;
                }
                else if (c == '}' && stack.get(last) == '{')
                {
                    stack.remove(last);
                    last--;
                }
                else if (c == ']' && stack.get(last) == '[')
                {
                    stack.remove(last);
                    last--;
                }
                else
                {
                    return false;
                }
            }
        }
        if (stack.isEmpty() == true)
        {
            return true;
        }
        return false;
    }

    public static boolean valid_symbols (String equation)
    {
        char[] eq_array = equation.toCharArray();
        //char eq_array[] = eq.toCharArray();
        for (int index = 0; index < eq_array.length; index++)
        {
            char c = eq_array[index];
            if (((c < '(' || c > '9') && (c != ' ')) || (c == ','))
            {

                return false;
            }
        }      
        return true;  
    }

    public static boolean valid_operators (String equation)
    {
        char[] eqa = equation.toCharArray();
        //char [] eqa = eq.toCharArray();

        boolean was_number = false;
        boolean was_operator = false;
        boolean was_bracket_open = false;
        boolean was_bracket_closed = false;

        for (int index = 0; index < eqa.length; index++)
        {
            
            char c = eqa[index];

            if ((c >= '0' && c <= '9') || c == '.')
            {
                if (was_number == true)
                {
                    return false;
                }
                was_number = true;
                was_operator = false;
            }
            if (c == '+' || c == '-' || c == '*' || c == '/' || c == '^')
            {
                if (was_operator == true)
                {
                    return false;
                }
                was_number = false;
                was_operator = true;
            }
            if (c == '(')
            {
                was_number = false;
                was_operator = false;
                was_bracket_open = true;
                was_bracket_closed = false;
            }
            if (c == ')')
            {
                if (was_number == false || was_operator == false)
                {
                    return false;
                }
                was_number = false;
                was_operator = false;
                was_bracket_open = false;
                was_bracket_closed = true;
            }
        }
        return true;
    }

    public String string_slicer(int start, int finish)
    {
        String sliced = eq.substring(start, finish);
        return sliced;
    }

    int precedence_giver (char c)
    {
        if (c == '^')
        {
            return 5;
        }
        else if (c == '*' || c == '/')
        {
            return 3;
        }
        else if (c == '+' || c == '-')
        {
            return 1;
        }
        return 0;
    }

    public static void main (String[] args)
    {
        Scanner sc = new Scanner (System.in);

        //ArrayList <String> test_1 = new ArrayList<>();
        /*postfix_solver[] test_1 = new postfix_solver[5];

        test_1[0] = new postfix_solver("2+3");
        test_1[1] = new postfix_solver("(2+3)*4");
        test_1[2] = new postfix_solver("  ");
        test_1[3] = new postfix_solver("2+a*4");
        test_1[4] = new postfix_solver("(2+8);");*/

        ArrayList <String> test_1 = new ArrayList<>();
        test_1.add("2+3");
        test_1.add("(2+3)*4");
        test_1.add("  ");
        test_1.add("2+a*4");
        test_1.add("(2+8);");

        for (int index = 0; index < 5; index++)
        {
            if (valid_symbols(test_1.get(index)))
            {
                System.out.println("True");
            }
            else
            {
                System.out.println("False");
            }
        }
        
        //String temp = test_1[1].string_slicer(1, 4);
        //System.out.println(temp);

        /*From test_2 onwards all the testcases will passed as argument to the method and not the data members of the object,
        this is done to make testing more fast and efficient.
        
        To do this, the code block that all the functions use to access the 'eq' data member will be commented out and new code 
        block to execute the argument will be coded. 
        
        After testing, all the functions will be reverted back to its original intended operations of performing it on 
        'eq' data member of the postfix_solver class. */


        ArrayList <String> test_2 = new ArrayList <>();
        test_2.add("(2+3)*4");
        test_2.add("(2+3*4");
        test_2.add("({}[]){}");
        test_2.add("(2+3)*((6 +7) -8)");
        test_2.add(" ");
        test_2.add("5 ^ 6");
        test_2.add("{[}]");


    }
}
