/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   04-Apr-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Filename: JobSequence.cpp
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 02-May-2021
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


typedef struct Item
{
        int id;
        int dead;
        int profit;
}Item;

bool cmpfunc(Item a, Item b)
{
        return (a.profit > b.profit);
}

int JobSelection(Item arr[], int n)
{
        sort(arr, arr+n, cmpfunc);

        int total=0;
        Item slot[n];

        for (int i=0; i<n; i++)
                slot[i].id = -1;

        for (int i=0; i<n; i++)
        {
                for (int j=min(n, arr[i].dead)-1; j>=0; j--)
                {
                        if (slot[j].id ==-1)
                        {
                                slot[j].id = arr[i].id;
                                slot[j].dead = j;
                                slot[j].profit = arr[i].profit;
                                total += arr[i].profit;
                                break;
                        }
                }
        }

        for (int i=0; i<n; i++) {
                if (slot[i].id != -1)
                        cout << arr[i].id << " " << arr[i].dead << " " << arr[i].profit << "\n";
        }
        std::cout << "profit: " <<total << '\n';
}

int main()
{
        Item arr[] = { {1, 9, 15},
                {2, 2, 2},
                {3, 5, 18},
                {4, 7, 1},
                {5, 4, 25},
                {6, 2, 20},
                {7, 5, 8},
                {8, 7, 10},
                {9, 4, 12},
                {10, 3, 5} };

        cout << JobSelection(arr, 10);;

        return 0;
}
