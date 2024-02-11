/* 11.02.2024 13:25:13 */

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
  for (long long i=2; i<=N; i++) {
    if (is_prime[i]) {
      prime.emplace_back(i);
      for (long long j=i*i; j<=N; j+=i) {
        is_prime[j] = false;
      }
    }
  }
  auto rem_r = [&](int x) {
    string s = to_string(x);
    s.pop_back();
    while (!s.empty()) {
      int cur = stoi(s);
      if (!is_prime[cur]) {
        return false;
      }
      s.pop_back();
    }
    return true;
  };
  auto rem_l = [&](int x) {
    string s = to_string(x);
    s.erase(s.begin());
    while (!s.empty()) {
      int cur = stoi(s);
      if (!is_prime[cur]) {
        return false;
      } 
      s.erase(s.begin());
    }
    return true;
  };
  int n = prime.size();
  int cnt = 0;
  long long sm = 0;
  for (int i=4; i<n; i++) {
    if (rem_l(prime[i]) && rem_r(prime[i])) {
      ++cnt;
      sm += prime[i];
    }
  }
  cerr << cnt << '\n';
  cout << sm << '\n';
}
