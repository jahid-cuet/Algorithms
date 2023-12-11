#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef pair<int,int> pii;
const long long int INF=1e9+7;
vector<pair<pii,int>>lists_of_edges;
int d[N];
int n,m;
bool cycle=false;

void bellman_ford(int src){
    for(int i=1;i<=n; i++){
       d[i]=INF;
    }
    d[src]=0;
    for(int i=1;i<n;i++){

//All nodes Relaxation

for(auto edge:lists_of_edges)
{
    int u=edge.first.first;
    int v=edge.first.second;
    int w=edge.second;
    if(d[u]!=INF && d[v]>d[u]+w){
        d[v]=d[u]+w;
    }
}
        }
        
        }


int main(){
    
    cin>>n>>m;
    for(int i=1;i<=m;i++){
    int u,v,w;
    cin>>u>>v>>w;
    lists_of_edges.push_back({{u,v},w});
    }
   long long int q;
    cin>>q;
    while(q--){
    int src,des;
    cin>>src>>des;
    
    bellman_ford(src);
    
        if (d[src] == INT_MAX) {
         cout << -1 << endl;
        }
        cout << d[des] << endl;
    
    }
 	return 0;
    
}