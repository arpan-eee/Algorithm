#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    cin >> n;
    if (n == 1)
    {
        cout << 1 << endl;
    }
    else if (n == 2)
    {
        cout << "12" << endl
             << "22" << endl;
    }
    else if (n > 2 && n <= 9)
    {
        for (int i = 1; i <= n; i++)
            cout << i;
        cout << endl;
        int j = 2;
        for (int i = 1; i <= n - 2; i++)
        {
            cout << j;
            for (int i = 1; i <= n - 2; i++)
            {
                cout << ' ';
            }
            cout << n << endl;
            j++;
        }
        for (int i = 1; i <= n; i++)
            cout << n;
    }
    return 0;
}