#include<bits/stdc++.h>
using namespace std;
int main()
{
  string a,b;
  cin>>a>>b;
  int n=a.size();
  int m=b.size();
  string c;
  int x=0;
  bool ans=false;
  for(char c:b){
    if(c==a[x]){
        x++;
    }
    if(x==a.size()){
        ans=true;
        break;
    }
  }  
  if(ans) cout<<"YES";
  else cout<<"FALSE";
    return 0;
}