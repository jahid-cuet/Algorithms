#include<bits/stdc++.h>
using namespace std;

int main()
{
vector<pair<int,int>>p;
    int e;
    cin >> e;
    for(int i=0;i<e;i++)
    {
    	int u,v;
    	cin >> u >> v;
        p.push_back({u,v});

    }
   sort(p.begin(),p.end());
   
   for(auto a:p){
    cout<<a.first<<" "<<a.second<<endl;
   }
   
	  return 0;
    
}