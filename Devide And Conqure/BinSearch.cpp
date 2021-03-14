#include <stdio.h>

bin_search(A[],len,key){
        l = 0;
        h = len-1;
        index = -1;
        while(l <= h) {
                mid = (l+h)/2;
                if(A[mid] == key) {
                        index = mid;
                        break;
                }
                else if(A[mid] >key) {
                        H = mid-1;
                }
                else{
                        l=mid+1;
                }
        }
        return index;
}
