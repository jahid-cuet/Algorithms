#include<bits/stdc++.h>
using namespace std;

const int N=1e5+7;
int arr[N];


int main()
{
  int n;
  cin>>n;
  int arr1[n];
    for(int i=0; i<n; i++){
      cin>>arr1[i];
    }
    int m;
     cin>>m;
    int arr2[m];
    for(int i=0; i<n; i++){
      cin>>arr2[i];
    }
    arr1[n]=INT_MIN;
    arr2[m]=INT_MIN;
int lp=0,rp=0;
for(int i=0;i<=m+n;i++){

if(arr1[lp]<arr2[rp]){
   arr[i]=arr2[rp];
   rp++;

}
else{
   arr[i]=arr1[lp];
   lp++;
}

}

for(int i=0; i<m+n; i++){
      cout<<arr[i]<<" ";
    }
     
    
    return 0;
}