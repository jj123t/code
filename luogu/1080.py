#!/usr/bin/env python
# coding=utf-8
#!/usr/bin/env python
# coding=utf-8

n = int(input())
res = []
A, B = map(int, input().split())
for i in range(n):
    a, b = map(int, input().split())
    res.append([a, b])
res = sorted(res, key = lambda x : x[0] * x[1]);
ans = 0
tmp = A
for i in range(n):
    ans = max(ans, tmp // res[i][1])
    tmp = tmp * res[i][0]
print(int(ans))

