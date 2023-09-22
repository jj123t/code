/*************************************************************************
	> File Name: 1657b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Sep  5 22:08:33 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, B, x, y; cin >> n >> B >> x >> y;
        vector<int> arr(n + 1);
        int s = 0;
        for (int i = 1; i <= n; i++) {
            if (arr[i - 1] + x > B) {
                arr[i] = arr[i - 1] - y;
            }
            else {
                arr[i] = arr[i - 1] + x;
            }
            s += arr[i];
        }
        cout << s << "\n";
    }
    return 0;
}

