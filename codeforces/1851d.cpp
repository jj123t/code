/*************************************************************************
	> File Name: 1851d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 25 22:20:37 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n - 1; i++) cin >> arr[i];
        map<int, int> mp;
        set<int> st;
        for (int i = 1; i <= n - 1; i++) {
            st.insert(arr[i] - arr[i - 1]);
            mp[arr[i] - arr[i - 1]]++;
        }
        vector<int> ned;
        for (int i = 1; i <= n; i++) {
            if (!st.count(i)) ned.push_back(i);
        }
        //for (auto x : ned) cout << x << "\n";
        if (ned.size() == 0) {
            cout << "NO\n";
        }
        else if (ned.size() >= 3) {
            cout << "NO\n";
        }
        else if (ned.size() == 1) {
            cout << "YES\n";
        }
        else {
            bool flag = false;
            int d = ned[0] + ned[1];
            for (int i = 1; i <= n; i++) {
                if (arr[i] - arr[i - 1] == d and (arr[i] - arr[i - 1] > n or mp[arr[i] - arr[i - 1]] >= 2)) {
                    flag = true;
                }
            }
            if (flag) cout << "Yes\n";
            else cout << "No\n";
        }
    }
    return 0;
}

