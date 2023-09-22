/*************************************************************************
	> File Name: 2501.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 18 14:39:13 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    vector<int> brr(n + 1);
    for (int i = 1; i <= n; i++) brr[i] = arr[i] - i;
    vector<int> dp(n + 1);
    int top = 1; dp[1] = brr[1];
    for (int i = 2; i <= n; i++) {
        if (dp[top] <= brr[i]) dp[++top] = brr[i];
        else *upper_bound(dp.begin() + 1, dp.begin() + top + 1, brr[i]) = brr[i];
    }
   // cout << top << "\n";
   // for (int i = 1; i <= top; i++) cout << dp[i] << " ";
    int l = 1;
    vector<int> res;
    res.push_back(0);
    for (int i = 1, j = 1, iter = 1; i <= n, iter <= top; i++) {
        if (dp[iter] == brr[i]) {
            res.push_back(i);
            iter++;
        }
    }
    vector<int> pfx(n + 1);
    for (int i = 1; i <= n; i++) pfx[i] = pfx[i - 1] + brr[i];
    res.push_back(n + 1);
    for (int i = 0; i < res.size() - 1; i++) {
        int a = res[i], b = res[i + 1];
        for (int k = a; k <= b; k++) {
            int sa = pfx[k] - pfx[a - 1];
            int sb = pfx[b] - pfx[k - 1];
        }
    }
    return 0;
}

