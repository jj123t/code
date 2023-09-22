#!/usr/bin/env python
# coding=utf-8
def gcd(a, b) :
    if not b : return a
    return gcd(b, a%b)
def lcm(a, b) :
    return a * b // gcd(a, b)
n, m = map(int, input().split())
res = list(map(int, input().split()))
for i in rang(n): 

LCM = 1
for x in res: LCM = lcm(x, LCM)
tmp = 0
if LCM % 2 == 0 : tmp = LCM // 2
else : tmp = LCM
ans = 0
ans += (2 * m - tmp + 2 * LCM - 1) // (2 * LCM);
print(ans)
