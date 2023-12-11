/*Question:
Problem Statement

Zarif has received M marks in his final term exam out of 1000. However, he wishes to obtain a perfect score of 1000 marks just once in his life. His wish was granted by a fairy who provided him with a list of N marks to choose from. Zarif needs to select any number of marks from that list, but he can choose each mark only once.

Can you tell if he can select marks from this list in such a way that his total marks add up to 1000?

Input Format->
First line will contain T, the number of test cases.
First line of each test case will contain N and M.
Second line of each test case will contain a list A of N marks.
Constraints:

1 <= T <= 1000
1 <= N, M <= 1000
1 <= A[i] <= 100; 0 <= i < N

Output Format:
Output "YES" if he can obtain perfect score of 1000, "NO" otherwise.

Sample Input ->
3
5 1000
1 2 3 4 5
5 999
2 3 4 5 6
6 900
10 20 30 40 50 60

Sample Output->
YES
NO
YES
*/


#include <bits/stdc++.h>
using namespace std;
int main()
{
    
    int t;
    cin>>t;
    while(t--){
    int n,m;
    cin >> n>>m;
    int a[n];
    for (int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    int s;
    s=1000-m;
    bool dp[n + 1][s + 1];
    dp[0][0] = true;
    for (int i = 1; i <= s; i++)
    {
        dp[0][i] = false;
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (a[i - 1] <= j)
            {
                dp[i][j] = dp[i - 1][j - a[i - 1]] || dp[i - 1][j];
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
   
    if (dp[n][s])
        cout << "YES" << endl;
    else
        cout << "NO" << endl;
    }
    return 0;
}