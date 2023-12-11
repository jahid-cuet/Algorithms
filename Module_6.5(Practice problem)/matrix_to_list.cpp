/*Question: You will be given an adjacency matrix for a directed graph (index starting from 1) as input. Now, convert it to an adjacency list and print it.

Sample Input
4
0 0 0 1
1 0 0 1
1 1 0 0
0 0 1 0

Sample Output->
List 1 : 4
List 2 : 1 4
List 3 : 1 2
List 4 : 3
*/
#include<bits/stdc++.h>
using namespace std;
const int N=1e5+5;
vector<int>adj[N];

int main()
{

    int n,m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);//For directed
        //adj[v].push_back(u);
       // adjmat[v][u]=1; // when both are comment out then resullt will be undirected
    }

    for(int i=1;i<=n;i++){
        cout<<"list"<<i<<":"<<" ";
        for(int j:adj[i]){
            cout<<j<<" ";
        }
        cout<<endl;
    }
    // //Print the matrix
    // for(int i=1; i<=n; i++){
    //     cout<< "List "<< i <<": ";
    //     for(int j:adj[i]){
    //         cout<< j <<" ";
    //     }
    //     cout<<endl;
    // }

    
    return 0;
}



