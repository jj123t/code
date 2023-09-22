/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat 15 Apr 2023 08:52:21 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    cin.tie(0)->sync_with_stdio(false);
    int n; cin >> n;
    vector a(n, vector<int>(n));
    vector b(n, vector<int>(n));

    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> a[i][j];
       
    for (int i = 0; i < n; i++) 
        for (int j = 0; j < n; j++)
            cin >> b[i][j];

    auto rotate = [&](vector<vector<int>> &v) {
        vector res(n, vector<int>(n));
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                res[i][j] = v[n-j-1][i];
        v = res;
    };
    int ok = 0;
    for (int z = 0; z < 4; z++) {
        int ok1 = 1;
        for (int i = 0; i < n; i++)
            for (int j = 0; j < n; j++)
                if (a[i][j] && !b[i][j])
                    ok1 = 0;
        if (ok1)
            ok = 1;
        rotate(a);
    }
    if (ok)
        cout << "Yes\n";
    else
        cout << "No\n";
    return 0;
}
