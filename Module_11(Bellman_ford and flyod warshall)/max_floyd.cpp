#include<bits/stdc++.h>
using namespace std;
const long long int INF=1e9;

int main(){

    int n,e;
     cin>>n>>e;
    int d[n+1][n+1];
   
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
     cout<<"Before Updated:"<<endl;
     for(int i=1;i<=n;i++){
        for(int j=1; j<=n; j++){
            if(d[i][j]==INF) cout<<"INF"<<" ";
            else cout<<d[i][j]<<" ";
        }
        cout<<endl;
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
 cout<<"After Updated:"<<endl;

    for(int i=1;i<=n;i++){
        for(int j=1; j<=n; j++){
            if(d[i][j]==INF) cout<<"INF"<<" ";
            else cout<<d[i][j]<<" ";
        }
        cout<<endl;
    }
    


 	return 0;
    
}