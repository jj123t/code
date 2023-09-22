/*************************************************************************
	> File Name: 1762a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 28 05:50:35 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int odd = 0, even = 0;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i];
            if (arr[i] & 1) odd++;
            else even++;
        }
        if (odd % 2 == 0) {
            cout << 0 << "\n";
        }
        else {
            int ans = 1e9;
            for (int i = 0; i < n; i++) {
                if (arr[i] & 1) {
                    int cnt = 0;
                    while (arr[i] & 1) {
                        cnt++;
                        arr[i] /= 2;
                    }
                    ans = min(ans, cnt);
                }
                else {
                    int cnt = 0;
                    while (arr[i] % 2 == 0) {
                        cnt++;
                        arr[i] /= 2;
                    }
                    ans = min(ans, cnt);
                }
            }
            cout << ans << "\n";
        }
    }
    return 0;
}

