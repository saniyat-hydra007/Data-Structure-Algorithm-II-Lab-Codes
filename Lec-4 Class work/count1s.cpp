/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   21-Mar-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 21-Mar-2021
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

int count1s(int a[], int low, int high)
{
        int n = high - low + 1;
        int mid = low + (high - low)/2;

        if (a[high] == 0) {
                return 0;
        }
        else if (a[low] == 1) {
                return n;
        }
        else{
                return count1s(a, low, mid) + count1s(a, mid+1, high);
        }
        return 0;
}

int main(){
        int arr[] = {0, 0, 1, 1, 1, 1, 1, 1};
        cout << count1s(arr, 0, 7);
}
