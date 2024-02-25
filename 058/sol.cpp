/* Ponosaegrum 25.02.2024 16:58:11 */

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

  auto tl = [&](int i) {
    return 1 + 4 * (i - 1) * (i - 1);
  };
  auto tr = [&](int i) {
    return 1 + 2 * (i - 1) * (2 * i - 3);
  };
  auto bl = [&](int i) {
    return 1 + 2 * (i - 1) * (2 * i - 1);
  };
  auto br = [&](int i) {
    return 1 + 4 * i * (i - 1);
  };
  auto is_prime = [&](int x) {
    for (int i = 2; i <= sqrt(x); ++i) {
      if (x % i == 0) {
        return false;
      }
    }
    return true;
  };
  int i = 2;
  double n = 3;
  double has = 0;
  while (true) {
    has += is_prime(tl(i)) + is_prime(tr(i)) + is_prime(bl(i)) + is_prime(br(i));
    double tot = 2 * n - 1;
    double percent = (has / tot) * 100.0;
//    debug((int) n, percent);
    if (percent < 10.0) {
      cout << n << '\n';
      break;
    }
    n += 2;
    ++i;
  }
}
