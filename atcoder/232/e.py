#!/usr/bin/env python
# coding=utf-8
#!/usr/bin/env python
# coding=utf-8
h, w, k = map(int, input().split())
p = 998244353
res = [[-1, -1], [-1, -1]]
mp = []
for i in range(k + 1) :
    mp.append(res)
def dfs(x, y, idx) :
    if x == 1 and y == 1 and idx == 0: return 1
    if idx == 0: return 0
    ans = 0
    if mp[idx][x][y] != -1 : return mp[idx][x][y]
    if y == 1 and x == 1 : 
        ans += dfs(0, 1, idx - 1) * (h - 1) % p
        ans += dfs(1, 0, idx - 1) * (w - 1) % p
    elif y == 0 and x == 1 : 
        ans += dfs(1, 0, idx - 1) * (w - 2) % p
        ans += dfs(1, 1, idx - 1)
        ans += dfs(0, 0, idx - 1) * (h - 1) % p
    elif y == 1 and x == 0:
        ans += dfs(0, 1, idx - 1) * (h - 2) % p
        ans += dfs(1, 1, idx - 1)
        ans += dfs(0, 0, idx - 1) * (w - 1) % p
    elif y == 0 and x == 0:
        ans += dfs(0, 1, idx - 1)
        ans += dfs(1, 0, idx - 1)
        ans += dfs(0, 0, idx - 1) * (h - 2) % p
        ans += dfs(0, 0, idx - 1) * (w - 2) % p
    ans = ans % p
    mp[idx][x][y] = ans;
    return ans
x1, y1, x2, y2 = map(int, input().split())
a, b = 0, 0
if x1 == x2 : a = 1
if y1 == y2 : b = 1
print(dfs(a, b, k))
        
