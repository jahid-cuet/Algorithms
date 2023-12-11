#include<bits/stdc++.h>
using namespace std;
const int N = 1005;
char grid[N][N];
bool vis[N][N];
typedef pair<int,int>pi;
    int n, m;
    int min_area=INT_MAX;
    
    vector<pair<int, int>> path = {{-1, 0}, {1, 0}, {0, -1}, {0, 1}};
    bool isValid(int cI, int cJ)
    {
        if (cI >= 0 && cI < n && cJ >= 0 && cJ < m)
            return true;
        else
            return false;
    }
    int cnt;
    void dfs(int si, int sj)
    {
        vis[si][sj] = true;
        cnt++;
        for (int i = 0; i < 4; i++)
        {
            pair<int, int> p = path[i];
            int ci = si + p.first;
            int cj = sj + p.second;
            if (isValid(ci, cj) && !vis[ci][cj] && grid[ci][cj] == '.')
            {
                dfs(ci, cj);
            }
        }
    }


 int main()
    {
        cin>>n>>m;
      
        for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                 cin>>grid[i][j];
                
            }
        }


            for (int i = 0; i < n; i++)
        {
            for (int j = 0; j < m; j++)
            {
                if (!vis[i][j] && grid[i][j] == '.')
                {
                    cnt = 0;
                    dfs(i, j);
                  min_area=min(min_area,cnt);
                }
            }
        }
        if(min_area==INT_MAX){
             cout<<"-1"<<endl;
        }
        else {
            cout<<min_area<<endl;
        }
        return 0;   

    }
