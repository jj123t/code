/*************************************************************************
	> File Name: 1857c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug  7 22:19:07 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int m = n * (n - 1) / 2;
        vector<int> arr(m + 1);
        for (int i = 1; i <= m; i++) cin >> arr[i];
        priority_queue<int, vector<int>, greater<int>> q;
        for (int i = 1;  i<= m; i++) q.push(arr[i]);
        vector<int> res;
        while (!q.empty()) {
            auto a = q.top();
            for (int i = 0; i < n - res.size() - 1; i++) {
                q.pop();
            }
            res.push_back(a);
        }
        res.push_back(res.back());
        for (auto x : res) cout << x << " ";
        cout << "\n";
    }
    return 0;
}

