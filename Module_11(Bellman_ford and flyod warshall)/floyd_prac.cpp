#include<bits/stdc++.h>
using namespace std;
const long long int INF=1e9;

int main(){

    int n;
     cin>>n;
    int d[n+1][n+1];
   
    for(int i=1;i<=n; i++){
    for(int j=1; j<=n;j++){
    cin>>d[i][j];
    }
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