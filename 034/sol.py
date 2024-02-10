import math

ans = 0;
for i in range(10, 1000000):
    d = str(i);
    sm = 0;
    for j in d:
        sm += math.factorial(int(j));
    if i == sm:
        ans += i;

print(ans);
