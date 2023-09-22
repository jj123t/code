#!/usr/bin/env python
# coding=utf-8
#!/usr/bin/env python
# coding=utf-8

tt = int(input())
for t in range(tt):
    a, b, c = map(int, input().split())
    a += (c + 1) // 2
    b += c - (c + 1) // 2
    if a > b:
        print("First")
    else :
        print("Second")
