/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   11-Apr-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: FIbNumber.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 11-Apr-2021
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

long long f[10000];
void init_table(){
        for (int i = 0; i < 10000; i++) {
                f[i] = -1;
        }
        f[0] = 0;
        f[1] = 1;
}

long long fib(long long n){
        if (n == 0 || n == 1) {
                return f[n];
        }
        if (f[n-1] == -1) {
                f[n-1] = fib(n-1);
        }
        if (f[n-2] == -1) {
                f[n-2] = fib(n-2);
        }
        return f[n-1] + f[n-2];
}

int main(){
        init_table();
        std::cout << fib(100) << '\n';
        return 0;
}
