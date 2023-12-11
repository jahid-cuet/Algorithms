#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
bool visited[N];
vector<int>g[N];
int n,m;
void dfs(int u){
    visited[u]=true;

    for(int v:g[u]){
    if(!visited[v]){
        dfs(v);
    }  
}
}
int main()
{
    int cnt=0;
    vector<int>p;
     cin>>n>>m;
     for(int i=1;i<=m;i++)
    {
        int u,v;
        cin>>u>>v;
        g[u].push_back(v);
        g[v].push_back(u);
        }

	 for (int i = 1; i<= n; i++)
    {
        if(!visited[i]){
            cnt++;
            dfs(i);
            p.push_back(i);   
        }
    }
    cout<<"The Connected Component is:"<<cnt<<" ";
    cout<<"Connected Betwenn these two componets are:";
    for(int i=0;i<p.size()-1;i++){
        cout<<p[i] << " "<<p[i+1];
    }
    return 0;
}