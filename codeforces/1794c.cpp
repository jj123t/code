/*************************************************************************
	> File Name: 1794c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul  6 11:34:15 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        priority_queue<int> q;
        priority_queue<int, vector<int>, greater<int>> p;
        int idx = 0;
        for (int i = 1; i <= n; i++) {
            if (!p.empty() and arr[i] > p.top()) {
                q.push(p.top()); p.pop();
                p.push(arr[i]);
            }
            else {
                q.push(arr[i]);
            }
            while (!q.empty() && q.top() >= idx + 1) {
                idx++;
                p.push(q.top());
                q.pop();
            }
            cout << idx << " ";
        }
        cout << "\n";
    }
    return 0;
}

