#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    vector<int> vis(2000000, false);
    for (int i = 2; i <= 1000010; i++) {
        if (!vis[i]) ;
        for (int j = 2 * i; j <= 1000010; j += i) {
            vis[j] = true;
        }
    }
    vis[1] = true;
    while (tt--) {
        int n; cin >> n;
        if (n == 1) cout << 1 << "\n";
        else if (n == 2) cout << 2 << " " << 1 << "\n";
        else if (n == 3) cout << 2 << " " << 1 << " " << 3 << "\n";
        else {
            vector<int> r1, r2, t1, t2;
            for (int i = 4; i <= n; i++) {
                if (!vis[i]) {
                    if (r1.size() < r2.size()) r1.push_back(i);
                    else r2.push_back(i);
                }
                else {
                    if (t1.size() < t2.size()) t1.push_back(i);
                    else t2.push_back(i);
                }
            }
            for (auto x : r2) cout << x << " ";
            cout << 2 << " ";
            for (auto x : t1) cout << x << " ";
            cout << 1 << " ";
            for (auto x : t2) cout << x << " ";
            cout << 3 << " ";
            for (auto x : r1) cout << x << " " ;
            cout << "\n";
        }
    }
    return 0;
}

