/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   09-May-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: prims.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 09-May-2021
 */



#include <stdio.h>

#define N_VERTICES 8
#define INF 99999
#define NULL -1

class Graph
{
public:
int mat[N_VERTICES][N_VERTICES];
void init_graph()
{
        for(int i=0; i<N_VERTICES; i++)
        {
                for(int j=0; j<N_VERTICES; j++)
                {
                        mat[i][j] = 0;
                }
        }
}
void add_edge(int u, int v, int weight)
{
        mat[u][v] = weight;
        mat[v][u] = weight;
}
int extract_min(int key[], int exists[], int n) {
        int minval_index;
        for(int i=0; i<n; i++) {
                if(exists[i] == 1) {
                        minval_index = i;
                        break;
                }
        }
        for(int i=0; i<n; i++) {
                if(exists[i] == 1 && key[i] < key[minval_index]) {
                        minval_index = i;
                }
        }
        return minval_index;
}
void prims(int r) {
        int key[N_VERTICES];
        int exists[N_VERTICES];
        int p[N_VERTICES];

        for(int i=0; i<N_VERTICES; i++) {
                key[i] = INF;
                exists[i] = 1;
        }

        key[r] = 0;
        p[r] = NULL;

        for(int i=0; i<N_VERTICES; i++) {
                int u = extract_min(key, exists, N_VERTICES);
                exists[u] = 0;
                for(int v=0; v<N_VERTICES; v++) {
                        if(mat[u][v] != 0) {
                                if(exists[v] == 1 && mat[u][v] < key[v]) {
                                        p[v] = u;
                                        key[v] = mat[u][v];
                                }
                        }
                }
        }

        printf("Printing MST:\n");
        for(int i=0; i<N_VERTICES; i++) {
                printf("%3d %3d\n", i, p[i]);
        }
}
};

int main()
{

        Graph G;
        G.init_graph();
        G.add_edge(0, 1, 4);
        G.add_edge(1, 2, 9);
        G.add_edge(1, 4, 2);
        G.add_edge(3, 4, 15);
        G.add_edge(4, 5, 8);
        G.add_edge(5, 6, 3);
        G.add_edge(5, 7, 10);
        G.add_edge(6, 7, 14);
        G.add_edge(1, 7, 5);
        G.add_edge(0, 7, 6);

        for(int i=0; i<N_VERTICES; i++) {
                for(int j=0; j<N_VERTICES; j++) {
                        printf("%3d ", G.mat[i][j]);
                }
                printf("\n");
        }

        G.prims(0);

        return 0;
}
