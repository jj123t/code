/*************************************************************************
	> File Name: 10720.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Sep 19 21:20:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    while (n) {
        vector<int> d(n + 1);
        for (int i = 1; i <= n; i++) cin >> d[i];
        sort(d.begin() + 1, d.end(), [&](int a, int b) {
             return a > b;
             });
        vector<int> sum(n + 1);
        for (int i = 1; i <= n; i++) sum[i] = sum[i - 1] + d[i];
        bool flag = true;
        if (sum[n] % 2) flag = false;
        for (int i = 1; i <= n; i++) {
            int res = i * (i - 1);
            for (int j = i + 1; j <= n; j++) res += min(i, d[j]);
            if (res < sum[i]) flag = false;
        }
        if (flag) cout << "Possible\n";
        else cout << "Not possible\n";
        cin >> n;
    }
    return 0;
}

