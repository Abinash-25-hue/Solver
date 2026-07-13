import java.util.*;

public class postfix_solver 
{
    String eq;
    String output = new String ("");

    public postfix_solver (String eq)
    {
        this.eq = eq;
    }

    public boolean valid_brackets ()
    {
        ArrayList <Character> stack = new ArrayList<>();
        int last = 0;

        char [] eq_array = eq.toCharArray();
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

    public boolean valid_symbols ()
    {
        char eq_array[] = eq.toCharArray();
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

    public boolean valid_operators ()
    {
        char [] eqa = eq.toCharArray();

        boolean was_number = false;
        boolean was_operator = false;
        boolean was_bracket_open = false;
        boolean was_bracket_closed = false;

        for (int index = 0; index < eq.length; index++)
        {
            
        }
    }

    public String string_slicer(int start, int finish)
    {
        String sliced = eq.substring(start, finish);
        return sliced;
    }

    public static void main (String[] args)
    {
        Scanner sc = new Scanner (System.in);

        //ArrayList <String> test_1 = new ArrayList<>();
        postfix_solver[] test_1 = new postfix_solver[5];

        test_1[0] = new postfix_solver("2+3");
        test_1[1] = new postfix_solver("(2+3)*4");
        test_1[2] = new postfix_solver("  ");
        test_1[3] = new postfix_solver("2+a*4");
        test_1[4] = new postfix_solver("(2+8);");

        for (int index = 0; index < 5; index++)
        {
            if (test_1[index].valid_symbols())
            {
                System.out.println("True");
            }
            else
            {
                System.out.println("False");
            }
        }
        
        String temp = test_1[1].string_slicer(1, 4);
        System.out.println(temp);
    }
}
