#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
bool visited[N];
void dfs(int u)
{
    visited[u]=true;
    cout<<u<<" ";
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
    adj[u].push_back(v);
    adj[v].push_back(u);
}
dfs(0);
// for(int i=0;i<n;i++){
//     cout<<"list"<<i<<" :";
//    for(int j:adj[i]){
    
//     cout<<j<<" ";
//    }
//    cout<<endl;
//    }
    return 0;
}