/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 10 03:40:25 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    using P = pair<int, int>;
    set<P> st;
    queue<P> q;
    int tt; cin >> tt;
    int type = 1;
    int cnt = 0;
    while (tt--) {
        int op; cin >> op;
        if (op == 1) {
            int x; cin >> x;
            q.push({x, ++cnt});
        }
        else if (op == 2) {
            if (q.empty()) {
                cout << (*st.begin()).first << '\n';
                st.erase(st.begin());
                continue;
            }
            if (st.empty()) {
                cout << q.front().first << '\n';
                q.pop();
                continue;
            }
            if (q.front().second < (*st.begin()).second) {
                cout << q.front().first << '\n';
                q.pop();
            }
            else {
                cout << (*st.begin()).first << '\n';
                st.erase(st.begin());
            }
        }
        else {
            while (!q.empty()) {
                st.insert(q.front());
                q.pop();
            }
        }
    }
    return 0;
}

