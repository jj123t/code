/*************************************************************************
	> File Name: 1168.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 24 23:38:47 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    priority_queue<int, vector<int>, greater<int>> q1;
    priority_queue<int> q2;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (i == 1) {
            q1.push(x);
            cout << x << "\n";
            continue;
        }
        if (q1.size() != q2.size()) {
            if (q1.size() < q2.size()) {
                q2.push(x);
                q1.push(q2.top());
                q2.pop();
            }
            else {
                q1.push(x);
                q2.push(q1.top());
                q1.pop();
            }
        }
        else {
            q1.push(x); 
            x = q1.top();
            q1.pop();
            q2.push(x);
            x = q2.top();
            cout << x << "\n";
        }
    }
    return 0;
}

