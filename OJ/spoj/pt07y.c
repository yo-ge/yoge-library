#include <stdio.h>
#include <stdlib.h>

int visited[10010];
int n, m;
int connected[10010][10010];

void dfs(int v) {

}

void solve() {
    scanf("%d %d ", &n, &m);
    int i, u, v;
    for (i = 0; i < m; ++i) {
        scanf("%d %d ", &u, &v);
        connected[u][v] = 1;
    }
    dfs(0);
    for (i = 0; i < n; ++i) {
        if (!visited[i]) {
            
        }
    }
}

int main() {
    solve();
    return 0;
}