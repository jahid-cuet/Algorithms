#include<bits/stdc++.h>
using namespace std;
const long long int INF=1e9;

int main(){

    int n,e;
    cin>>n>>e;
   long long int d[n+1][n+1];
   
    for(int i=1;i<=n; i++){
    for(int j=1; j<=n;j++){
    d[i][j]=INF;
    if(i==j){
        d[i][j]=0;
    }
}
    }
    while(e--){
    int u,v,w;
    cin>>u>>v>>w;
    d[u][v]=w;
    }
     
for(int k=1;k<=n;k++){

for(int i=1;i<=n;i++){

for(int j=1;j<=n;j++){
    if(d[i][k]+d[k][j]<d[i][j]){

        d[i][j]=d[i][k]+d[k][j];
    }
}

}

}

int q;
    cin>>q;
    while(q--){
    int src,des;
    cin>>src>>des;

     if(d[src][des]==INF) cout<<"-1"<<" ";
            else cout<<d[src][des]<<" ";
        }
    
    


 	return 0;
    
}