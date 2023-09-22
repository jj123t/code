#!/usr/bin/env python
# coding=utf-8
#!/usr/bin/env python
# coding=utf-8

class node() :
    def __init__(self, val = 0, left = None, right = None) :
        self.val = val
        self.right = right
        self.left = left
n = int(input())
head = node(1, None, None)
dic = {}
dic[1] = head
for i in range(2, n + 1) :
    a, b = map(int, input().split())
    res = node(i, None, None)
    root = dic[a]
    if b == 0 : 
        if root.left : 
            res.left = root.left
            res.right = root
            root.left.right = res 
            root.left = res
        else :
            res.right = root
            root.left = res
    else :
        if root.right : 
            res.right = root.right
            res.left = root
            root.right.left = res
            root.right = res
        else :
            res.left = root
            root.right = res
    dic[a] = root
    dic[i] = res
m = int(input())
mp = {}
for i in range(m) :
    x = int(input())
    mp[x] = True
root = dic[1]
while root.left : 
    root = root.left
while root :
    if (root.val not in mp) :
        print(root.val, end = " ")
    root = root.right
