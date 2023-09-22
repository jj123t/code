/*************************************************************************
	> File Name: 3045.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 25 13:47:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, k, m; cin >> n >> k >> m;
    using P = pair<int, int>;
    priority_queue<P, vector<P>, greater<P>> q1, q2;
    vector<P> arr(n + 1); 
    for (int i = 1; i <= n; i++) {
        int p, c; cin >> p >> c;
        arr[i] = P(p, c);
        q1.push(P(c, i));
    }
    int res = 0;
    while (res <= k and (!q1.empty() and m >= q1.top().first)) {
        m -= q1.top().first;
        q2.push(P(arr[q1.top().second].first - arr[q1.top().second].second, q1.top().second));
        q1.pop(); 
        res++;
    }
    while (true) {
        if (m - q2.top().first < q1.top().first) {
            break;
        }
        res++;
        m -= q2.top().first; q2.pop();
        m -= q1.top().first; q1.pop();
    }
    cout << res << "\n";
    return 0;
}

