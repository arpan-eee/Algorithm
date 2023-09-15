#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e3 + 5;
string g[N];
int visited[N][N];
int level[N][N];
int n, m;
vector<pii> direction = {{0, -1}, {0, 1}, {-1, 0}, {1, 0}};

bool isValid(int i, int j)
{
    return (i >= 0 && i < n && j >= 0 && j < m);
}

void bfs(int si, int sj)
{
    queue<pii> q;
    q.push({si, sj});
    visited[si][sj] = true;
    level[si][sj] = 0;

    while (!q.empty())
    {
        pii upair = q.front();
        int i = upair.first;
        int j = upair.second;
        q.pop();

        for (auto d : direction)
        {
            int ni = i + d.first;
            int nj = j + d.second;

            if (isValid(ni, nj) && !visited[ni][nj] && g[ni][nj] != '-')
            {
                q.push({ni, nj});
                visited[ni][nj] = true;
                level[ni][nj] = level[i][j] + 1;
            }
        }
    }
}

int main()
{
    cin >> n >> m;
    for (int i = 0; i < n; i++)
    {
        cin >> g[i];
    }
    int si, sj, di, dj;
    cin >> si >> sj >> di >> dj;
    bfs(si, sj);
    if (!visited[di][dj])
        cout << "NO" << endl;
    else
        cout << "YES" << endl;

    return 0;
}