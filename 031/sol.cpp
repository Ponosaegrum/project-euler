/* 11.02.2024 11:26:15 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 8;
  const int m = 200;
  vector<int> a = {1, 2, 5, 10, 20, 50, 100, 200};
  vector<long long> dp(m+1, 0);
  dp[0] = 1;
  for (int j=0; j<n; j++) {
    for (int i=0; i<=m; i++) {
      if (a[j] <= i) {
        dp[i] += dp[i-a[j]];
      }
    }
  }
  cout << dp[m] << '\n';
}
