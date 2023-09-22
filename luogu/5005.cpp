/*************************************************************************
	> File Name: 5005.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug  5 20:36:52 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int p = 1e9 + 7;
int dp[5][100][100];
bool check1(int x, int y) {
	for(int i = 0 ; 1 << i <= x ; i++) {
		if(!(x & (1 << i))) continue ;
		if(i > 1) {
			if(!(!(y & (1 << i - 2)) || ((x & (1 << i - 1)) && (y & (1 << i - 1))))) return 1 ;
		}
		if(!(!(y & (1 << i + 2)) || ((x & (1 << i + 1)) && (y & (1 << i + 1))))) return  1;
	}
	return 0 ;
}
bool check2(int len, int x, int y, int z) {
	for(int i = 0 ; 1 << i <= x ; i++) {
		if(!(x & (1 << i))) continue ;
		if(i > 0) {
			if(!(!(z & (1 << i - 1)) || ((y & (1 << i)) && (y & (1 << i - 1))))) return 1 ;
		}
		if(!(!(z & (1 << i + 1)) || ((y & (1 << i)) && (y & (1 << i + 1))))) return 1 ;
	}
	return 0;
}

signed main()
{
    int x, y; cin >> x >> y;
    swap(x, y);
    for (int i = 0; i < (1 << x); i++) dp[1][i][0] = 1;
    for (int i = 0; i < (1 << x); i++) {
        for (int j = 0; j < (1 << x); j++) {
            if (check1(i, j)) continue;
            dp[0][i][j] += dp[1][j][0];
            dp[0][i][j] %= p;
        }
    }
    for (int i = 3; i <= y; i++) {
        memset(dp[(i - 2 + 2) % 2], 0, sizeof(dp[(i - 2 + 2) % 2]));
        for (int now = 0; now < (1 << x); now++) {
            for (int last = 0; last < (1 << x); last++) {
                if (check1(now, last)) continue;
                for (int pre = 0; pre < (1 << x); pre++) {
                    if (check2(x, now, last, pre)) continue;
                    dp[i % 2][now][last] += dp[(i - 1 + 2) % 2][last][pre];
                    dp[i % 2][now][last] %= p;
                }
            }
        }
    }
    int ans = 0;
    for (int now = 0; now < (1 << x); now++) {
        for (int last = 0; last < (1 << x); last++) {
            if (check1(now, last)) continue;
            ans += dp[y % 2][now][last];
            ans %= p;
        }
    }
    cout << ans << "\n";
    return 0;
}

