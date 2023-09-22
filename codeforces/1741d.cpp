/*************************************************************************
	> File Name: 1741d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 23 01:33:48 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
const int N = 1e6 + 10;
vector<int> arr(N);
int ans = 0;
bool flag = false;
void dfs(int left, int right) {
    if (left == right) return ;
    int mid = left + right >> 1;
    dfs(left, mid), dfs(mid + 1, right);
    int mia = 1e9, mxa = 0;
    for (int i = left; i <= mid; i++) {
        mia = min(mia, arr[i]);
        mxa = max(mxa, arr[i]);
    }
    int mib = 1e9, mxb = 0;
    for (int i = mid + 1; i <= right; i++) {
        mib = min(mib, arr[i]);
        mxb = max(mxb, arr[i]);
    }
    if (mia > mib) {
        if (mxb + 1 != mia || (mxb - mib) != (mxa - mia)) {
            flag = true;
        }
        ans++;
    }
    else {
        if ((mxa + 1) != mib || (mxb - mib) != (mxa - mia)) {
            flag = true;
        }
    }
}
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        for (int i = 0; i < n; i++) cin >> arr[i];
        ans = 0;
        flag = false;
        dfs(0, n - 1);
        if (flag) cout << -1 << "\n";
        else cout << ans << "\n";
    }
    return 0;
}

