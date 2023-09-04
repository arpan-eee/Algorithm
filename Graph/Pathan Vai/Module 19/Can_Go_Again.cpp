#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1000000000000000000;
class Edge
{
public:
    int u;
    int v;
    int w;
    Edge(int u, int v, int w)
    {
        this->u = u;
        this->v = v;
        this->w = w;
    }
};
int main()
{
    int n, e;
    cin >> n >> e;
    vector<Edge> v;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        Edge ed(a, b, w);
        v.push_back(ed);
    }
    long long int dis[n + 1];
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INF;
    }
    int s, t;
    cin >> s;
    dis[s] = 0;
    bool test = true;
    vector<int> vtest1, vtest2;
    for (int i = 1; i <= n - 1; i++)
    {
        for (auto ed : v)
        {
            int a = ed.u;
            int b = ed.v;
            int w = ed.w;
            if (dis[a] != INF)
            {
                if (dis[a] + w < dis[b])
                {
                    dis[b] = dis[a] + w;
                }
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        vtest1.push_back(dis[i]);
    }
    for (auto ed : v)
    {
        int a = ed.u;
        int b = ed.v;
        int w = ed.w;
        if (dis[a] != INF)
        {
            if (dis[a] + w < dis[b])
            {
                dis[b] = dis[a] + w;
            }
        }
    }
    for (int i = 1; i <= n; i++)
    {
        vtest2.push_back(dis[i]);
    }
    for (int i = 0; i <= n - 1; i++)
    {
        if (vtest1[i] != vtest2[i])
        {
            test = false;
        }
    }
    if (test)
    {
        cin >> t;
        for (int i = 1; i <= t; i++)
        {
            int tc;
            cin >> tc;
            cout << ((dis[tc] == INF) ? "Not Possible" : to_string(dis[tc])) << endl;
        }
    }
    else
    {
        cout << "Negative Cycle Detected" << endl;
    }
    return 0;
}