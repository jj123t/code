/*************************************************************************
	> File Name: 1837b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 21:50:55 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        vector<int> arr(1, 0);
        for (int i = 1; i < n; i++) {
            if (s[i] != s[i - 1]) {
                arr.push_back(i);
            }
        }
        arr.push_back(n);
        int ans = 0;
        int tmp = 0;
        for (int i = 1; i < arr.size(); i++) {
            //cout << arr[i] << " "<< endl;
            ans = max(tmp, ans);
            tmp = arr[i] - arr[i - 1] + 1;
        }
        ans = max(ans, tmp);
        cout << ans << "\n";
    }
    return 0;
}

