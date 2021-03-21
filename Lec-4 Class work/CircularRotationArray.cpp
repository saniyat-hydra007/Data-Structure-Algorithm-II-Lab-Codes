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

int RotationArray(int a[],int n)
{
        int l = 0;
        int h = n - 1;
        int index = -1;

        while (l <= h)
        {
                int mid = (l + h) / 2;

                int next = (mid + 1) % n;
                int prev = (mid - 1 + n) % n;

                if(a[l] <= a[h]) {
                        index = l;
                        break;
                }

                else if (a[mid] < a[next] && a[mid] < a[prev]) {
                        index = mid;
                        break;
                }

                else if (a[mid] <= a[h]) {
                        h = mid - 1;
                }

                else if (a[mid] >= a[l]) {
                        l = mid + 1;
                }
        }

        return index;
}

int main(void)
{
        int arr[] = {3,4,5,6,2};
        std::cout << "Rotation is: " << RotationArray(arr,5) << '\n';
        return 0;
}
