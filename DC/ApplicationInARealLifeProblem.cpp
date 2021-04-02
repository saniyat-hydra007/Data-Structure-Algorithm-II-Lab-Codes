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


struct result {
        int start;
        int end;
        int sum;
};

struct result max_crossing_subarray(int A[], int low, int mid, int high) {
        int left_sum = -1000000000;
        int sum = 0;

        int max_left;
        for (int i = mid; i >= low; i--) {
                sum = sum + A[i];
                if (sum > left_sum) {
                        left_sum = sum;
                        max_left = i;
                }
        }

        int right_sum = -1000000000;
        sum = 0;

        int max_right;
        for (int j = mid + 1; j <= high; j++) {
                sum = sum + A[j];
                if (sum > right_sum) {
                        right_sum = sum;
                        max_right = j;
                }
        }

        struct result X = {max_left, max_right, left_sum + right_sum};
        return X;
}

struct result max_subarray(int A[], int low, int high) {
        if(low == high) {
                struct result X = {low, high, A[low]};
                return X;
        }
        else {
                int mid=(low+high)/2;

                struct result x = max_subarray(A,low,mid);

                struct result y = max_subarray(A,mid+1,high);

                struct result z = max_crossing_subarray(A,low,mid,high);

                if((x.sum >= y.sum) && (x.sum>=z.sum)) {
                        struct result X = {x.start, x.end, x.sum};
                        return X;
                }
                else if((y.sum>=x.sum) && (y.sum>=z.sum)) {
                        struct result X = {y.start, y.end, y.sum};
                        return X;
                }
                else{
                        struct result X = {z.start, z.end, z.sum};
                        return X;
                }
        }
}

int main() {
        int price[] = {1,-4,3,-4};
        int change[]={100};
        change[0]= -1000000000;

        int n = sizeof(price)/sizeof(price[0]);

        for(int i=1; i<=n; i++) {
                change[i] = price[i]-price[i-1];
        }

        for(int i=0; i<=n; i++) {
                std::cout << i << " " << change[i] << '\n';
        }

        struct result X = max_subarray(change, 0, n-1);

        std::cout << "Max sum subarray " << X.start << " to " << X.end << " Sum = " << X.sum << '\n';

        return 0;
}
