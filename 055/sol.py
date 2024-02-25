import math

ans = 0;

for i in range(1, 10000):
    cnt = 0;
    ok = True;
    n = i;
    while (cnt < 50):
        s_n = str(n)[::-1];
        cur = n + int(s_n);
        s_cur = str(cur);
        palindrome = True;
        m = math.floor(math.log10(cur)) + 1;
        for i in range(0, m // 2):
            if (s_cur[i] != s_cur[m - 1 - i]):
                palindrome = False;
                break;
        if (palindrome):
            ok = False;
            break;
        cnt += 1;
        n = cur;
    if (ok):
        ans += 1;

print(ans);
