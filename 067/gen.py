cnt = 0;
file = open('0067_triangle.txt', 'r');
lines = file.readlines();

for l in lines:
    cur = l.strip();
    cur += ' ';
    print("g[{}] = {{".format(cnt), end='');
    cnt += 1;
    now = -1;
    for j in range(0, len(cur)):
        if (cur[j] == ' '):
            if (j == len(cur)-1):
                print("{}}};".format(now));
            else:
                print("{}, ".format(now), end='');
            now = -1;
            continue;
        _d = int(cur[j]);
        if (now == -1):
            now = _d*10;
        else:
            now += _d;

file.close()
