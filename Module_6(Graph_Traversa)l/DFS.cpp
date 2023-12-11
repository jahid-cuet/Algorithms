#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj_list[N]; //Every index of array will contain Vector 
int visited[1000];

void dfs(int par){
    cout<<par<<" ";
    visited[par]= 1; 

    for(int child:adj_list[par]){
        if(visited[child]==0){
            dfs(child);
        }
    }

}
int main()
{
    int n; //Number of node
    int m; //Number of edge
    cin>>n>>m;
    for(int i=0;i<m;i++){ //take number of edges as input
    int u,v;
    cin>>u>>v;
    adj_list[u].push_back(v);
    adj_list[v].push_back(u);   //THis two for the undirected list
    }
int par=1;
    dfs(par);
    //The printing part
    // for(int i=1;i<=n;i++){
    //     cout<<i<<"-->";
    //     for(int j=0; j<adj_list[i].size();j++){ //also write this line this way: for(int val:adj_list[i])
    //         cout<<adj_list[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    return 0;
}