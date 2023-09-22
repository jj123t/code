/*************************************************************************
	> File Name: 1772c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 11 11:10:53 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int k, n; cin >> k >> n;
        vector<int> ans;
        int t = 1, d = 0 ;
        for (int i = 0; i < k; i++) {
            if (n - (t + d) + 1 >= (k - i)) {
                t += d;
                d++;
                ans.push_back(t);
                t++;
            }
            else {
                ans.push_back(t);
                t++;
            }
        }
        for (auto x : ans) cout << x << " ";
        cout << "\n";
    }
    return 0;
}

