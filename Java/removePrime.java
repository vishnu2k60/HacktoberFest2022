import java.util.*;

public class removePrime {


    public static boolean isPrime(int p )
    {
        for(int i =2;i*i<=p;i++)
        {
            if(p%i==0)
            {
                return false;
            }
        }
        return true;
    }
    public static void removeit(ArrayList<Integer> list)
    {
            for(int i =list.size()-1;i>=0;i--)
            {
                int val =list.get(i);
                if(isPrime(val)==true)
                {
                    list.remove(i);
                }
            }
    }
    public static void main(String[] args)
    {
        Scanner scn =new Scanner(System.in);
        // no. of content
        int n =scn.nextInt();
        ArrayList<Integer> list =new ArrayList<>();
        for(int i =0;i<n;i++)
        {
            list.add(i,scn.nextInt());
        }
        removeit(list);
        System.out.println(list);

    }
    
}
