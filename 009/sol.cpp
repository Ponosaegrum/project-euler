/* 08.02.2024 18:39:59 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int N = 1000;
  for (int a=1; a<=N; a++) {
    for (int b=1; b<=N-b; b++) {
      int c = N-a-b;
      if (b>=c) {
        break;
      }
      if (a*a + b*b == c*c) {
        cerr << a << " " << b << " " << c << '\n';
        cout << a*b*c << '\n';
        return 0;
      }
    }
  }
}
