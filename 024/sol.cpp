/* 10.02.2024 10:05:43 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  string s = "0123456789";
  int cnt = 0;
  do {
    ++cnt;
    if (cnt == 1e6) {
      cout << s << '\n';
      break;
    }
  } while (next_permutation(s.begin(), s.end()));
}
