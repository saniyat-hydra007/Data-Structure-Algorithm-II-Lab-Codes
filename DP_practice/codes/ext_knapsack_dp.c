#include <stdio.h>
#define INF 99999

int table[1000][1000];
int choice[1000][1000];

int knapsack(int W, int v[], int wt[], int n) {
    // write your code here
}

void print_solution(int W, int v[], int wt[], int n) {
    // write your code here
}

int main() {
    int v[] = {INF, 60, 100, 120}; // don't use index 0
    int wt[] = {INF, 10, 20, 30}; // don't use index 0
    int n = 3;
    int W = 50;
    int profit = knapsack(W, v, wt, n);
    printf("%d\n", profit);
    print_solution(W, v, wt, n);
    return 0;
}
