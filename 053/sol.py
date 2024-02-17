import math
cnt = 0;
for n in range(1, 101):
    for k in range(1, n + 1):
        if (math.comb(n, k) > 1000000):
            cnt += 1;
print(cnt);
