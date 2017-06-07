#include <stdio.h>
#include <stdlib.h>

enum {
    INF = 987654321,  /* Shouldn't be too big, otherwise may cause overflow. */
    MAX_NUMBER_OF_NODES = 10000,
    VIRTUAL_ROOT = -1,
};

int n_nodes;
int path_to[MAX_NUMBER_OF_NODES];
int visited[MAX_NUMBER_OF_NODES];
int dist[MAX_NUMBER_OF_NODES][MAX_NUMBER_OF_NODES];

/* Inputs the distance of two connected vertices. */
void input() {
    n_nodes = 100;
}

void init_graph() {
    int i, j;
    for (i = 0; i < n_nodes; ++i) {
        visited[i] = 0;
        for (j = i; j < n_nodes; ++j) {
            dist[i][j] = dist[j][i] = i == j ? 0 : INF;
        }
    }
}

void dijkstra_shortest_path(int root) {
    int i, j;
    for (i = 0; i < n_nodes; ++i) {
        path_to[i] = root;
    }
    path_to[root] = VIRTUAL_ROOT;
    int visiting = root;
    for (i = 1; i < n_nodes; ++i) {
        for (j = 0; j < n_nodes; ++j) {
            if (!visited[j] && 
                dist[root][visiting] + dist[visiting][j] < dist[root][j]) {
                dist[root][j] = dist[root][visiting] + dist[visiting][j];
                path_to[j] = visiting;
            }
        }
        int nearest = -1, min_distance = INF;
        for (j = 0; j < n_nodes; ++j) {
            if (!visited[j] && dist[root][j] < min_distance) {
                nearest = j;
                min_distance = dist[root][j];
            }
        }
        visiting = nearest;
        visited[visiting] = 1;
    }
}

/* Tests. */
int main() {
    init_graph();
    int root = 0;
    dijkstra_shortest_path(root);
    /* Prints the result. */
    int i;
    for (i = 0; i < n_nodes; ++i) {
        printf("Distance between %d and %d: %d\n", root, i, dist[root][i]);
    }
}