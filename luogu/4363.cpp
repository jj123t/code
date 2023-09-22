/*************************************************************************
	> File Name: 4363.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Sep 15 12:21:57 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n, m; cin >> n >> m;
    vector<int> grade_a(n + 1, vector<int>(m + 1));
    vector<int> grade_b(n + 1, vector<int>(m + 1));
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> grade_a[i][j];
    for (int i = 1; i <= n; i++) for (int j = 1; j <= m; j++) cin >> grade_b[i][j];
    vector<int> ok[(1 << m) + 1];
    for (int i = 0; i < (1 << m); i++) {
        for (int j = 0; j < (1 << m); j++) {

        }
    }
    vector<int> dp(n + 1);
    for (int i = 2; i <= n; i++) {
        for (int state = 0; state = (1 << m); state++) {
            if (!check1(state)) continue;
            for (int last : ok[state]) {
                for (int pre : ok[last]) 
                    dp[i][now][last] = max(dp[i][now][last], dp[i - 1][last][pre] + get[state]);
            }
        }
    }
    return 0;
}

