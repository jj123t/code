/*************************************************************************
	> File Name: 1792a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul  5 19:33:15 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 0; i < n; i++) cin >> arr[i];
        sort(arr.begin(), arr.begin()+ n);
        int ans = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] == 0) continue;
            else if (arr[i] == 1) {
                arr[i + 1]--;
                ans++;
            }
            else {
                ans++;
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

