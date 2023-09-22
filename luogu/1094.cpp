/*************************************************************************
	> File Name: 1094.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug 14 20:32:43 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int m; cin >> m;
    int n; cin >> n;
    vector<int> a(n);
    for (int i = 0; i < n; i++) cin >> a[i];
    sort(a.begin(), a.end());
    int left = 0, right = n - 1;
    int ans = 0;
    while (left <= right) {
        if (a[left] + a[right] <= m) ans += 1, left++, right--;
        else right--, ans++;
    }
    cout << ans << "\n";
    return 0;
}

