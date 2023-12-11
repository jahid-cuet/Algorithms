/* Question: You will be given an undirected graph as input. This graph will contain only one connected component. The edge number will be exactly node-1. Then take a node from the input and print its depth. Consider root as 1.

Sample Input
7 
6
1 2
2 4
2 5
1 3
3 6
1 7
7

Sample Output
Depth of 7 = 1
*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
bool visited[N];
 int depth[N];
 int height[N];
void dfs(int u)
{
    visited[u]=true;
    for(int v:adj[u])
   {
    if(visited[v]==true) continue;
     // depth[v]=depth[u]+1;
      dfs(v);
      height[u] = max(height[u], height[v]+1);
     }
   
}
int main()
{
int n,m;
cin>>n>>m;
for(int i=1;i<=m;i++){

    int u,v;
    cin>>u>>v;
    adj[u].push_back(v);
    adj[v].push_back(u);
}
dfs(1);
int d,h;
 //cin>>d;
 cin>>h;
 //cout<<"depth of "<<d<< ":"<<depth[d]<<" ";
 cout<<"Height of "<<h<< ":"<<depth[h]<<" ";

    return 0;
}