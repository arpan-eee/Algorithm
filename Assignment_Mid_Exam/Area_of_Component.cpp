#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 5;
string g[N];
int visited[N][N];
int n, m, c;
vector<pii> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void dfs(int i, int j)
{
    if (!isValid(i, j) || visited[i][j] || g[i][j] == '-')
        return;

    c++;
    visited[i][j] = true;

    for (auto d : direction)
    {
        dfs(i + d.first, j + d.second);
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }

    priority_queue<int, vector<int>, greater<int>> pq;

    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            c = 0;
            if (visited[i][j] || g[i][j] == '-')
                continue;
            dfs(i, j);
            pq.push(c);
        }
    }
    if (pq.empty())
        cout << "-1" << endl;
    else
        cout << pq.top() << endl;

    return 0;
}