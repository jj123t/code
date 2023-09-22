/*************************************************************************
	> File Name: 1855c1.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 22:47:40 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        using P = pair<int, int>;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        int mx = -1e9;
        int idx = 0;
        int res = 0;
        int mi = 1e9;
        for (int i = 1; i <= n; i++) {
            if (arr[i] > mx) {
                mx = arr[i];
                idx = i;
            }
            if (arr[i] < mi) {
                mi = arr[i];
                res = i;
            }
        } 
        if (mi == mx) {
            cout << 0 << "\n";
            continue;
        }
        //cout << mi << " " << mx << "\n";
        auto b = arr;
        vector<P> ans1, ans2;
        bool flag1 = false, flag2 = false;
        if (mi < 0) {
            flag1 = true;
            for (int i = 1; i <= n; i++) {
                if (arr[i] >= 0) {
                    while (arr[i] >= -arr[res]) {
                        arr[res] += arr[res];
                        ans1.push_back({res, res});
                    }
                    arr[i] += arr[res];
                    ans1.push_back({i, res});
                }
            }
            for (int i = n - 1; i >= 1; i--) {
                while (arr[i] > arr[i + 1]) {
                    ans1.push_back({i, i + 1});
                    arr[i] += arr[i + 1];
                }
            }
        }
        arr = b;
        if (mx > 0) {
            flag2 = true;
            for (int i = 1; i <= n; i++) {
                if (arr[i] <= 0) {
                    while (-arr[i] >= arr[idx]) {
                        arr[idx] += arr[idx];
                        ans2.push_back({idx, idx});
                    }
                    arr[i] += arr[idx];
                    ans2.push_back({i, idx});
                }
            }
            for (int i = 2; i <= n; i++) {
                while (arr[i] < arr[i - 1]) {
                    ans2.push_back({i, i - 1});
                    arr[i] += arr[i - 1];
                }
            }
        }
        if (flag1 and !flag2) {
            cout << ans1.size() << "\n";
            for (auto [a, b] : ans1) {
                cout << a << " " << b << "\n";
            }
        }
        else if (!flag1 and flag2) {
            cout << ans2.size() << "\n";
            for (auto [a, b] : ans2) {
                cout << a << " " << b << "\n";
            }
        }
        else {
            if (ans1.size() < ans2.size()) {
                cout << ans1.size() << "\n";
                for (auto [a, b] : ans1) {
                    cout << a << " " << b << "\n";
                }
            }
            else {
                cout << ans2.size() << "\n";
                for (auto [a, b] : ans2) {
                    cout << a << " " << b << "\n";
                }
            }
        }
    }
    return 0;
}

