/* Ponosaegrum 25.02.2024 15:05:50 */

#include <bits/stdc++.h>
using namespace std;

#ifdef LOCAL
  #include "debug.h"
#else
  #define debug(...) 42
#endif

template <class... U>
auto create(size_t n, U&&... x)
{
  if constexpr (sizeof...(x) == 1)
    return vector(n, x...);
  else
    return vector(n, create(x...));
}

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  long long ans = 0;
  vector<int> one = {3, 3, 5, 4, 4, 3, 5, 5, 4};
  vector<int> ten = {0, 6, 6, 5, 5, 5, 7, 6, 6};
  for (int i = 1; i <= 1000; ++i) {
    if (i == 1000) {
      ans += 11;
      break;
    }
    int h = i / 100;
    int t = (i / 10) % 10;
    int d = i % 10;
    if (h != 0) {
      ans += one[h - 1] + 7;
      if (t > 0 || d > 0) {
//        debug(h, t, d);
        ans += 3;
      }
    }
    if (t != 0) {
      if (t == 1) {
        if (d == 1 || d == 2) {
          ans += 6;
        } else if (d == 3 || d == 8 || d == 9 || d == 4) {
          ans += 8;
        } else if (d == 5 || d == 6) {
          ans += 7;
        } else if (d == 7) {
          ans += 9;
        } else if (d == 0) {
          ans += 3;
        }
      } else {
        ans += ten[t - 1];
        if (d != 0) {
          ans += one[d - 1];
        }
      }
    } else {
      if (d != 0) {
        ans += one[d - 1];
      }
    }
//    debug(i, ans);
  }
  cout << ans << '\n';
}
