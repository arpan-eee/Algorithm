#include <bits/stdc++.h>
const int N = 1e9 + 7;
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
        dp[0][0] = 1;
        for (int i = 1; i <= s; i++)
            dp[0][i] = 0;
        for (int i = 1; i <= n; i++)
        {
            for (int j = 0; j <= s; j++)
            {
                if (a[i - 1] <= j)
                {
                    dp[i][j] = ((dp[i][j - a[i - 1]] % N) + dp[i - 1][j] % N) % N;
                }
                else
                {
                    dp[i][j] = dp[i - 1][j];
                }
            }
        }
        cout << dp[n][s] % N << endl;
    }
    return 0;
}