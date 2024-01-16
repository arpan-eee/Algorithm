#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, ns;
        cin >> n >> ns;
        int a[n];
        for (int i = 0; i < n; i++)
        {
            cin >> a[i];
        }
        int s = 1000 - ns;
        int dp[n + 1][s + 1];
        dp[0][0] = 0;
        for (int i = 1; i <= s; i++)
            dp[0][i] = INT_MAX - 1;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = min(1 + dp[i][j - a[i - 1]], dp[i - 1][j]);
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        if (dp[n][s] == INT_MAX - 1)
            cout << "-1" << endl;
        else
            cout << dp[n][s] << endl;
    }
    return 0;
}