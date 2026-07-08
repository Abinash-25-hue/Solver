import java.util.*;

public class postfix_solver 
{
    String eq;
    String output = new String ("");

    public postfix_solver (String eq)
    {
        this.eq = eq;
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

    public static void main (String[] args)
    {
        Scanner sc = new Scanner (system.in);
    }
}
