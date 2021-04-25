#include <stdio.h>
#define INF 99999

int rodcutting(int p[], int n) {
    if(n == 0)
        return 0;

    int q = -INF;
    for(int i=1; i<=n; i++) {
        int a = p[i] + rodcutting(p, n-i);
        if(a > q) {
            q = a;
        }
    }
    return q;
}

int main() {
    int p[] = {INF, 1, 5, 8, 9, 10}; // don't use index 0
    int n = 4;
    int max_rev = rodcutting(p, n);
    printf("%d", max_rev);
    return 0;
}
