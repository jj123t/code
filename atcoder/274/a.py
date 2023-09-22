#!/usr/bin/env python
# coding=utf-8
a, b = map(int, input().split())
s = b / a
x = round(s, 3)
ans = str(x)
print('%.3f'%x)
