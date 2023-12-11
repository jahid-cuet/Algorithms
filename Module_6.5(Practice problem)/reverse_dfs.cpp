/*Question: You will be given an undirected graph. Print its DFS traversal in reverse order. Consider root as 1.

Sample Input

4 
4
1 2
4 3
3 2
2 4
3 4 2 1
Sample Output
( 4 3 2 1 is also valid ans)

*/

#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];
bool visited[N];
void dfs(int u)
{
    visited[u]=true;
  //  cout<<u<<" ";
    for(int v:adj[u])
   {
    if(visited[v]==true) continue;
    dfs(v);
      
     }
     cout<<u<<" ";
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
// for(int i=0;i<n;i++){
//     cout<<"list"<<i<<" :";
//    for(int j:adj[i]){
    
//     cout<<j<<" ";
//    }
//    cout<<endl;
//    }
    return 0;
}