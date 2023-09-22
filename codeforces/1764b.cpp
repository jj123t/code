/*************************************************************************
	> File Name: 1764b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul  2 21:02:57 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        int x = arr[0];
        if (arr[0] == 1) x = 1;
        for (int i = 1; i < n; i++) {
            x = gcd(x, arr[i]);
        }
        cout << (arr[n - 1] / x) << "\n";
    }
    return 0;
}

