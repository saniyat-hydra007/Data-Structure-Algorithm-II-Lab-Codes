#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int formula(int n)
{
        if (n==0)
        {
                return 0;
        }
        else if (n == 1)
        {
                return 1;
        }
        else if (n == 2)
        {
                return 2;
        }
        else
        {
                return formula(n/2)+formula(n/3);
        }
}

int main(){
        int n,result;
        scanf("%d",&n);
        result = formula(n);
        printf("%d",result);
        return 0;
}
