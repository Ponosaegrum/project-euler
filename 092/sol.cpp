/* Ponosaegrum 25.02.2024 16:45:39 */

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

  const int N = 1e7;
  int cnt = 0;
  for (int n = 1; n <= N; ++n) {
    int cur_n = n;
    while (true) {
      int new_n = 0;
      while (cur_n) {
        int d = cur_n % 10;
        new_n += d * d;
        cur_n /= 10;
      }
      if (new_n == 1) {
        break;
      } else if (new_n == 89) {
        ++cnt;
        break;
      }
      cur_n = new_n;
    }
  }
  cout << cnt << '\n';
}
