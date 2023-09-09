#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
int a[N];
void dp(int n)
{
    if (n >= N || a[n] != -1)
    {
        return;
    }
    a[n] = 1;
    dp(n + 3);
    dp(n * 2);
}
int main()
{
    int t;
    cin >> t;
    for (int i = 0; i < N; i++)
    {
        a[i] = -1;
    }
    dp(1);
    while (t--)
    {
        int n;
        cin >> n;
        if (n == 1)
            cout << "YES" << endl;
        else if (a[n] == 1)
        {
            cout << "YES" << endl;
        }
        else
            cout << "NO" << endl;
    }
    return 0;
}