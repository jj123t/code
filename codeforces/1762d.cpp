/*************************************************************************
	> File Name: 1762d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 28 13:18:41 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        queue<int> q;
        for (int i = 1; i <= n; i++) {
            q.push(i);
        }
        while (q.size() > 2) {
            int a = q.front(); q.pop();
            int b = q.front(); q.pop();
            int c = q.front(); q.pop();
            cout << "? " << a << " " << b << endl;
            int x; cin >> x;
            cout << "? " << a << " " << c << endl;
            int y; cin >> y;
            if (x == y) {
                q.push(b); q.push(c);
            }
            else if (x < y) {
                q.push(a); q.push(c);
            }
            else {
                q.push(a); q.push(b);
            }
        }
        int a = q.front(); q.pop();
        int b = q.front(); q.pop();
        cout << "!" << " " << a << " " << b << endl;
        cin >> a;
    }
    return 0;
}

