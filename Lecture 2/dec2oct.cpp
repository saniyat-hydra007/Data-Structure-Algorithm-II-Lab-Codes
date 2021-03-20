#include <stdio.h>
#include <string.h>

int dec2oct(int n, char s[]) {
    if(n < 8) {
        s[0] = n + '0';
        return 1;
    }
    else {
        int i = dec2oct(n/8, s);
        // printf("%s (%d bits)\n", s, i);
        s[i] = n%8 + '0';
        return i+1;
    }
}

int main() {
    char str[100] = {0};
    dec2oct(638, str);
    printf("%s", str);
    return 0;
}
