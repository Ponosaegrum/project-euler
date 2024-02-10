/* 10.02.2024 10:32:34 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  const int n = 1001;
  vector a(n, vector(n, -1));
  auto valid = [&](int x, int y) {
    return x>=0 && x<n && y>=0 && y<n && a[x][y]==-1;
  };
  int cur = n*n;
  int go = 0;
  vector<int> dx = {0, 1, 0, -1}, dy = {-1, 0, 1, 0};
  queue<pair<int, int>> qu;
  qu.emplace(0, n-1);
  while (!qu.empty()) {
    int x = qu.front().first;
    int y = qu.front().second;
    qu.pop();
    a[x][y] = cur--;
    bool good = true;
    int moves = 0;
    while (!valid(x+dx[go], y+dy[go])) {
      ++go;
      go %= 4;
      ++moves;
      if (moves > 4) {
        good = false;
        break;
      }
    }
    if (good) {
      qu.emplace(x+dx[go], y+dy[go]);
    }
  }
  long long sm = 0;
  for (int i=0; i<n; i++) {
    sm += a[i][i];
    sm += a[i][n-1-i];
  }
  cout << sm-1 << '\n';
}
