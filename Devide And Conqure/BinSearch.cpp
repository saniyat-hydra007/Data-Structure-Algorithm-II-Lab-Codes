/**
 * @Author: Saniyat Mushrat Lamim
 * @Date:   14-Mar-2021
 * @Email:  robertarmstrong096@gmail.com
 * @Last modified by:   Saniyat Mushrat Lamim
 * @Last modified time: 21-Mar-2021
 */



#include <bits/stdc++.h>
using namespace std;

bin_search(int A[], int n, int key){
        int l = 0;
        int h = n-1;
        int index = -1;
        while(l <= h) {
                int mid = (l+h)/2;
                if(A[mid] == key) {
                        index = mid;
                        break;
                }
                else if(A[mid] >key) {
                        h = mid-1;
                }
                else{
                        l=mid+1;
                }
        }
        return index;
}
int main(){
        int arr[] = {2,5,7,8,9,13,16,19,33,43};

        cout << "Index is: " << bin_search(arr,10,16) << endl;
        return 0;
}
