#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 7;
int nums[N];
int f = 0;
int b_search(int l, int r, int t)
{
    if (l <= r)
    {
        int m = (l + r) / 2;
        if (nums[m] == t)
            f++;
        if (nums[m] <= t)
            b_search(m + 1, r, t);
        else if (nums[m] >= t)
            b_search(l, m - 1, t);
    }
    else
        return f;
}
int main()
{
    int n, i = 0;
    cin >> n;
    while (i < n)
    {
        cin >> nums[i];
        i++;
    }
    int test;
    cin >> test;

    if (b_search(0, n - 1, test) > 1)
        cout << "YES";
    else
        cout << "NO";
    return 0;
}