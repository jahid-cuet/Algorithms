#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
vector<int> adj[N]; //Every index of array will contain Vector 
bool visited[N];
int level[N];

void bfs(int s){
    queue<int>q;
    q.push(s);
    visited[s]=true;
    level[s]=0;
     
while(!q.empty()){
int u=q.front();
q.pop();
for(int v:adj[u]){
if(visited[v]) continue;
q.push(v);
visited[v]=true;
level[v]=level[u]+1;
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
    adj[u].push_back(v);
    adj[v].push_back(u);   //THis two for the undirected list
    }
    //The printing part
    // for(int i=0;i<n;i++){
    //     cout<<i<<" "<<level[i]<<endl;
     // if source and level are given then print the distance
     int Q;
     cin>>Q;
    while(Q--){
     int f,
     d;
     cin>>f>>d;
   
     for(int i=0; i<n;i++){
           (visited[i])=false;
           level[i]=0;
        } 
        bfs(f);  
        if(visited[d]){
            cout<<level[d]<<endl;
        }
        
               else {
          cout << -1 << endl; // No path found
    }
     }
    
     
          
         /*
         if level given ,then print the level element 
         for(int i=0;i<n;i++){
            if(level[i]==2){
        cout<<i<<endl;
         
         
         */
    
    return 0;
}