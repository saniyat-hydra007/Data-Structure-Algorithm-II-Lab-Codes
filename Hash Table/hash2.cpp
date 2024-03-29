/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   06-Jun-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: hash2.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 06-Jun-2021
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



#define M 100

class Object {
public:
char key[100];
int value;

Object() {

}
Object(const char k[], int v) {
        strcpy(key, k);
        value = v;
}
};

class HashTable {
Object Table[M];
bool taken[M];
public:
HashTable() {
        for(int i=0; i<M; i++) {
                taken[i] = false;
        }
}

int h_aux(const char k[]) {
        int sum=0;
        int len = strlen(k);
        for(int i=0; i<len; i++) {
                sum = sum + k[i];
        }
        return sum%M;
}

int h(const char k[], int i) {
        return (h_aux(k) + i)%M;
}

int insert(const char k[], int v) {
        int i=0;
        while(i != M) {
                int j = h(k, i);
                if(taken[j] == false) {
                        Object o(k, v);
                        Table[j] = o;
                        taken[j] = true;
                        return j;
                }
                i++;
        }
        printf("Hashtable overflow\n");
        return -1;
}

int search(const char k[]) {
        int i=0;
        while(i != M ) {
                int j = h(k, i);
                if(taken[j] == false) {
                        return -1;
                }
                if(taken[j] == true && strcmp(Table[j].key, k) == 0) {
                        return Table[j].value;
                }
                i++;
        }
        return -1;
}
};

int main() {

        HashTable T;

        T.insert("a", 1);
        T.insert("b", 5);
        T.insert("c", 189);

        printf("%d\n", T.search("a"));
        printf("%d\n", T.search("b"));
        printf("%d\n", T.search("c"));

        return 0;
}
