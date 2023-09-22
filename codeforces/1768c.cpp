/*************************************************************************
	> File Name: 1768c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul  6 11:03:01 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        vector<int> vis(n + 1, false);
        vector<int> a(n + 1), b(n + 1);
        bool flag = true;
        for (int i = 1; i <= n; i++) {
            if (!vis[arr[i]]) a[i] = arr[i], vis[arr[i]]++;
            else if (vis[arr[i]] == 1) b[i] = arr[i], vis[arr[i]]++; 
            else {
                flag = false;
            }
        }
        vector<int> visa(n + 1), visb(n + 1);
        for (int i = 1; i <= n; i++) visa[a[i]]++;
        for (int i = 1; i <= n; i++) visb[b[i]]++;
        set<int> hasa, hasb;
        for (int i = 1; i <= n; i++) if (!visa[i]) hasa.insert(i);
        for (int i = 1; i <= n; i++) if (!visb[i]) hasb.insert(i);
        for (int i = 1; i <= n; i++) {
            if (!a[i] && b[i]) {
                auto it = hasa.lower_bound(b[i]);
                if (it == hasa.end() or (*it) != b[i]) --it;
                a[i] = *it; hasa.erase(it);
            }
            else if (!b[i] && a[i]) {
                auto it = hasb.lower_bound(a[i]);
                if (it == hasb.end() or (*it) != a[i]) --it;
                b[i] =*it; hasb.erase(it);
            }
        }
        for (int i = 1; i <= n; i++) {
            if (max(a[i], b[i]) != arr[i] || !a[i] || !b[i]) {
                flag = false;
            }
        }
        if (!flag) cout << "NO\n";
        else {
            cout << "YES\n";
            for (int i = 1; i <= n; i++) cout << a[i] << " ";
            cout << "\n";
            for (int i = 1; i <= n; i++) cout << b[i] << " ";
            cout << '\n';
        }
    }
    return 0;
}

