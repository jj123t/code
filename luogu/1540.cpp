/*************************************************************************
	> File Name: 1540.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 25 19:48:18 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m, n; cin >> m >> n;
    queue<int> q;
    map<int, int> mp;
    int ans = 0;
    for (int i = 1; i <= n; i++) {
        int x; cin >> x;
        if (q.size() > m) {
            mp[q.front()] = false;
            q.pop();
        }
        if (!mp[x]) {
            mp[x] = true;
            q.push(x);
            ans++;
        }
    }
    cout << ans << "\n";
    return 0;
}

