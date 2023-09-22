#!/usr/bin/env python
# coding=utf-8
p = 10**9 + 7
def gcd(a, b) : 
    if b == 0 : return a
    return gcd(b, a % b)
def lcm(a, b) :
    return a * b // gcd(a, b)
n = int(input())
res = list(map(int,input().split()))
LCM = 1
for x in res : LCM = lcm(x, LCM)
LCM %= p
ans = 0
for x in res : 
    ans += LCM * pow(x, p - 2, p)
    ans %= p
print(ans)
