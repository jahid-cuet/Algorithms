#include<bits/stdc++.h>
using namespace std;
#define pi pair<int,int>
const long long int N=1e5;
bool vis[N];
vector<pi>v[N];

class Edge{
    public:
    int a,b,w;
    Edge(int a,int b,int w){
        this->a=a;
        this->b=b;
        this->w=w;
    }


};
class cmp
{
public:
    bool operator()(Edge a, Edge b)
    {
        return a.w > b.w;
    }
};

void prims(int s){
     priority_queue<Edge, vector<Edge>, cmp> pq;
     vector<Edge>Edge_list;
     pq.push(Edge(s,s,0));
     while(!pq.empty()){
        Edge parent=pq.top();
        pq.pop();
        int a=parent.a;
        int b=parent.b;
        int w=parent.w;
        if(vis[b]) continue;
        vis[b]=true;
        Edge_list.push_back(parent);
        for(pi child:v[b]){
            if(!vis[child.first]){
                pq.push(Edge(b,child.first,child.second));
            }
            

        }
       

     }
      Edge_list.erase(Edge_list.begin());
for(Edge val:Edge_list){
    cout<<val.a<<" "<<val.b<<" "<<val.w<<endl; 

}


}


int main()
{
  int n,e;
  cin>>n>>e;
  while(e--){
    int a,b,w;
    cin>>a>>b>>w;
    v[a].push_back({b,w});
    v[b].push_back({a,w});
  }  
  prims(1);
    return 0;
}


/* how compare function work

pq.push(Edge(1,2,10));
     pq.push(Edge(1,5,5));
     while(!pq.empty()){
        Edge p=pq.top();
        pq.pop();
        cout<<p.w<<endl;
     }

*/