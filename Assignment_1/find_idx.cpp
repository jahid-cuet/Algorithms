#include<bits/stdc++.h>
using namespace std;

int bS(int arr[], int k, int l, int r) {
    while (l <r) {
        int mid = (l+r)/2;
        if (arr[mid] == k) {
            return mid;
 } 
       if (arr[mid] < k) {
       l = mid + 1;  
} else {
     r= mid - 1;
  }
    }
      return -1;  
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
// Binary search works in O(logN) complexity .so here we used binary search.

    if(bS(arr, k,0, N-1)!= -1) {
    cout <<bS(arr, k,0, N-1) << endl;
    } else {
    cout <<"Not Found" << endl;
    }
    
    return 0;
}
