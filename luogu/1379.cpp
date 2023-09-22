/*************************************************************************
	> File Name: 1379.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Aug 21 09:44:10 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string ssd; cin >> ssd;
    queue<string> q;
    q.push(ssd);
    auto to_change = [&](string st) -> vector<string> {
        vector<string> res(3, "");
        for (int i = 0; i < 9; i++) {
            res[i / 3] += st[i];
        }
        return res;
    };
    auto get = [&](vector<string> res) -> string {
        string tmp = "";
        for (auto x : res) tmp += x;
        return tmp;
    };
    auto check = [&](int x, int y) -> bool {
        if (x < 0 or x >= 3 or y < 0 or y >= 3) return false;
        return true;
    };
    map<string, int> mp;
    mp[ssd] = 0;
    int dx[4] = {0, 1, 0, -1};
    int dy[4] = {1, 0, -1, 0};
    while (!q.empty()) {
        string s = q.front();
        if (s == "123804765") break;
        auto c = to_change(s); q.pop();
        int x, y;
        for (int i = 0; i < 9; i++) {
            if (s[i] == '0') {
                x = i / 3;
                y = i % 3;
            } 
        }
        for (int k = 0; k < 4; k++) {
            int nx = x + dx[k];
            int ny = y + dy[k];
            if (!check(nx, ny)) continue;
            swap(c[nx][ny], c[x][y]);
            string t = get(c);
            if (!mp[t] or mp[t] > mp[s] + 1) {
                mp[t] = mp[s] + 1;
                q.push(t);
            }
            swap(c[nx][ny], c[x][y]);
        }
    }
    cout << mp["123804765"] << '\n';
    return 0;
}

