#include <bits/stdc++.h>
using namespace std;
typedef pair<int, int> pii;
int main()
{
    int n;
    cin >> n;
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    while (n--)
    {
        int a, b;
        cin >> a >> b;
        pq.push({a, b});
    }
    while (!pq.empty())
    {
        pii s = pq.top();
        pq.pop();
        cout << s.first << ' ' << s.second << endl;
    }

    return 0;
}