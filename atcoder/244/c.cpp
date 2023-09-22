/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 28 15:13:33 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    int k = 2 * n + 1;
    map<int, bool> mp; 
    queue<int> q;
    for (int i = 0; i < k; i++) {
        q.push(i + 1);
    }
    while (!q.empty()) {
        while (mp[q.front()]) {
            q.pop();
        }
        cout << q.front() << endl;
        q.pop();
        int x; cin >> x;
        if (x == 0) break;
        mp[x] = true;
    }
    return 0;
}

