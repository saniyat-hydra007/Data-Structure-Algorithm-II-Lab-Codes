#include <stdio.h>
#include <string.h>

int dec2hex(int n, char s[]) {
        if(n < 16) {
                if(n < 10) {
                        s[0] = n + '0';
                }
                else {
                        s[0] = (n-10) + 'A';
                }
                return 1;
        }
        else {
                int i = dec2hex(n/16, s);
                // printf("%s (%d bits)\n", s, i);
                int mod = n%16;
                if(mod < 10) {
                        s[i] = mod + '0';
                }
                else {
                        s[i] = (mod-10) + 'A';
                }
                return i+1;
        }
}

int main() {
        char str[100] = {0};
        dec2hex(2543738, str);
        printf("%s",str);
        return 0;
}
