#!/usr/bin/env python
# coding=utf-8
#!/usr/bin/env python
# coding=utf-8
M = 1e9 + 7;
def mypow(a, b) :
    res = 1
    while b:
        if b % 2 == 1: res = res * a % M
        a = a * a % M
        b //= 2
    return res % M
fac = [ 0 for _ in range(200100)]
for i in range(1, 200010) :
    fac[i] = (fac[i - 1] + mypow(2, i)) % M
t = int(input())
for _ in range(t) :
    n, m = map(int, input().split())
    s = str(input())
    a = [ 0 for _ in range(n + 1)]
    b = [ 0 for _ in range(n + 1)]
    for i in range(1, n + 1) :
        if s[i - 1] == '1' :
            a[i] = a[i - 1] + 1
        else : 
            a[i] = a[i - 1]
        if s[i - 1] == '0' :
            b[i] = b[i - 1] + 1
        else :
            b[i] = b[i - 1]

    Hash = [0 for _ in range(n + 1)]
    for i in range(1, n + 1):
        if (s[i - 1] == '1') : 
            Hash[i] = (Hash[i - 1] + mypow(2, i) % M) % M
        else :
            Hash[i] = (Hash[i - 1]) % M
    st = set()
    for i in range(1, m + 1) :
        l, r = map(int,input().split())
        zero = b[r] - b[l - 1]
        one = a[r] - a[l - 1]
        res = (fac[r] - fac[l + zero - 1] + 2 * M) % M
        xa = Hash[l - 1] % M
        xb = (Hash[n] - Hash[r] + 2 * M) % M
        xc = (xa + xb) % M
        tmp = (res +xc) % M
        st.add(tmp)
    print(len(st))

