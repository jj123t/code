/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 15 19:55:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n, m; cin >> n >> m;
    using P = pair<int, set<int>> ;
    vector<P> arr(n);
    for (int i = 0; i < n; i++) {
        int p, c; cin >> p >> c;
        arr[i].first = p;
        for (int j = 0; j < c; j++) {
            int x; cin >> x;
            arr[i].second.insert(x);
        }
    }
    sort(arr.rbegin(), arr.rend());
    bool ok = false;
    for (int i = 0; i < n; i++) {
        int c = arr[i].first;
        for (int j = 0; j < n; j++) {
            if (j == i) continue;
            if (arr[j].first > c) continue;
            bool flag = true;
            for (auto x : arr[i].second) {
                if (!arr[j].second.count(x)) flag = false;
            }
            if (arr[i].second.size() == arr[j].second.size() and arr[j].first == c) flag = false;
            if (flag) {
                ok = true;
                break;
            }
        }
        if (ok) break;
    }
    if (ok) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

