/* 08.02.2024 18:22:26 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  // So basically, find the difference of
  // [n(n+1)/2]^2 - n(n+1)(2n+1)/6
  // ...
  // = n(n+1)(n*(3n-1)-2) / 12
  int n = 100;
  cout << n * (n+1) * (n*(3*n-1)-2) / 12 << '\n';
}
