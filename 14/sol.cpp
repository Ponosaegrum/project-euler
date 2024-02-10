/* 08.02.2024 20:55:01 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  long long n = 1000000;
  int mx = -1;
  auto solve = [&](long long x) {
    int cnt = 0;
    while (x != 1) {
      x = (x&1 ? 3*x+1 : x/2);
      ++cnt;
    }
    return cnt+1;
  };
  int ans = -1;
  for (int i=n-1; i>=100000; i--) {
//    cerr << "[i]: " << i << '\n';
    int cur = solve(i);
    if (cur > mx) {
      mx = cur;
      ans = i;
    }
  }
  cout << ans << '\n';
}
