/* 09.02.2024 22:28:43 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int n = 15;
  vector g(n, vector(n, 0));
  g[0] = {75};
  g[1] = {95, 64};
  g[2] = {17, 47, 82};
  g[3] = {18, 35, 87, 10};
  g[4] = {20, 4, 82, 47, 65};
  g[5] = {19, 1, 23, 75, 3, 34};
  g[6] = {88, 2, 77, 73, 7, 63, 67};
  g[7] = {99, 65, 4, 28, 6, 16, 70, 92};
  g[8] = {41, 41, 26, 56, 83, 40, 80, 70, 33};
  g[9] = {41, 48, 72, 33, 47, 32, 37, 16, 94, 29};
  g[10] = {53, 71, 44, 65, 25, 43, 91, 52, 97, 51, 14};
  g[11] = {70, 11, 33, 28, 77, 73, 17, 78, 39, 68, 17, 57};
  g[12] = {91, 71, 52, 38, 17, 14, 91, 43, 58, 50, 27, 29, 48};
  g[13] = {63, 66, 4, 68, 89, 53, 67, 30, 73, 16, 69, 87, 40, 31};
  g[14] = {4, 62, 98, 27, 23, 9, 70, 98, 73, 93, 38, 53, 60, 4, 23};
  vector dp(n+1, vector(n+1, 0));
  for (int i=0; i<n; i++) {
    for (int j=0; j<=i; j++) {
      dp[i+1][j] = max(dp[i+1][j], dp[i][j] + g[i][j]);
      dp[i+1][j+1] = max(dp[i+1][j+1], dp[i][j] + g[i][j]);
    }
  }
  cout << *max_element(dp[n].begin(), dp[n].end()) << '\n';
}
