#include <stdio.h>

int gcd(int a,int b){
        if(a%b == 0)
                return b;
        else return gcd(b, a%b);
}

int main(){

        cout<<gcd(23,6);
        return 0;
}
