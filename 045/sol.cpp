/* 12.02.2024 22:49:49 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  auto f = [&](int i) {
    return i * 1ll * (i+1) / 2ll;
  };
  auto g = [&](int i) {
    return i * 1ll * (3ll*i - 1) / 2ll;
  };
  auto h = [&](int i) {
    return i * 1ll * (2ll*i - 1);
  };
  int n = 1;
  map<long long, int> cnt;
  const long long MX = 1e12;
  while (f(n) <= MX) {
    cnt[f(n++)]++;
  }
  n = 1;
  while (g(n) <= MX) {
    cnt[g(n++)]++;
  }
  n = 1;
  while (h(n) <= MX) {
    cnt[h(n++)]++;
  }
  for (auto &[x, y] : cnt) {
    if (y == 3) {
      cout << x << '\n';
    }
  }
}
