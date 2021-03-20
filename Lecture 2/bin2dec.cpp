#include <stdio.h>
#include <string.h>

int bin2dec(char s[], int k) {
        if(k == 1) {
                return s[k-1] - '0';
        }
        else {
                int x = s[k-1] - '0';
                int y = bin2dec(s, k-1);
                return 2*y + x;
        }
}

int main() {
        char str[100] = "10101101";
        int n_bit = strlen(str);
        int dec = bin2dec(str, n_bit);
        printf("%d", dec);
        return 0;
}
