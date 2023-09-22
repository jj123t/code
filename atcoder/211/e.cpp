/*************************************************************************
	> File Name: e.cpp
	> Author: abcemm
	> Mail: 2542142016@qq.com 
	> Created Time: Sun May  7 02:56:28 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 10;
vector<string> s(N);
int n;
using P = pair<int, int>;
int dx[4] = {0, 1, 0, -1};
int dy[4] = {1, 0, -1, 0};
bool check(int x, int y) {
    return !(x < 0 || x >= n || y < 0 || y >= n);
}
int ans;
set<vector<string>> vis;
void dfs(int k) {
    if (vis.find(s) != vis.end()) return;
    vis.insert(s);
    if (k == 0) {
        ans++;
        return;
    }
    vector<P> res;
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '.') {
                bool flag = false;
                for (int z = 0; z < 4; z++) {
                    int tx = i + dx[z];
                    int ty = j + dy[z];
                    if (check(tx, ty) && s[tx][ty] == '@') flag = true;
                    if (flag) res.push_back(P(i, j));
                }
            }
        }
    }
    for (auto [a, b] : res) {
        s[a][b] = '@';
        dfs(k - 1);
        s[a][b] = '.';
    }
}
signed main() {
    int k; cin >> n >> k;
    for (int i = 0; i < n; i++) cin >> s[i];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            if (s[i][j] == '.') {
                s[i][j] = '@';
                dfs(k - 1);
                s[i][j] = '.';
            }
        }
    }
    cout << ans;
    return 0;
}

