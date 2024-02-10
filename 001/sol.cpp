/* 08.02.2024 17:39:46 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int n = 999; // BELOW 1000 is < 1000
  int n_3 = n/3, n_5 = n/5, n_15 = n/15;
  auto f = [&](int i) {
    return (i * (i+1)) / 2;
  };
  cout << 3*f(n_3) + 5*f(n_5) - 15*f(n_15) << '\n';
}
