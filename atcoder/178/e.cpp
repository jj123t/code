/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon 17 Apr 2023 07:19:45 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    int n; cin >> n;
    using P = pair<int, int>;
    vector<int> z, w;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        z.push_back(x + y);
        w.push_back(x - y);
    }
    cout << max(*max_element(z.begin(), z.end())-*min_element(z.begin(), z.end()), *max_element(w.begin(), w.end()) - *min_element(w.begin(), w.end()));
    return 0;
}
