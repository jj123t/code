#!/usr/bin/env python
# coding=utf-8
#!/usr/bin/env python
# coding=utf-8
n, m = map(int, input().split())
arr = list(map(int, input().split()))
vis = {}
tmp = 0
res = 0
for i in range(m) :
    if not res in vis:
        vis[res] = True;
        tmp += arr[res]
        res = (res + arr[res]) % n
        res = res % n
    else :
        tmp = m / i * tmp
        print(m % i)
        for j in range(0, m % i) :
            tmp += arr[res]
            res = (res + arr[res]) % n
            res = res % n
        break
print(tmp)

