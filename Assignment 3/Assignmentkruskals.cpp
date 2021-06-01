/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   24-May-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: Assignmentkruskals.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 31-May-2021
 */



#include "bits/stdc++.h"

using namespace std;
#define el "\n"
#define F first
#define S second
#define PI 3.14159265358979323846  /* pi */
#define FOR(i,a,b) for(int i = a; i <= b; ++i)
#define FORD(i,a,b) for(int i = a; i >= b; --i)
#define RI(i,n) FOR(i,1,n)
#define REP(i,n) FOR(i,0,(n)-1)
#define SQR(x) (x)*(x)
#define all(v)    ((v).begin()),((v).end())
#define degreesToRadians(angleDegrees) (angleDegrees * PI / 180.0) // Converts degrees to radians.
#define radiansToDegrees(angleRadians) (angleRadians * 180.0 / PI) // Converts radians to degrees.
typedef long long ll;
typedef pair<int, int>  pii;
typedef pair<ll, ll>  pll;
typedef long double ld;
typedef vector<int>   vi;
typedef vector<ll>    vll;
typedef vector<pii>   vpii;
typedef vector<pll>   vpll;
const double EPS = 1e-9;
const int N = 1e3+2, M = 3e5+5, OO = 0x3f3f3f3f;
// int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; // 4 Direction
// int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1}; // 8 Direction
// int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; // Knight Direction
// int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; // Hexagonal Direction

#define N_VERTICES 11


class DisjointSet
{
int p[N_VERTICES];

public:
void make_set(int x)
{
        p[x] = x;
}
int find_set(int x)
{
        while(x != p[x])
        {
                x = p[x];
        }
        return x;
}
void union_set(int x, int y)
{
        int a = find_set(x);
        int b = find_set(y);
        p[a] = b;
}
bool same_set(int x, int y)
{
        if(find_set(x) == find_set(y))
                return true;
        return false;
}
};

struct Edge {
        int u;
        int v;
        int weight;
};

int cmpfunc(const void * a, const void * b) {
        // return ((Edge*)a)->weight > ((Edge*)b)->weight;
        // the mistake was to use > instead of -
        return ((Edge*)a)->weight - ((Edge*)b)->weight;
}

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

int create_edge_list(Edge edgelist[]) {
        int c = 0;
        for(int i=0; i<N_VERTICES; i++) {
                for(int j=i; j<N_VERTICES; j++) {
                        if(mat[i][j] != 0) {
                                Edge e;
                                e.u = i;
                                e.v = j;
                                e.weight = mat[i][j];
                                edgelist[c] = e;
                                c++;
                        }
                }
        }
        return c;
}

void sort_edge_list(Edge edgelist[], int n) {
        qsort(edgelist, n, sizeof(Edge), cmpfunc);
}

void Kruskals() {

        DisjointSet ds;
        for(int i = 0; i < N_VERTICES; i++)
        {
                ds.make_set(i);
        }

        Edge edgelist[10000];
        int nE = create_edge_list(edgelist);
        sort_edge_list(edgelist, nE);

        for(int i = 0; i < N_VERTICES; i++)
        {
                if(ds.find_set(edgelist[i].u) != ds.find_set(edgelist[i].v))
                {
                        std::cout << edgelist[i].u << " " << edgelist[i].v << '\n';
                        ds.union_set(edgelist[i].u, edgelist[i].v);
                }
        }
}
};


