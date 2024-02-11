/* 11.02.2024 11:11:51 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int N = 1e6;
  vector<bool> is_prime(N+1, true);
  is_prime[0] = is_prime[1] = false;
  vector<int> prime;
  for (long long i=0; i<=N; i++) {
    if (is_prime[i]) {
      prime.emplace_back(i);
      for (long long j=i*i; j<=N; j+=i) {
        is_prime[j] = false;
      }
    }
  }
  auto f = [&](int n, int a, int b) {
    return n*n + a*n + b;
  };
  int ans = -1, mx = -1;
  for (int a=-999; a<=999; a++) {
    for (int b=-1000; b<=1000; b++) {
      int n = -1;
      while (is_prime[f(n+1, a, b)]) {
        ++n;
      }
      if (n > mx) {
        mx = n;
        ans = a*b;
      }
    }
  }
  cerr << "[ans, mx]: " << ans << " " << mx << '\n';
  cout << ans << '\n';
}
