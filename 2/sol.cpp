/* 08.02.2024 17:45:50 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int dp1 = 1, dp2 = 2;
  long long sm = 2;
  const int mx = 4e6;
  while (1) {
    int cur = dp1 + dp2;
    if (cur > mx) {
      break;
    }
    if (!(cur&1)) {
      sm += cur;
    }
    swap(dp1, dp2);
    swap(dp2, cur);
  }
  cout << sm << '\n';
}
