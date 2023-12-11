#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
typedef pair<int,int>pi;
bool vis[N][N];
int n,m;
char a[N][N];

vector<pi>path={{-1,0},{1,0},{0,-1},{0,1}};

bool isValid(int cI, int cJ)
{
    if (cI >= 0 && cI < n && cJ >= 0 && cJ < m && a[cI][cJ] =='.')
        return true;
else{
	return false;
}
}
void dfs(int si,int sj)
{
	vis[si][sj]=true;
    for(int i=0;i<4; i++){
    pi p=path[i];
    int cI=si+p.first;
    int cJ=sj+p.second;
   if(isValid(cI,cJ) && !vis[cI][cJ])
   dfs(cI,cJ);
    }
}

int main()
{
    cin >> n >> m;
    for(int i=0;i<n;i++)
    {
        for(int j=0; j<m; j++){
          cin>>a[i][j];
        }
    }

    int si,sj,di,dj;
    cin>>si>>sj>>di>>dj;
   
            dfs(si, sj);
            if(vis[di][dj]){
                cout<<"YES"<<endl;
            }
            else{
                cout<<"NO";
            }
        
    
    return 0;
}