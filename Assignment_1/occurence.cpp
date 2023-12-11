#include<bits/stdc++.h>
using namespace std;
bool bS(int arr[], int k, int l, int r) {
  int cnt=0;
    while (l <r) {
        int mid = (l+r)/2;
        if (arr[mid] == k) {
         if (arr[mid - 1]==k) {
                return true;
            }
        
            if (arr[mid + 1]== k) {
                return true;
            }
            return false;  
 } 
      else if (arr[mid] < k) {
       l = mid + 1;  
} else {
 r= mid - 1;
  }
    }
    return false;
     
}

int main() {
    int N;
    cin >>N;
    int arr[N];
    for (int i = 0; i < N; i++) {
        cin >> arr[i];
    }
     int k;
    cin >> k;  
//Binary search works in O(logN) complexity .so here we used binary search.

    if(bS(arr, k,0, N-1)){
    cout <<"Yes"<< endl;
    } else {
    cout <<"NO" << endl;
    }
    
    return 0;
}


























