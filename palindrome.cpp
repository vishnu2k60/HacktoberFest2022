#include <iostream>
using namespace std;

int main()
{
     int temp, num, digit, rev = 0;

     cout << "Enter a positive number: ";
     cin >> num;

     temp = num;

     do
     {
         digit = num % 10;
         rev = (rev * 10) + digit;
         num = num / 10;
     } while (num != 0);

     cout << " The reverse of the number is: " << rev << endl;

     if (temp == rev)
         cout << " The number is a palindrome.";
     else
         cout << " The number is not a palindrome.";

    return 0;
}
