/* 08.02.2024 18:35:28 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int N = 1e6;
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
//  cout << prime.size() << '\n';
  cout << prime[10000] << '\n';
}
