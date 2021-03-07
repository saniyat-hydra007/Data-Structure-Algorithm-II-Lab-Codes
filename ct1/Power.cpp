#include <bits/stdc++.h>
#include <stdio.h>
#include <string.h>
using namespace std;

int power(int x, int y){
        if(y!=0) {
                return (x*power(x,y-1));
        }
        else
                return 1;
}

int main(){
        int x,y;
        long long result;
        scanf("%d",&x);
        scanf("%d",&y);
        result = power(x,y);
        printf("%ld",result);
        return 0;
}
