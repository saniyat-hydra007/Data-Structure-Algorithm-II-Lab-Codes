/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   28-Mar-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: CoinChange.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 04-Apr-2021
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


int cmpfunc (const void * a, const void * b) {
        return ( *(int*)b - *(int*)a );
}

int main () {
        int coins[] = { 1, 5, 10, 25, 100 };
        qsort(coins, 5, sizeof(int), cmpfunc);


        int m;
        std::cout << "Enter The Ammount: ";
        std::cin >> m;
        std::cout << endl;
        int i = 0;

        while(m>0) {
                int c = coins[i];
                int req_num_coin = m/c;
                if (req_num_coin >0) {
                        std::cout << "Take coin " << coins[i] << " for " << req_num_coin << " times" << '\n';
                }
                i++;
                m = m%c;
        }

        return 0;
}
