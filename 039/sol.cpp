/* 11.02.2024 13:39:01 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  int ans = -1, mx = -1;
  for (int p=3; p<=1000; p++) {
    int cnt = 0;
    for (int a=1; a<=p; a++) {
      for (int b=a; b<=p-a; b++) {
        int c = p-a-b;
        if (b<=c && a*a+b*b==c*c) {
          ++cnt;
        }
      }
    }
    if (cnt > mx) {
      mx = cnt;
      ans = p;
    }
  }
  cout << ans << '\n';
}
