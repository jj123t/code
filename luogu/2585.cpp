/*************************************************************************
	> File Name: 2585.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 31 17:46:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
void dfs(int u) {
    if (s[u] == '0') {
        dp1[u][0] = dp2[u][0] = 1;
        return ;
    }
    dfs(++cnt);
    if (s[u] == '1') {
        dp1[u][0] = min(dp1[u + 1][1], dp1[u + 1][2]) + 1;
        dp1[u][1] = min(dp1[u + 1][0], dp1[u + 1][2]);
        dp1[u][2] = min(dp1[u + 1][0], dp1[u + 1][1]);

        dp2[u][0] = max(dp2[u + 1][1], dp2[u + 1][2]) + 1;
        dp2[u][1] = max(dp2[u + 1][0], dp2[u + 1][2]);
        dp2[u][2] = max(dp2[u + 1][0], dp2[u + 1][1]);
    }
    else if (s[u] == '2') {
        int v = ++cnt;
        dfs(v);
        dp1[u][0] = min(dp1[])
    }
}
int main()
{
    cin >> s;
    return 0;
}

