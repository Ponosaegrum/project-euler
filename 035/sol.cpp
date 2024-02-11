/* 11.02.2024 11:44:01 */

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
  auto check = [&](int x) {
    string s = to_string(x);
    int l = log10(x)+1;
    for (int rot=0; rot<l; rot++) {
      int cur = stoi(s);
      if (!is_prime[cur]) {
        return false;
      }
      s.push_back(s[0]);
      s.erase(s.begin());
    }
    return true;
  };
  int cnt = 0;
  for (int i=0; i<(int)prime.size(); i++) {
    if (check(prime[i])) {
//      cerr << prime[i] << '\n';
      ++cnt;
    }
  }
  cout << cnt << '\n';
}
