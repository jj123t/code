/*************************************************************************
	> File Name: 3374.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jun 10 03:20:27 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 5e5 + 10;
int tree[N];
int n;
void add(int x, int i) {
    while (i <= n) {
        tree[i] += x;
        i += i & -i;
    }
}
int qry(int i) {
    int res = 0;
    while (i) {
        res += tree[i];
        i -= i & -i;
    }
    return res;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int m; cin >> n >> m;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        add(x, i);
    }
    while (m--) {
        int op; cin >> op;
        int x, y; cin >> x >> y;
        if (op == 1) {
            add(y, x);
        }
        else {
            cout << qry(y) - qry(x - 1) << "\n";
        }
    }
    return 0;
}

