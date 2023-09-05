#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;
const int N = 1e5 + 5;
vector<pii> v[N];
vector<int> dis(N, INT_MAX);
bool vis[N];

void dijkstra(int s)
{
    priority_queue<pii, vector<pii>, greater<pii>> pq;

    pq.push({0, s});
    dis[s] = 0;
    while (!pq.empty())
    {
        pii parent = pq.top();
        pq.pop();
        int parentNode = parent.second;
        if (vis[parentNode])
            continue;
        vis[parentNode] = true;
        int parentCost = parent.first;
        for (auto child : v[parentNode])
        {
            int childNode = child.first;
            int childCost = child.second;
            if (parentCost + childCost < dis[childNode])
            {
                dis[childNode] = parentCost + childCost;
                pq.push({dis[childNode], childNode});
            }
        }
    }
}
int main()
{
    int n, e;
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        v[a].push_back({b, w});
        v[b].push_back({a, w});
    }
    for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    dijkstra(1);
    for (int i = 1; i <= n; i++)
    {
        cout << "Node " << i << ": " << dis[i] << endl;
    }
    return 0;
}