#include<bits/stdc++.h>
using namespace std;
const int N = 1e5+5;
int n,m;  //n=number of nodes and m=number of edges
const long long int INF=1e18;
vector<pair<int,int>>adj[N];
long long int d[N];
bool visited[N];
int parent[N];


//Here the dijkstra function that gives output
void dijkstra(int src)
{
    for(int i=1; i<=n; i++){
d[i]=INF;
    }
    d[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({d[src],src});
    while(!pq.empty())
    {
        pair<int,int>f=pq.top();
        pq.pop();
        int selectNode=f.second;
        if(visited[selectNode]) continue;
        visited[selectNode]=true;
        for(auto child:adj[selectNode]){
            int edgecost=child.first; 
            int v=child.second;
            if(d[selectNode]+edgecost<d[v]){
                d[v]=d[selectNode]+edgecost;
                pq.push({d[v],v});
                parent[v]=selectNode;

            }

        }

    }

	
}

int main()
{
  
    cin >> n >> m;

    for(int i=0;i<m;i++)
    {
    	int u,v,w;
    	cin >> u >> v>>w;
    	adj[u].push_back({w,v});
    	adj[v].push_back({w,u});
    }
  int src=1; 
  dijkstra(src);
   if(!visited[n]){
        cout<<-1<<endl;
        return 0;
    }
    int current = n;
    vector<int> paths;

    while (true)
    {
        paths.push_back(current);
        if (current == src)
        {
            break;
        }
        current = parent[current];
    }

    reverse(paths.begin(),paths.end());

    for(int val:paths){
        cout<<val<<" ";
    }
    cout<<endl;

    

	  return 0;
    
}