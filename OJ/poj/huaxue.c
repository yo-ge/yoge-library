#include <stdio.h>

int r, c;
int a[110][110];
int dp[110][110];
int dx[] = {-1, 0, 0, 1};
int dy[] = {0, -1, 1, 0};

int max(int a, int b) {
    return a > b ? a : b;
}

int is_valid(int x, int y) {
    return x > -1 && y > -1 && x < r && y < c;
}

int get_dp(int x, int y) {
    if (dp[x][y]) {
        return dp[x][y];
    }
    int i, res = 0;
    for (i = 0; i < 4; ++i) {
        int xx = x + dx[i], yy = y + dy[i];
        if (!is_valid(xx, yy)) {
            continue;
        }
        if (a[xx][yy] < a[x][y]) {
            res = max(res, get_dp(xx, yy));
        }
    }
    return dp[x][y] = res + 1;
}

void solve() {
    scanf("%d %d", &r, &c);
    int i, j;
    int ans = 0;
    for (i = 0; i < r; ++i) {
        for (j = 0; j < c; ++j) {
            ans = max(ans, get_dp(i, j));
        }
    }
    printf("%d\n", ans);
}

int main() {
    solve();
    return 0;
}