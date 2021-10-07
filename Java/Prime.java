
import java.util.*;


public class Prime{

public static void main (String Argus[])
{

boolean flag=true;

Scanner s1= new Scanner(System.in);
System.out.println("*********** Prime or non-Prime Number Identifier *************");
System.out.println("\nEnter Your Number");
int a = s1.nextInt();

// By Git mam Logic
for (int i=2;i<=(a-1);i++)

{
if(a%i==0){
flag=false;
break;
}
else
flag=true;

}

if(flag==false)
System.out.println("Hello Buddy, Your Number "+a+" is Non-Prime");
else
System.out.println("Hello Buddy, Your Number "+a+" is Prime");
}

}
