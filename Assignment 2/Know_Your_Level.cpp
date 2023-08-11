#include <bits/stdc++.h>
using namespace std;

const int N = 1e5 + 1;
vector<int> adj[N];
bool visited[N];
int level[N];
vector<int> v;

int bfs(int s)
{
    queue<int> q;
    q.push(s);
    visited[s] = true;
    level[s] = 0;
    int m = 0;
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int v : adj[u])
        {
            if (visited[v] == true)
                continue;
            q.push(v);
            visited[v] = true;
            level[v] = level[u] + 1;
            m = max(m, level[v]);
        }
    }
    return m;
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

    int l;
    cin >> l;

    int mx = bfs(0);
    if (l > mx)
    {
        cout << -1;
    }
    else if (l == 0)
    {
        cout << 0;
    }
    else
    {
        for (int i = 0; i < N; i++)
        {
            if (level[i] == l)
            {
                v.push_back(i);
            }
        }
        if (v.empty())
        {
            cout << -1;
        }
        else
        {
            for (auto it = v.begin(); it != v.end(); it++)
            {
                cout << *it << " ";
            }
        }
    }

    return 0;
}