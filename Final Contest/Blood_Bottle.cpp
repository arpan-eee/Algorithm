#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        string a;
        queue<char> st;
        cin >> a;
        for (int i = a.size() - 1; i >= 0; i--)
        {
            st.push(a[i]);
        }
        char cp = '2';
        int z = 0, k = 0;
        bool zb = false, kb = false;
        while (!st.empty())
        {
            char cn = st.front();
            st.pop();

            if (cp == '2')
            {
                if (cn == '1')
                {
                    zb = true;
                    z++;
                    cp = cn;
                }
            }
            else
            {
                if (cp == '0' && cn == '1')
                {
                    if (zb)
                    {
                        zb = false;
                        kb = true;
                        k++;
                    }
                    else
                    {
                        kb = false;
                        zb = true;
                        z++;
                    }
                }
                else if (cn == '1' && cp == '1')
                {

                    if (zb)
                    {
                        z++;
                    }
                    else
                    {
                        k++;
                    }
                }
                cp = cn;
            }
        }
        cout << z << endl;
    }
    return 0;
}