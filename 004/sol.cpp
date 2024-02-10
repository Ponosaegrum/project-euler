/* 08.02.2024 18:05:27 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  auto ispalindrome = [&](int x) {
    string s = to_string(x);
    int n = s.size();
    for (int i=0; i<n/2; i++) {
      if (s[i] != s[n-i-1]) {
        return false;
      }
    }
    return true;
  };
  int mx = -1;
  for (int i=100; i<1000; i++) {
    for (int j=100; j<1000; j++) {
      int cur = i*j;
      if (ispalindrome(cur)) {
        mx = max(mx, cur);
      }
    }
  }
  cout << mx << '\n';
}
