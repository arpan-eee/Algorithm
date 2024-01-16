#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        int arpan = 0, arnab = 0;
        cin >> n;
        vector<int> v;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            v.push_back(a);
        }
        sort(v.begin(), v.end());
        while (!v.empty())
        {
            if (arpan > arnab)
            {
                arnab = arnab + v.back();
                v.pop_back();
                if (!v.empty())
                {
                    arpan = arpan + v.back();
                    v.pop_back();
                }
            }
            else
            {
                arpan = arpan + v.back();
                v.pop_back();
                if (!v.empty())
                {
                    arnab = arnab + v.back();
                    v.pop_back();
                }
            }
        }
        cout<<abs(arpan-arnab)<<endl;
    }
    return 0;
}