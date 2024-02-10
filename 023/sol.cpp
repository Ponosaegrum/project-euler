/* 10.02.2024 11:05:49 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  vector<int> a;
  auto solve = [&](int x) {
    set<int> cur;
    for (int i=1; i<=sqrt(x); i++) {
      if (x%i == 0) {
        cur.insert(i);
        if (i != 1) {
          cur.insert(x / i);
        }
      }
    }
    long long ret = 0;
    for (int c : cur) {
      ret += c;
    }
    return ret;
  };
  for (int i=1; i<=30000; i++) {
    long long cur = solve(i);
    if (cur > i) {
      a.emplace_back(i);
    }
  }
//  for (int x : a) { cerr << x << " "; } cerr << '\n';
  vector<bool> good(28123+1, true);
  int n = a.size();
  for (int i=0; i<n; i++) {
    for (int j=0; j<n; j++) {
      int cur = a[i]+a[j];
      if (cur>0 && cur<=28123) {
        good[cur] = false;
      }
    }
  }
  long long sm = 0;
  for (int i=1; i<=28123; i++) {
    sm += (good[i] ? i : 0);
  }
  cout << sm << '\n';
}
