/* 08.02.2024 17:52:15 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  long long x = 600851475143;
  const int N = 1e6;
  vector<bool> isprime(N+1, true);
  vector<int> prime;
  isprime[0] = isprime[1] = false;
  for (long long i=2; i<=N; i++) {
    if (isprime[i]) {
      prime.emplace_back(i);
      for (long long j=i*i; j<=N; j+=i) {
        isprime[j] = false;
      }
    }
  }
  int n = prime.size();
  long long mx = -1;
  for (int i=0; i<n; i++) {
    while (x%prime[i] == 0) {
      mx = max(mx, 1ll*prime[i]);
      x /= prime[i];
    }
  }
//  cerr << x << '\n';
  cout << mx << '\n';
}
