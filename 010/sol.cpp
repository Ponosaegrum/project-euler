/* 08.02.2024 19:06:23 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int N = 2e6-1;
  vector<bool> isprime(N+1, true);
  isprime[0] = isprime[1] = false;
  vector<int> prime;
  for (long long i=2; i<=N; i++) {
    if (isprime[i]) {
      prime.emplace_back(i);
      for (long long j=i*i; j<=N; j+=i) {
        isprime[j] = false;
      }
    }
  }
  cout << accumulate(prime.begin(), prime.end(), 0ll) << '\n';
}
