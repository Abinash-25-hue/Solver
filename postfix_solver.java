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
