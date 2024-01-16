#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
const int N = 1e9 + 5;
int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n;
        priority_queue<pii, vector<pii>> pq;
        cin >> n;
        for (int i = 0; i < n; i++)
        {
            int a;
            cin >> a;
            pq.push({a, i});
        }
        pii p, q;
        p = pq.top();
        pq.pop();
        q = pq.top();
        if (p.second > q.second)
            cout << q.second << ' ' << p.second;
        else
            cout << p.second << ' ' << q.second;
        cout << endl;
    }
    return 0;
}