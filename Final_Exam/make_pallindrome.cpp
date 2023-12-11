/*Problem Statement

Rahim, fueled by his newfound fascination with strings and the enigmatic world of palindromes, has a challenging quest in mind. He's got a string swirling around in his thoughts, but the catch is, he's not entirely sure how palindromes work! Nevertheless, he's determined to transform his string into a glorious palindrome, and he's on a mission to do it in the quickest time possible.

Now, here's the deal: Rahim can add characters to his string at any position, but it comes at the price of one minute per character. Rahim, being the savvy time-saver he is, doesn't want to squander precious minutes. That's where you come in!

Your task is to help Rahim figure out the minimum time it will take to turn his string into a palindrome. Imagine the clock ticking and Rahim eagerly awaiting your genius advice. Let's embark on this palindromic journey and make it as swift and fascinating as possible!

Input Format

First line will contain T, the number of test cases.
Each line of the test case will contain the string S.
Constraints

1 <= T <= 1000
1 <= |S| <= 1000; Here |S| means the length of S. The string will contain only English alphabets and won't contain any spaces.
Output Format

Output the minimum time needed to make the string palindrome.
Sample Input 0

5
madam
mcadam
madcam
mcaedam
macdarm
Sample Output 0

0
1
1
2
2 
*/
#include <bits/stdc++.h>
using namespace std;
int main()
{
    int t;
    cin>>t;
    while(t--){
    string a;
    cin >> a;
    int n = a.size();
    string b = a;
    reverse(b.begin(), b.end());
    int m = b.size();

    int dp[n + 1][m + 1];
    for (int i = 0; i <= n; i++)
    {
        for (int j = 0; j <= m; j++)
        {
            if (i == 0 || j == 0)
                dp[i][j] = 0;
        }
    }
    for (int i = 1; i <= n; i++)
    {
        for (int j = 1; j <= m; j++)
        {
            if (a[i - 1] == b[j - 1])
            {
                dp[i][j] = dp[i - 1][j - 1] + 1;
            }
            else
            {
                dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]);
            }
        }
    }
    cout<<a.size()-dp[n][m]<<endl;
    }
    return 0;
}
