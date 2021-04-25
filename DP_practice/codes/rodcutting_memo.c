#include <stdio.h>
#define INF 99999

int r[1000];

void init_table(int n) {
	// write your code here
}

int rodcutting(int p[], int n) {
    // write your code here
}

int main() {
    int p[] = {INF, 1, 5, 8, 9, 10}; // don't use index 0
    int n = 5;
    init_table(n);
    int max_rev = rodcutting(p, n);
    printf("%d\n", max_rev);
    return 0;
}
