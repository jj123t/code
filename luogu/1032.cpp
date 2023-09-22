/*************************************************************************
	> File Name: 1032.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Sep  1 10:27:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s, t;
using P = pair<string, string>;
set<P> mp;
int ans = 1e9;
set<string> vis;
int dep = 0;
void dfs(int idx, string tmp) {
    if (idx > dep) {
        return;
    }
    if (tmp == t) {
        ans = min(ans, idx);
        return ;
    }
    if (vis.count(tmp)) return;
    vis.insert(tmp);
    for (auto [x, y] : mp) {
        for (int i = 0; i + x.size() <= tmp.size(); i++) {
            bool t = true;
            for (int j = 0, k = i; j < x.size(); j++, k++) {
                if (x[j] != tmp[k]) {
                    t = false;
                    break;
                }
            }
            if (t) {
                string res = "";
                for (int j = 0; j < i; j++) res += tmp[j];
                res += y;
                for (int j = i + x.size(); j < tmp.size(); j++) res += tmp[j];
                dfs(idx + 1, res);
            }
        }
    }
}
int main()
{
    cin >> s >> t;
    string a = "", b = ""; 
    while (cin >> a >> b) {
        mp.insert(P(a, b));
    }
    while (ans == 1e9) {
        dfs(0, s);
        vis.clear();
        dep++;
        if (dep == 11) break;
    }
    if (ans != 1e9) cout << ans << '\n';
    else cout << "NO ANSWER!\n";
    return 0;
}

