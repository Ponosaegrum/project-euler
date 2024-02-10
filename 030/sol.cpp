/* 10.02.2024 10:20:10 */

#include <bits/stdc++.h>
using namespace std;

int main()
{
  ios::sync_with_stdio(false);
  cin.tie(NULL);

  auto power = [&](int x) {
    return x * x * x * x * x;
  };
  long long sm = 0;
  for (int i1=0; i1<=9; i1++) {
    for (int i2=0; i2<=9; i2++) {
      for (int i3=0; i3<=9; i3++) {
        for (int i4=0; i4<=9; i4++) {
          for (int i5=0; i5<=9; i5++) {
            for (int i6=0; i6<=9; i6++) {
              long long num = i1*100000 + i2*10000 + i3*1000 + i4*100 + i5*10 + i6;
              long long cur = power(i1) + power(i2) + power(i3) + power(i4) + power(i5) + power(i6);
              if (num == cur) {
                sm += num;
              }
            }
          }
        }
      }
    }
  }
  cout << sm-1 << '\n';
}
