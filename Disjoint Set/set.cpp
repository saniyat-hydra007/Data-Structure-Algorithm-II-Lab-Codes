/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   02-May-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: set.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 02-May-2021
 */
#include "bits/stdc++.h"

using namespace std;
#define N_VERTICES 10
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

class DisjointSet {

int p[N_VERTICES];
public:
void make_set(int x) {
        p[x] = x;
}

int find_set(int x) {
        while (x != p[x]) {
                x = p[x];
        }
        return x;
}

void uinion_set(int x, int y) {
        int a = find_set(x);
        int b = find_set(y);
        p[a] = b;
}

bool same_set(int x,int y){
        if (find_set(x) == find_set(y))
                return true;
        return false;
}

};


int main(){
        DisjointSet ds;
        for (int i = 0; i < N_VERTICES; i++) {
                ds.make_set(i);
        }

        ds.uinion_set(0,5);
        ds.uinion_set(1,0);
        ds.uinion_set(3,7);
        ds.uinion_set(7,2);
        ds.uinion_set(0,7);

        int a,b;
        std::cin >> a;
        std::cin >> b;
        if(ds.same_set(a,b) == true) {
                printf("%d and %d in same set\n",a,b);
        }
        else{
                printf("%d and %d in different set\n",a,b);
        }

        return 0;
}
