#include <stdio.h>
#include <string.h>

int dec2bin(int n, char s[]) {
        if(n < 2) {
                s[0] = n + '0';
                return 1; // solved upto 1 bit
        }
        else {
                int i = dec2bin(n/2, s); // solved upto i bit
                // printf("%s (%d bits)\n", s, i);
                s[i] = n%2 + '0';
                return i+1; // solved upto i+1 bit
        }
}

int main() {
        char str[100] = {0};
        dec2bin(43, str);
        printf("%s", str);
        return 0;
}
