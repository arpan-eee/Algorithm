#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 7;
int nums[N];

void merge(int l, int r, int m)
{
    int l_size = m - l + 1;
    int L[l_size + 1];

    int r_size = r - m;
    int R[r_size + 1];

    for (int i = l, j = 0; i <= m; i++, j++)
        L[j] = nums[i];

    for (int i = m + 1, j = 0; i <= r; i++, j++)
        R[j] = nums[i];

    L[l_size] = INT_MIN;
    R[r_size] = INT_MIN;

    int lp = 0, rp = 0;
    for (int i = l; i <= r; i++)
    {
        if (L[lp] >= R[rp])
        {
            nums[i] = L[lp];
            lp++;
        }
        else
        {
            nums[i] = R[rp];
            rp++;
        }
    }
}
void mergesort(int l, int r)
{
    if (l == r)
        return;
    int m = (l + r) / 2;
    mergesort(l, m);
    mergesort(m + 1, r);
    merge(l, r, m);
}
int main()
{
    int n;
    cin >> n;
    int i = 0;
    while (i < n)
    {
        cin >> nums[i];
        i++;
    }
    mergesort(0, n - 1);
    i = 0;
    while (i < n)
    {
        cout << nums[i] << ' ';
        i++;
    }
    return 0;
}