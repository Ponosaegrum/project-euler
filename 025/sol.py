dp1 = 1;
dp2 = 1;
idx = 3;
while (True):
    cur = dp1 + dp2;
    if (len(str(cur)) == 1000):
        print(idx);
        break;
    dp1, dp2 = dp2, dp1;
    dp2, cur = cur, dp2;
    idx += 1;
