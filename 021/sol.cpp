/* 09.02.2024 22:05:56 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  auto d = [&](int x) {
    set<int> t;
    for (int i=1; i<=sqrt(x); i++) {
      if (x%i == 0) {
        t.insert(i);
        if (i != 1) {
          t.insert(x / i);
        }
      }
    }
    int sm = 0;
    for (int cur : t) {
      sm += cur;
    }
    return sm;
  };
  const int N = 10000;
  set<int> s;
  for (int a=1; a<N; a++) {
    int b = d(a);
    cerr << "[a, b]: " << a << " " << b << '\n';
    if (d(b)==a && a!=b) {
      s.insert(a);
      s.insert(b);
    }
  }
  long long sm = 0;
  for (int x : s) {
    sm += x;
  }
  cout << sm << '\n';
}
