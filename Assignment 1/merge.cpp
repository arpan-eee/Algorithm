#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    int num1[n + 1];
    for (int i = 0; i < n; i++)
    {
        cin >> num1[i];
    }
    num1[n] = INT_MIN;

    int m;
    cin >> m;
    int num2[m + 1];
    for (int i = 0; i < m; i++)
    {
        cin >> num2[i];
    }
    num2[m] = INT_MIN;

    int num[m + n];
    int n1 = 0, n2 = 0;

    for (int i = 0; i < (m + n); i++)
    {
        if (num1[n1] <= num2[n2])
        {
            num[i] = num2[n2];
            n2++;
        }
        else
        {
            num[i] = num1[n1];
            n1++;
        }
    }

    for (int i = 0; i < (m + n); i++)
    {
        cout << num[i] << ' ';
    }

    return 0;
}