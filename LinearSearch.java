import java.util.*;
public class lsearch {
  static void linear(int a[],int n){
    int f=0,c=1;
    for(int i=0;i<n;i++){
      if(a[i]==n){
        f=1;
        break;
     }
    c++;
   }
   if(f==1)
     System.out.println("Element found at "+c);
   else
     System.out.println("Element not found");
 }
 public static void main(String args[]){
   Scanner sc=new Scanner(System.in);
   System.out.println("Enter the no. of elements:");
   int n=sc.nextInt();
   int a[]=new int[n];
   System.out.println("Enter the array elements:");
   for(int i=0;i<n;i++){
     a[i]=sc.nextInt();
   }
   System.out.println("Enter the number to be searched:");
   int num=sc.nextInt();
   linear(a,num);
  }
}
   
 


