#include <stdio.h>

int comb(int n, int r) {
    if(r == 0)
        return 1;
    else if(n == r) {
        return 1;
    }
    else {
        return comb(n-1, r-1) + comb(n-1, r);
    }
}

int main() {
    int f = comb(30, 17);
    printf("%d\n", f);
    return 0;
}
