#include <stdio.h>
#define INF 99999

int knapsack(int W, int v[], int wt[], int n) {
    if(n == 0 || W == 0)
        return 0;

    int q = -INF;
    if(W - wt[n] < 0) {
        q = knapsack(W, v, wt, n-1);
    }
    else {
        int a = v[n] + knapsack(W - wt[n], v, wt, n-1);
        int b = knapsack(W, v, wt, n-1);
        if(a > b)
            q = a;
        else
            q = b;
    }
    return q;
}

int main() {
    int v[] = {INF, 60, 100, 120}; // don't use index 0
    int wt[] = {INF, 10, 20, 30}; // don't use index 0
    int n = 3;
    int W = 50;
    int profit = knapsack(W, v, wt, n);
    printf("%d", profit);
    return 0;
}
