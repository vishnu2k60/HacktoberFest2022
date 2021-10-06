import java.util.Scanner;

class Main{
  static int linear_search(int arr[], int n, int x) 
  {
    int i;
    for (i=0; i<n; i++)
      if (arr[i] == x)    // Check each element of the array.
        return i;        // if found return the position
    return -1;    // otherwise return -1
  }
  public static void main(String[] args)
  {
    int loc,x,array[]={10,11,12,13,14,25,26,37,48,29};

    x=25;    // Searched Element.

    loc=linear_search(array, 10, x);    // Call the search function

    if(loc != -1)
      System.out.print("Element found at location : " + loc);
    else
      System.out.print("Element not present in the array.");
  }
}
