#!/usr/bin/env python
# coding=utf-8
#!/usr/bin/env python
# coding=utf-8

def gcd(a, b):
    if b == 0:
        return a
    return gcd(b, a % b)
tt = int(input())
for t in range(tt):
    n = int(input())
    if n % 2 == 0:
        a = [0] * n
        j = 1
        vis = [False] * (n + 1)
        for i in range(0, n, 2):
            a[i] = j
            vis[j] = True
            j += 1
        print(vis)
        for i in range(n - 1, -1, -2):
            t = a[i - 1]
            while vis[t] == True:
                t += a[i - 1]
            if (t > n): t = 1
            vis[t] = True
            a[i] = t
        print(*a)
