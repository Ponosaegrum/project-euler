mx = -1;
for a in range(1, 100):
    for b in range(1, 100):
        c = a**b;
        s = str(c);
        sm = 0;
        for d in s:
            sm += int(d);
        if (sm > mx):
            mx = sm;
print(mx);
