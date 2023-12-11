#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef pair<int,int> pii;
const long long int INF=1e9+7;
vector<pair<int,int>>g[N];
int d[N];
int n,m;

void bellman_ford(int src){
    for(int i=1;i<=n; i++){
       d[i]=INF;
    }
    
    d[src]=0;
    for(int i=1;i<n;i++){
//All nodes Relaxation
        for(int u=1;u<=n;u++){

for(pii vpair:g[u])
{
    int v=vpair.first;
    int w=vpair.second;

    if(d[u]!=INF && d[v]>d[u]+w){
        d[v]=d[u]+w;
    }
}
        }

    }

}
int main(){
    
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    g[u].push_back({v,w});
    }
    bellman_ford(1);

    for(int i=1; i<=n;i++){
        cout<<"Distance of "<<i;
        cout<<":"<<d[i]<<endl;
    }
 	return 0;
    
}