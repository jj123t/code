/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 15 19:55:27 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, p, q; cin >> n >> p >> q;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) cin >> arr[i];
    int ans = p;
    for (int i  =0; i < n; i++) {
        ans = min(ans, q + arr[i]);
    }
    cout << ans << "\n";
    return 0;
}

