#include <bits/stdc++.h>
using namespace std;

absulate(float x){
        if (x>=0) {
                return x;
        }                 else
                return -x;
}


float SqRoot_req(float l,float h,float x){
        float mid = (l+h)/2;
        if(absulate(mid*mid -x) < 0.000001)
                return mid;
        else if(mid*mid >x)
                return SqRoot_req(l,mid,x);
        else return SqRoot_req(mid,h,x);
}
int main(){

}
