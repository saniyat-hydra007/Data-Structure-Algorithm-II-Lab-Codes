#include <stdio.h>

int fib(int n) {
    if(n == 1)
        return 0;
    else if(n == 2)
        return 1;
    else {
        return fib(n-1) + fib(n-2);
    }
}


int main() {

    for(int i=1; i<=10; i++){
        int f = fib(i);
        printf("%d ", f);
    }

    return 0;
}
