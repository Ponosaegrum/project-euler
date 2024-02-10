/* 08.02.2024 21:29:39 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int cur = 1, add = 2;
  auto solve = [&](int x) {
    set<int> d;
    for (int i=1; i<=sqrt(x); i++) {
      if (x%i == 0) {
        d.insert(i);
        d.insert(x / i);
      }
    }
    return d.size();
  };
  while (1) {
    int ans = solve(cur);
    if (ans > 500) {
      cout << cur << '\n';
      return 0;
    }
    cur += add++;
  }
}
