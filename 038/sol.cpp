/* Ponosaegrum 17.02.2024 15:16:36 */

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

  string mx = "000000000";
  for (int i = 1; i <= 100000000; ++i) {
    string s;
    s += to_string(i);
    for (int j = 2; j <= 9; ++j) {
      s += to_string(j * i);
      if ((int) s.size() > 9) {
        break;
      }
      if ((int) s.size() == 9) {
//        debug(s);
        vector<bool> used(10);
        for (char k : s) {
          used[k - '0'] = true;
        }
        if (!used[0]) {
          bool good = true;
          for (int k = 1; k <= 9; ++k) {
            if (!used[k]) {
              good = false;
              break;
            }
          }
          if (good) {
            mx = max(mx, s);
          }
        }
      }
    }
  }
  cout << mx << '\n';
}
