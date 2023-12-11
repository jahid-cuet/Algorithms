#include<bits/stdc++.h>
using namespace std;
int bounded_knapsack(int n,int s,int v[],int w[]){
if(n==0 ||s==0) return 0;
if(w[n-1]<=s){
int op1=v[n-1]+bounded_knapsack(n,s-w[n-1],v,w);
int op2=bounded_knapsack(n-1,s,v,w);
return max(op1,op2);
}
else{
  return bounded_knapsack(n-1,s,v,w);

}

}
int main()
{
  int n,s;
  cin>>n>>s;
  int v[n];
    
  for(int i=0; i<n;i++){
    cin>>v[i];
  }  
  int w[n];
  for(int i=0; i<n;i++){
    cin>>w[i];
  }  
  cout<<bounded_knapsack(n,s,v,w);
  return 0;
}