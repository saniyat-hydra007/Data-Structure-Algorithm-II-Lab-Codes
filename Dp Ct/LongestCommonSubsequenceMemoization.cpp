/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   18-Apr-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: LongestCommonSubsequenceMemoization.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 18-Apr-2021
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



int max(int a, int b) {
        if(a>b) return a;
        return b;
}

int table[1000][1000];

void init_table(int m, int n) {
        for (int i = 0; i < m; i++) {
                table[0][i] = 0;
        }
        for (int i = 1; i < n; i++) {
                table[i][0] = 0;
        }
        for (int i = 1; i < m; i++) {
                for (int j = 1; j < n; j++) {
                        table[i][j] = -1;
                }
        }
}

int LCS(char X[], int i, char Y[], int j) {
        if(i == 0 || j == 0) {
                return table[i-1][j-1];
        }

        if (table[i-1][j-1] != -1) {
                return table[i-1][j-1];
        }

        if(X[i-1] == Y[j-1]) {
                table[i-1][j-1] = LCS(X, i-1, Y, j-1) + 1;
                return table[i-1][j-1];
        }
        else{
                table[i-1][j-1] = max(LCS(X, i, Y, j-1), LCS(X, i-1, Y, j));
                return table[i-1][j-1];
        }
}

void print_solution(char X[], int i, char Y[], int j) {
        if(i==0 || j==0)
                return;

        if(X[i] == Y[j]) {
                print_solution(X, i-1, Y, j-1);
                printf("%c", X[i]);
        }
        else {
                if(table[i-1][j] > table[i][j-1]) {
                        print_solution(X, i-1, Y, j);
                }
                else {
                        print_solution(X, i, Y, j-1);
                }
        }
}

int main() {
        // char X[] = "~ABDE"; // we are not going to use index 0
        // char Y[] = "~ZBE"; // we are not going to use index 0

        // char X[] = "~ABDEASJDFLASJBDFLJASIUFASIDUF"; // we are not going to use index 0
        // char Y[] = "~ZBEFSIDHFAPDOIFHAOSF";     // we are not going to use index 0

        char X[] = "~ABCBDAB"; // we are not going to use index 0
        char Y[] = "~BDCABA"; // we are not going to use index 0

        int m = sizeof(X)/sizeof(char)-2; // excluding '~' and '\0'
        int n = sizeof(Y)/sizeof(char)-2; // excluding '~' and '\0'

        init_table(m, n);
        printf("%d", LCS(X, m, Y, n)+1);
        std::cout << '\n';
        print_solution(X,m,Y,n);
        return 0;
}
