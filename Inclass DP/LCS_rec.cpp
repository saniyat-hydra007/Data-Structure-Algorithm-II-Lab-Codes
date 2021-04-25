#include <stdio.h>
#define INF 99999

int max(int a, int b) {
    if(a>b) return a;
    return b;
}

int LCS(char X[], int i, char Y[], int j) {
    if(i == 0 || j == 0)
        return 0;

    if(X[i] == Y[j])
        return LCS(X, i-1, Y, j-1) + 1;
    else {
        int a = LCS(X, i, Y, j-1);
        int b = LCS(X, i-1, Y, j);
        return max(a, b);
    }
}

int main() {
    char X[] = "~ABDE"; // we are not going to use index 0
    char Y[] = "~ZBE"; // we are not going to use index 0
    int m = sizeof(X)/sizeof(char)-2; // excluding '~' and '\0'
    int n = sizeof(Y)/sizeof(char)-2; // excluding '~' and '\0'
    printf("%d", LCS(X, m, Y, n));
    return 0;
}
