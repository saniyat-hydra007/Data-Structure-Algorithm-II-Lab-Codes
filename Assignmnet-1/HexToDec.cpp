#include <iostream>
#include <math.h>
#include <string.h>
using namespace std;

int hex2dec(char s[],int i,int j)
{
        int a;
        if(i < 0)
                return 0;
        else if(s[i] >= 65 && s[i] <= 70)
                a = s[i] - 55;
        else if(s[i] >= 97)
                a = s[i] - 87;
        else
                a = s[i] - 48;

        return a*pow(16,j) + hex2dec(s,i-1,j+1);
}
int main()
{
        char str[100]= "23A405D";
        int n_bit = strlen(str);
        int dec = hex2dec(str,n_bit-1,0);
        cout<< dec << endl;
        return 0;
}
