import java.util.Scanner;

class Main{
  static int binary_search(int A[], int left, int right, int key) 
  {
    int m;
    while( left <= right )     
    {
      m = left + (right-left)/2;
      if( A[m] == key )     // Element found
        return m;
      if( A[m] < key )         // Search in right part of list
        left = m + 1;
      else            // Search in left part of list
        right = m - 1;
    }
    return -1;
  }

  public static void main(String[] args)
  {
    int loc, x, array[]={10,11,12,13,14,25,26,37,48,59};
    x = 26;        // element to be searched in the array
    loc=binary_search(array,0,10,x);
    if(loc != -1)
      System.out.print("Element found at location : " + loc);
    else
      System.out.print("Element not present in the array.");

  }
}
