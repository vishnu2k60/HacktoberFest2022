#include <iostream>
using namespace std;

int main(){
    int a,b,c;
    cin>>a;
    cin>>b;
    cin>>c;
    if (a>b)
    {
        if (a>c)
        {
            cout<<"Max no: ";
            cout<<a;
        }
        else
        {
            cout<<"Max no: ";
            cout<<c;
        }
        
    }
    else{
        if (b>c)
        {
            cout<<"Max no: ";
            cout<<b;
        }
        else
        {
            cout<<"Max no: ";
            cout<<c;
        }
    }
    return 0;   
}
