/*************************************************************************
	> File Name: 1031.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug 10 10:20:29 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    int t = 0;
    for (int i = 0; i < n; i++) t += a[i];
    t /= n;
    vector<int> q(n + 1);
    int ans = 0;
    for (int i = 0; i < n; i++) q[i] = a[i] - t;
    for (int i = 0; i < n; i++) {
        if (q[i] == 0) continue;
        q[i + 1] += q[i];
        ans++;
    }
    cout << ans << "\n";
    return 0;
}

