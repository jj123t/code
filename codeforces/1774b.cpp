/*************************************************************************
	> File Name: 1774b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul  4 11:34:08 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, m, k; cin >> n >> m >> k;
        vector<int> arr(m);
        for (int i = 0; i < m; i++) cin >> arr[i];
        bool flag = true;
        int cnt = 0;
        for (int i = 0; i < m; i++) {
            if (arr[i] > n / k) {
                if (arr[i] > n / k + 1) flag = false;
                else cnt++;
            }
        }
        if (!flag or cnt > n % k) cout << "NO\n";
        else cout << "YES\n";
    }
    return 0;
}
