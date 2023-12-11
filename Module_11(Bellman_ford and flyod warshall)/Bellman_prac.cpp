
/*
Given a directed graph, that can contain multiple edges and loops.
 Each edge has a weight that is expressed by a number (possibly negative). 
 It is guaranteed that there are no cycles of negative weight.

Calculate the length of the shortest paths from the vertex number 1 to all other vertices.

Input data
First the number of vertices n (1 ≤ n ≤ 100) is given. 
It is followed by the number of edges m (0 ≤ m ≤ 10000).
Next m triples describe the edges: beginning of the edge, the end of the edge and its weight (an integer from -100 to 100).

Output data
Print n numbers - the distance from the vertex number 1 to all other vertices of the graph.
 If the path to the corresponding vertex does not exist, instead of the path length print the number 30000.
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+10;
typedef pair<int,int> pii;
const long long int INF=3000;
vector<pair<pii,int>>lists_of_edges;
int d[N];
int n,m;

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
    lists_of_edges.push_back({{u,v},w}
    );
    }
   bellman_ford(1);

    for(int i=1; i<=n;i++){ 
        
     cout<<d[i]<<" ";
}
 	return 0;
    
}