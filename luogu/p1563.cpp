/*************************************************************************
	> File Name: p1563.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon May 29 02:00:25 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n, m; cin >> n >> m;
    using P = pair<int, string>;
    vector<P> post(n);
    for (int i = 0; i < n; i++) {
        cin >> post[i].first >> post[i].second;
    }
    int tmp = 0;
    for (int i = 0; i < m; i++) {
        int op, x; cin >> op >> x;
        if (op == 0) {
            if (post[tmp].first == 0) {
                tmp = (tmp - x + n) % n;
            }
            else {
                tmp = (tmp + x) % n;
            }
        }
        else {
            if (post[tmp].first == 0) {
                tmp = (tmp + x) % n;
            }
            else {
                tmp = (tmp - x + n) % n;
            }
        }
    }
    cout << post[tmp].second;
    return 0;
}

