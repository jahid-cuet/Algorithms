#include <bits/stdc++.h>
using namespace std;
const int N = 1e5 + 5;
vector<pair<int, int>> adj[N];
int dis[N];
bool vis[N];
int n, e;
void dijkstra(int src)
{
     
    dis[src]=0;
    priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>>pq;
	pq.push({dis[src],src});
    while(!pq.empty())
    {
        pair<int,int>f=pq.top();
        pq.pop();
        int selectNode=f.second;
        if(vis[selectNode]) continue;
        vis[selectNode]=true;

        for(auto child:adj[selectNode]){
            int edgecost=child.first; 
            int v=child.second;

            if(dis[selectNode]+edgecost<dis[v]){
                dis[v]=dis[selectNode]+edgecost;
                pq.push({dis[v],v});

            }

        }

    }

	
}

int main()
{
    
    cin >> n >> e;
    while (e--)
    {
        int a, b, w;
        cin >> a >> b >> w;
        adj[a].push_back({b, w});
         //adj[b].push_back({a, w});
    }
     for (int i = 1; i <= n; i++)
    {
        dis[i] = INT_MAX;
    }
    int q;
    cin>>q;
    while(q--){
    int src,des;
    cin>>src>>des;
     for (int i = 1; i <= n; i++) {
     dis[i] = INT_MAX;
     vis[i] = false;
        }
    dijkstra(src);
    
        if (dis[src] == INT_MAX) {
         cout << -1 << endl;
        }
        else{
        cout << dis[des] << endl;
        }
    
    }

    return 0;
}