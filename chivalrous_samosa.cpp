#include <iostream>
using namespace std;

int count(string a, string b)
{
    int m = a.length();
    int n = b.length();

    int dp[m + 1][n + 1] = { { 0 } };

    for (int i = 0; i <= n; ++i)
        dp[0][i] = 0;

    for (int i = 0; i <= m; ++i)
        dp[i][0] = 1;

    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            if (a[i - 1] == b[j - 1])
                dp[i][j] = dp[i - 1][j - 1] +
                            dp[i - 1][j];
                
            else
                dp[i][j] = dp[i - 1][j];
        }
    }

    return dp[m][n];
}

// Driver code
int main()
{
    string old;
    string nw;
    
    cin>>nw>>old;

    cout << count(old, nw);

    return 0;
}
