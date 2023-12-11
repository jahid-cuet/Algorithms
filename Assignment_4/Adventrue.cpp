/*Question:
Problem Statement

Once upon a time, there was a treasure hunter who ventured into an ancient temple in search of a valuable artifact. The temple was filled with traps and obstacles, and the treasure hunter had to carry all of his equipment with him.

The treasure hunter had a backpack with a limited weight capacity, and he could only carry a certain amount of equipment with him. Each piece of equipment had its own weight and value, and the treasure hunter needed to choose which items to bring to maximize the total value while keeping the total weight under the limit.

Help the treasure hunter to choose which items to bring in his backpack to maximize their total value while keeping the total weight of his backpack under a certain limit. Each item can only be included once.

Input Format ->
First line will contain T, the number of test cases.
The first line of each test case will contain N(Number of items) and W(Total weight of backpack).
Second line of each test case will contain an array w containing the weights of all items.
Third line of each test case will contain an array v containting the values of all items.
Constraints:
1 <= T <= 1000
1 <= N <= 1000
0 <= W <= 1000
0 <= w[i] <= 1000; Here 0 <= i < N
0 <= v[i] <= 1000; Here 0 <= i < N

Output Format->
Output the maximum total value you can obtain in the backpack for each test case.


Sample Input->
2
4 7
2 3 4 5
4 7 6 5
4 17
10 1 6 9
6 10 10 8
Sample Output ->
13
28

Explanation->
In the first test case case, he can take 2nd and 3rd item which total weight is 3+4=7 and total value is 7+6=13 and its the maximum value possible.
*/






#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
    int n,s;
    cin >> n>>s;
    int w[n];
         for (int i = 0; i < n; i++)
    {
        cin >> w[i];
    }
        int v[n];
    for (int i = 0; i < n; i++)
    {
        cin >> v[i];
    }
   
   
    int dp[n + 1][s + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= s; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= s; j++)
        {
            if (w[i - 1] <= j)
            {
                // dp state
                dp[i][j] = max(v[i - 1] + dp[i - 1][j - w[i - 1]], dp[i - 1][j]);
            }
            else
            {
                dp[i][j] = dp[i - 1][j];
            }
        }
    }
   cout<<dp[n][s]<<endl;
    }
    return 0;
}

