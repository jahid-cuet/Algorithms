#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
typedef pair<int,int>pi;
bool visited[N][N];
int level[N][N];
int parent[N];
int n,m;
vector<pi>path={{-1,0},{1,0},{0,-1},{0,1}};

bool isvalid(int cI,int cJ){
        if(cI>=0 && cI<n && cJ>=0 && cJ<m){
			return true;
}
else{
	return false;
}
}
void bfs(int si,int sj)
{
	queue<pi>q;
	q.push({si,sj});
	visited[si][sj] = true;
	level[si][sj]=0;

	while(!q.empty())
	{
		pi parent = q.front();
		int PI=parent.first;
		int PJ=parent.second;
		q.pop();
for(int i=0; i<4; i++){
	pi p=path[i];
	int cI=PI+p.first;
	int cJ=PJ+p.second;
	if(isvalid(cI,cJ)&& !visited[cI][cJ]){
		visited[cI][cJ]=true;
		q.push({cI,cJ});
		level[cI][cJ]=level[PI][PJ]+1;
	}
}
	}
}

int main()
{

    cin >> n >> m;
    char a[n][m];

    for(int i=0;i<n;i++)
    {
        for(int j=0; j<m; j++){
            cin>>a[i][j];

        }
    }
    int si,sj;
    cin>>si>>sj;
    bfs(si,sj);
	 for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < m; j++)
        {
            cout << level[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}