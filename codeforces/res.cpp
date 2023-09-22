/*************************************************************************
	> File Name: res.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jun 29 23:38:07 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string s;
vector<int> arr(11, 0), brr(11, 0);
bool check(string a, string b) {
    int i = 0, j = 0;
    for (i = 0; i < b.size(); i++) {
        while (j < a.size() && a[j] != b[i]) {
            j++;
        }
        if (j >= a.size()) return false;
        j++;
    }
    return true;
}
map<string, vector<string, int>> dp[12][2][2][2];
bool tmp = false;
int dfs(int idx, int lima, int limb, int lead, string t) {
    if (tmp) return 1;
    if (idx == 0) {
        if (!check(s, t)) {
           // cout << t << "\n";
           tmp = true;
            return 1;
        }
        else {
            return 0;
        }
    }
    if (dp[idx][lima][limb][lead][s][t] != 0) return dp[idx][lima][limb][lead][s][t] == -1 ? 0 : dp[idx][lima][limb][lead][s][t];
    int la = arr[idx];
    int lb = brr[idx];
    int ans = 0;
    for (int i = la; i <= lb; i++) {
       // cout << la << " " << lb << "\n";
         ans |= dfs(idx - 1, lima && i == la, limb && i == lb, lead && i == '0', t + (char)('0' + i));
    }
    return dp[idx][lima][limb][lead][s][t] = (ans == 0 ? -1 : ans);
}
int solve(string l, string r) {
    reverse(l.begin(), l.end());
    reverse(r.begin(), r.end());
    //cout << l << " " << r << "\n";
    fill(arr.begin(), arr.end(), 0);
    fill(brr.begin(), brr.end(), 0);
    int i = 0;
    int cnt = 0;
    while (i < l.size()) {
        arr[++cnt] = l[i] - '0';
        i++;
    }
    i = 0;
    cnt = 0;
    while (i < r.size()) {
        brr[++cnt] = r[i] - '0';
        i++;
    }
    //cout << cnt << "\n";
     dfs(cnt, 1, 1, 1, "");
     return tmp;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        cin >> s;
        int m; cin >> m;
        /*
        for (int i = 0; i <= m; i++) {
            for (int j = 0; j < 2; j++) {
                for (int k = 0; k <2 ; k++) {
                    for (int l = 0; l <2 ; l++) {
                        dp[i][j][k][l].clear();
                    }
                }
            }
        }
        */
        tmp = false;
        string l, r; cin >> l >> r;
        int d = solve(l, r);
        if (d) cout << "YES\n";
        else cout <<"NO\n";
    }
    return 0;
}

