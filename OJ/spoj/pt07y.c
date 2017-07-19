#include <stdio.h>
#include <stdlib.h>

/* PT07Y: IS IT A TREE? */

int visited[10010];
int n, m;
int has_edge[10010][10010];

void dfs(int v) {
    visited[v] = 1;
    int i;
    for (i = 0; i < n; ++i) {
        if (has_edge[v][i] && !visited[i]) {
            dfs(i);
        }
    }
}

void solve() {
    scanf("%d %d ", &n, &m);
    int i, u, v;
    for (i = 0; i < m; ++i) {
        scanf("%d %d ", &u, &v);
        has_edge[u-1][v-1] = 1;
    }
    if (n - m != 1) {
        printf("NO\n");
        return;
    }
    dfs(0);
    for (i = 0; i < n; ++i) {
        if (!visited[i]) {
            printf("NO\n");
            return;
        }
    }
    printf("YES\n");
}

int main() {
    solve();
    return 0;
}