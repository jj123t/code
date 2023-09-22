/*************************************************************************
	> File Name: 2085.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 25 12:17:38 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
struct node {
    int a, b, c, val, loc;
    node(int a, int b, int c, int loc) {
        this->a = a, this->b = b, this->c = c, this->loc = loc;
        this->val = a * loc * loc + b * loc + c;
    }
    bool operator < (const node res) const {
        return res.val < this->val;
    }
    bool operator > (const node res) const {
        return res.val > this->val;
    }
};
signed main()
{
    int n, k; cin >> n >> k;
    priority_queue<node> q;
    for (int i = 0; i < n; i++) {
        int a, b, c; cin >> a >> b >> c;
        node res = node(a, b, c, 1);
        q.push(res);
    }
    int t = 0;
    while (t < k) {
        node res = q.top(); q.pop();
        cout << res.val << " ";
        q.push(node(res.a, res.b, res.c, res.loc + 1));
        t++;
    }
    return 0;
}

