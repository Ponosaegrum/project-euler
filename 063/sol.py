cnt = 0;

for p in range(1, 100 + 1):
    b = 1;
    while (True):
        cur = str(b ** p);
        if (len(cur) == p):
            cnt += 1;
        elif (len(cur) > p):
            break;
        b += 1;

print(cnt);
