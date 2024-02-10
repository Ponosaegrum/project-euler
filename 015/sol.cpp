/* 08.02.2024 21:38:57 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 20;
  vector dp(n+1, vector(n+1, 0ll));
  dp[0][0] = 1;
  for (int i=0; i<=n; i++) {
    for (int j=0; j<=n; j++) {
      if (j+1 <= n) {
        dp[i][j+1] += dp[i][j];
      }
      if (i+1 <= n) {
        dp[i+1][j] += dp[i][j];
      }
    }
  }
  cout << dp[n][n] << '\n';
}
