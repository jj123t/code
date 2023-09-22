/*************************************************************************
	> File Name: 1219.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 17 19:03:34 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int cnt = 3;
vector<int> x(50), y(50), dig(50);
vector<int> p(50);
int ans = 0;
int n;
void dfs(int idx) {
    if (idx > n) {
        if (cnt) {
            for (int i = 1; i <= n; i++) {
                cout << p[i] << " ";
            }
            cout << "\n";
            cnt--;
        }
        ans++;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (!x[i] and !y[i + idx] and !dig[n + i - idx]) {
            x[i] = y[i + idx] = dig[n + i - idx] = true;
            p[idx] = i;
            dfs(idx + 1);
            x[i] = y[i + idx] = dig[n + i - idx] = false;
        }
    }
}
int main()
{
    cin >> n;
    dfs(1);
    cout << ans << "\n";
    return 0;
}

