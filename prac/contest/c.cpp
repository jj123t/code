/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue May  9 05:28:24 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int tt; cin >> tt;
    while (tt--) {
        int m, n; cin >> m >> n;
        vector<int> three;
        int one = 0, two = 0;
        bool flag = false;
        for (int i = 0; i < m; i++) {
            int x; cin >> x;
            if (x == -1) one++;
            else if (x == -2) two++;
            else three.push_back(x);
            if (x == 1) flag = true;
        }
        int ans = 0;
        ans = min(n, max(one + two, 0));
        sort(three.begin(), three.end());
        three.erase(unique(three.begin(), three.end()), three.end());
        ans = min(n, max(one + (int)three.size(), two + (int)three.size()));
        for (int i = 0; i < three.size(); i++) {
            int x = three[i];
            int leftcan = min(one, x);
            int rightcan = min(two, n - x);
            auto itl = lower_bound(three.begin(), three.end(), x - leftcan);
            auto itr = lower_bound(three.begin(), three.end(), x + rightcan);
            int a = itl - three.begin();
            int b = three.size() - (itr - three.begin()) - 1;
            a = max(a, 0);
            b = max(b, 0);
            //cout << x << " " << leftcan << " " << rightcan << "\n";
            //cout << a << " " << b << "\n";
            int res = a + b + (leftcan + rightcan + 1);
            if (!flag && (n - x < two) && (x > one)) {
                res++;
            }
            ans = max(ans, res);
        }
        cout << ans << "\n";
    }
    return 0;
}
