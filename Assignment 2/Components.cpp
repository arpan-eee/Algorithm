#include <bits/stdc++.h>
using namespace std;

const int N = 1e3 + 5;
vector<int> adj[N];
bool visited[N];
int cmp[N];
vector<int> v;

int dfs(int u)
{
    int x = 1;
    visited[u] = true;
    for (int v : adj[u])
    {
        if (visited[v])
        {
            continue;
        }
        x += dfs(v);
    }
    return x;
}

int main()
{
    int n, m;
    cin >> n >> m;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    for (int i = 0; i <= 1e3; i++)
    {
        if (!adj[i].empty())
        {
            if (visited[i])
            {
                continue;
            }
            cmp[i] = dfs(i);
        }
    }

    for (int i = 0; i <= 1e3; i++)
    {
        if (cmp[i] > 1)
        {
            v.push_back(cmp[i]);
        }
    }

    sort(v.begin(), v.end());

    for (auto it = v.begin(); it != v.end(); it++)
    {
        cout << *it << " ";
    }

    return 0;
}