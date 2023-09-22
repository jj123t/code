/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul  1 20:02:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    map<string, int> mp;
    vector<string> brr(n);
    for (int i = 0; i < n; i++) {
        cin >> brr[i];
    } 
    for (int i = 0; i < m; i++) {
        string x; cin >> x;
        mp[x] = i + 1;
    }
    vector<int> arr(m + 1); 
    for (auto &x : arr) {
        cin >> x;
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        if (mp[brr[i]]) ans += arr[mp[brr[i]]];
        else ans += arr[0];
    }
    cout << ans;
    return 0;
}

