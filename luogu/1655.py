#!/usr/bin/env python
# coding=utf-8
#!/usr/bin/env python
# coding=utf-8
s = [[0] * 202 for _ in range(202)]
for i in range(1, 101):
    s[i][i] = s[i][1] = 1
    for j in range(2, i):
        s[i][j] = s[i - 1][j - 1] + j * s[i - 1][j]
while True:
    try:
        n, m = map(int, input().split())
        print(s[n][m])
    except EOFError:
        break

