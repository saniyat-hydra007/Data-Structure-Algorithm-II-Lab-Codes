#include <stdio.h>

int fact(int n) {
    if(n == 0)
        return 1;
    else {
        return n * fact(n-1);
    }
}

int main() {

    printf("%d", fact(7)/(fact(4)*fact(7-4)));

    return 0;
}
