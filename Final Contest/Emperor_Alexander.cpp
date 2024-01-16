#include <bits/stdc++.h>
using namespace std;
int c=0;

typedef pair<int, int> pii;
const int N = 1e5 + 5;
vector<pii> v[N];
vector<pii> v2;
vector<pii> v3;
vector<int> dis(N, INT_MAX);
bool vis0[N];
bool vis[N];

int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        vis[a]=true;
        vis[b]=true;

        priority_queue<pii, vector<pii>> pq;

        pq.push({w,make_pair(a, w)});

        auto it = find(v[b].begin(), v[b].end(), make_pair(a, w));
        if (it != v[b].end())
        {
            if (w < it->second)
            {
                v[b].erase(it);
            }
        }
        it = find(v[a].begin(), v[a].end(), make_pair(b, w));
        if (it != v[a].end())
        {
            if (w < it->second)
            {
                v[a].erase(it);
            }
        }
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    dijkstra(1);
    cout<<v2.size()-v3.size()<<' ';
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
    return 0;
}