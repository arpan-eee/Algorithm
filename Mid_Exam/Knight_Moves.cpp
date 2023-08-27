#include <bits/stdc++.h>
using namespace std;

typedef pair<int, int> pii;

const int N = 1e2 + 5;
int visited[N][N];
int level[N][N];
vector<pii> direction = {{2, -1}, {2, 1}, {1, 2}, {-1, 2}, {-2, 1}, {-2, -1}, {-1, -2}, {1, -2}};

void bfs(int si, int sj, int mi, int mj)
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

            if (!visited[ni][nj] && (ni >= 0 && ni < mi && nj >= 0 && nj < mj))
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
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, ki, kj, qi, qj;
        cin >> n >> m >> ki >> kj >> qi >> qj;

        bfs(ki, kj, n, m);

        if (ki == qi && kj == qj)
            cout << 0 << endl;
        else if (level[qi][qj] == 0)
            cout << -1 << endl;
        else
            cout << level[qi][qj] << endl;

        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                visited[i][j] = false;
                level[i][j] = 0;
            }
        }
    }

    return 0;
}