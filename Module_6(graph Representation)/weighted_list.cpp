#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<pair<int,int> >adj[N];

int main()
{

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v,w;
        cin>>u>>v>>w;
        adj[u].push_back({v,w});//For directed
        //adj[v].push_back(u);
       // adjmat[v][u]=1; // when both are comment out then resullt will be undirected
    }
    //Print the matrix
    for(int i=1; i<=n; i++){
        cout<< "List "<< i <<": ";
        for(auto j:adj[i]){
            cout<< "("<<j.first <<", "<<j.second<<"),";
        }
        cout<<endl;
    }

    
    return 0;
}