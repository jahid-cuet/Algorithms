#include<bits/stdc++.h>
using namespace std;
const int N=1e5 + 5;
vector<int>adj[N];
bool visited[N];
void dfs(int u)
{
    visited[u]=true;
    for(int v:adj[u])
   {
    if(visited[v]==true) continue;
    dfs(v);
      
     }
}
int main()
{
int n,m;
cin>>n>>m;
for(int i=0;i<m;i++){

    int u,v;
    cin>>u>>v;
    adj[u].push_back(v); //For one way
    
}
int f;
cin>>f;
for(int i=0;i<n;i++){
    visited[i]=false;
}
dfs(f);
int c=0;
for(int i=0;i<n;i++){
    if(visited[i]){
        c++;
    }
}
cout<<c-1; //subract 1  the kamals house itself here that was also visited

    return 0;
}