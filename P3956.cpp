#include <bits/stdc++.h>
using namespace std;

const int maxn = 105;

int G[maxn][maxn];
int dp[maxn][maxn];
bool ismagic[maxn][maxn];

int nx[] = {1, -1, 0, 0}, ny[] = {0, 0, 1, -1};

void dfs(int x, int y, int cost, int n) {
    if (x == n and y == n)
        return;
    int res = INT_MAX;
    for (int i = 0; i < 4; i++) {
        int newx = x + nx[i], newy = y + ny[i];
        if (newx < 1 or newx > n or newy < 1 or newy > n)
            continue;
        if (G[newx][newy] >= 0) {
            int newcost = cost;
            if (G[newx][newy] != G[x][y])
                newcost += 1;
            if (newcost < dp[newx][newy]) {
                dp[newx][newy] = newcost;
                dfs(newx, newy, newcost, n);
            }
        } else if (!ismagic[x][y] && cost + 2 < dp[newx][newy]) {
            dp[newx][newy] = cost + 2;
            ismagic[newx][newy] = true;
            G[newx][newy] = G[x][y];
            dfs(newx, newy, cost + 2, n);
            ismagic[newx][newy] = false;
            G[newx][newy] = -1;
        }
    }
}

int main() {
    fill(G[0], G[0] + maxn * maxn, INT_MAX);
    dp[1][1] = 0;
    memset(G, -1, sizeof(G));
    memset(ismagic, false, sizeof(ismagic));
    int n, m, x, y, c;
    cin >> n >> m;
    while (m--) {
        cin >> x >> y >> c;
        G[x][y] = c;
    }
    dfs(1, 1, 0, n);
    cout << (dp[n][n] == INT_MAX ? -1 : dp[n][n]) << endl;
}