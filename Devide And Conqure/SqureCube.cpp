#include <bits/stdc++.h>
using namespace std;

absulate(float x){
        if (x>=0) {
                return x;
        }                 else
                return -x;
}

sqrt(float x){
        float l = 0;
        float h = x;
        float result = 0;
        while(l) {
                float mid = (l+h)/2;
                if(absulate(mid*mid*mid-x) < 0.000001) {
                        result = mid;
                        break;
                }
                else if(mid*mid*mid >x) {
                        h = mid;
                }
                else
                        l = mid;
        }
        return result;
}

int main(){
        cout << sqrt(665) << endl;
}
