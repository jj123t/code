#!/usr/bin/env python
# coding=utf-8
#!/usr/bin/env python
# coding=utf-8

n = int(input())
num = list(map(int, input().split()))
mp = [1 for _ in range(200)]
for i in range(1, 150):
    mp[i] = mp[i - 1] * i
ans = mp[n - 2]
for x in num:
    if x == 0:
        print(0)
        exit()
    ans //= mp[x - 1]
if sum(num) - n == n - 2:
    print(ans)
else:
    print(0)
