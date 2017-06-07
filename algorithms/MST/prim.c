#include <stdio.h>
#include <stdlib.h>

enum {
    INF                    = 98765432,  /* Shouldn't be too big, otherwise may cause overflow. */
    MAX_NUMBER_OF_VERTICES = 1000,
    MAX_NUMBER_OF_EDGES    = 1000,
};

int n_vertices, n_edges;
int edge_ids[MAX_NUMBER_OF_VERTICES][MAX_NUMBER_OF_VERTICES];
int weights[MAX_NUMBER_OF_VERTICES][MAX_NUMBER_OF_VERTICES];
int visited[MAX_NUMBER_OF_VERTICES];
int in_mst[MAX_NUMBER_OF_EDGES];
int mst_size = 0;

/* Inputs the distance of two connected vertices. */
void init_graph() {
    scanf("%d %d ", &n_vertices, &n_edges);
    int i, j;
    for (i = 0; i < n_vertices; ++i) {
        visited[i] = 0;
        for (j = 0; j < n_vertices; ++j) {
            weights[i][j] = weights[j][i] = i == j ? 0 : INF;
        }
    }
    for (i = 0; i < n_edges; ++i) {
        int id, v1, v2, weight;
        scanf("%d %d %d %d ", &id, &v1, &v2, &weight);
        edge_ids[v1][v2] = edge_ids[v2][v1] = id;
        weights[v1][v2] = weights[v2][v1] = weight;
    }
}

/* 
 * Returns the overall weight of MST using Prim's algorithm;
 * -1 if not connected. Starts from the root vertex.
 */
int prim_mst(int root) {
    int overall_weight = 0;
    int n_remain_nodes = n_vertices - 1;
    visited[root] = 1;
    int i, j;
    while (n_remain_nodes--) {
        int min_weight_to_add = INF, st = -1, en = -1;
        for (i = 0; i < n_vertices; ++i) {
            if (visited[i]) {   /* Starts from one end of the visited edges. */
                for (j = 0; j < n_vertices; ++j) {
                    if (!visited[j] && weights[i][j] < min_weight_to_add) {
                        /* Updates the min edge to add. */
                        min_weight_to_add = weights[i][j];
                        st = i;
                        en = j;
                    }
                }
            }
        }
        if (min_weight_to_add == INF) { /* The graph is not connected. */
            return -1;
        }
        overall_weight += min_weight_to_add;
        in_mst[mst_size++] = edge_ids[st][en];
        visited[en] = 1;
    }
    return overall_weight;
}

int int_cmp(const void *p1, const void *p2) {
    return *((const int *) p1) - *((const int *) p2);
}

int main() {
    init_graph();
    int overall_weight = prim_mst(0);
    printf("%d\n", overall_weight);
    qsort(in_mst, mst_size, sizeof in_mst[0], &int_cmp);
    int i;
    for (i = 0; i < mst_size; ++i) {
        printf("%d%s", in_mst[i], i == mst_size - 1? "\n" : " ");
    }
    return 0;
}
