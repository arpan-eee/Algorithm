#include <bits/stdc++.h>
using namespace std;
const long long int INF = 1e11 + 500;
int main()
{
    long long int n, e;
    cin >> n >> e;
    long long int dis[n + 1][n + 1];
    for (long long int i = 1; i <= n; i++)
    {
        for (long long int j = 1; j <= n; j++)
        {
            dis[i][j] = INF;
            if (i == j)
                dis[i][j] = 0;
        }
    }
    while (e--)
    {
        long long int a, b, w;
        cin >> a >> b >> w;
        if (dis[a][b] > w)
            dis[a][b] = w;
    }
    for (long long int k = 1; k <= n; k++)
    {
        for (long long int i = 1; i <= n; i++)
        {
            for (long long int j = 1; j <= n; j++)
            {
                if (dis[i][k] + dis[k][j] < dis[i][j])
                {
                    dis[i][j] = dis[i][k] + dis[k][j];
                }
            }
        }
    }
    long long int t;
    cin >> t;
    while (t--)
    {
        long long int p, q;
        cin >> p >> q;
        cout << (dis[p][q] == INF ? -1 : dis[p][q]) << endl;
    }
    return 0;
}