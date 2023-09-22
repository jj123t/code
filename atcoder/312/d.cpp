/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 29 20:49:56 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int p = 998244353;
string s;
int n;
using tp = tuple<int, int, int>;
map<tp, int> dp;
int dfs(int idx, int left, int right) {
    if (idx == n + 1) {
        if (left == right) return 1;
        else return 0;
    }
    if (right > left or left > n / 2 or right > n / 2) return 0;
    if (dp[tp(idx, left, right)]  != -1) return dp[tp(idx, left, right)];
    if (s[idx - 1] == '?') {
        return dp[tp(idx, left, right)] = (dfs(idx + 1, left + 1, right) % p) + (dfs(idx + 1, left, right + 1) % p) % p;
    }
    else if (s[idx - 1] == ')') {
        return dp[tp(idx, left, right)] = dfs(idx + 1, left, right + 1) % p;
    }
    else {
        return dp[tp(idx, left, right)] =  dfs(idx + 1, left + 1, right) % p;
    }
}
signed main()
{
    cin >> s;
    n = s.size();
    cout << dfs(1, 0, 0) % p;
    return 0;
}

