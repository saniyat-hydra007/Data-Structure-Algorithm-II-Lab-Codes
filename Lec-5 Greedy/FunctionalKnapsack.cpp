/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   28-Mar-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: FunctionalKnapsack.cpp
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
// int dx[] = {1,-1,0,0} , dy[] = {0,0,1,-1}; // 4 Direction
// int dx[] = {1,-1,0,0,1,1,-1,-1}, dy[] = {0,0,1,-1,1,-1,1,-1}; // 8 Direction
// int dx[] = {1,-1,1,-1,2,2,-2,-2} , dy[] = {2,2,-2,-2,1,-1,1,-1}; // Knight Direction
// int dx[] = {2,-2,1,1,-1,-1} , dy[] = {0,0,1,-1,1,-1}; // Hexagonal Direction



typedef struct Item {
        float value;
        float weight;
} Item;

int cmpfunc(const void * a, const void * b) {
        return ( ((Item*)b)->value / ((Item*)b)->weight -((Item*)a)->value / ((Item*)a)->weight );
}

int main() {
        Item items[] = {{30,5}, {20,10}, {100, 20},{90,30},{160,40}};

        // for(int i=0; i<3; i++) {
        //         std::cout << items[i].value << " " << items[i].weight << '\n';
        // }

        qsort(items, 5, sizeof(Item), cmpfunc);

        // std::cout << '\n';
        // for(int i=0; i<3; i++) {
        //         std::cout << items[i].value << " " << items[i].weight << '\n';
        // }

        float w =60;
        int i = 0;
        float profit = 0;
        while (w>0 && i<3) {
                Item p = items[i];
                float x;
                if(w > p.weight) {
                        x= 1;
                        profit = profit + x*p.value;
                        printf("Take %.2f %.2f %.2f\%\n",p.value,p.weight,x*100);
                }
                else{
                        x = w/p.weight;
                        profit = profit + x*p.value;
                        printf("Take %.2f %.2f %.2f\%\n",p.value,p.weight,x*100);
                }
                i++;
                w = w - x*p.weight;
        }
        std::cout << "Total profit: " << profit << '\n';
        return 0;
}
