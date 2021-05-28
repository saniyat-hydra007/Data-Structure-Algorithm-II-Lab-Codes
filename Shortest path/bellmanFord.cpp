/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   23-May-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: bellmanFord.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 23-May-2021
 */

#include "bits/stdc++.h"
using namespace std;
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
}

void relax(int u, int v, int d[], int p[]) {

        if(d[v] > d[u] + mat[u][v])
        {
                d[v] = d[u] + mat[u][v];
                p[v] = u;
        }

}

void print_shortest_path_tree(int p[], int d[]) {
        std::cout <<"\n" << "Shortest path" << '\n';

        for(int i = 0; i < N_VERTICES; i++) {
                std::cout << i << " " << d[i] << " " << p[i] << '\n';
        }

}
void Bellmanford(int source) {
        int d[N_VERTICES];
        int p[N_VERTICES];

        for(int i = 0; i < N_VERTICES; i++) {
                d[i] = INF;
                p[i] = NULL;
        }
        d[source]=0;

        for(int i = 1; i < N_VERTICES-1; i++) {
                for(int u = 0; u < N_VERTICES; u++) {
                        for(int v = 0; v < N_VERTICES; v++) {
                                if (mat[u][v] != 0) {
                                        relax(u, v, d, p);
                                }
                        }
                }
        }

        for(int u = 0; u < N_VERTICES-1; u++) {
                for(int v = 0; v < N_VERTICES; v++) {
                        if (mat[u][v] != 0 && d[v] > d[u] + mat[u][v]) {
                                return;
                        }
                }
        }
        print_shortest_path_tree(d, p);
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

        G.Bellmanford(0);



        return 0;
}
