/* 08.02.2024 18:09:20 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  long long l = 1;
  for (long long i=1; i<=20; i++) {
    l = lcm(l, i);
  }
  cout << l << '\n';
}
