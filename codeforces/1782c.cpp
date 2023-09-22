/*************************************************************************
	> File Name: 1782c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul  5 13:14:20 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; string s; cin >> n >> s;
        map<char, int> mp;
        for (auto c : s) mp[c]++;
        int mi = 1e9, idx = 0;
        using P = pair<char, int>;
        for (int cnt = 1; cnt <= 26; cnt++) {
            if (n % cnt != 0) continue;
            int cou = n / cnt;
            int mor = 0;
            vector<int> ls;
            for (auto [x, y] : mp) {
                if (y == cou) continue;
                else if (y > cou) mor += y - cou;
                else ls.push_back(y);
            }
            if (mp.size() <= cnt) {
                if (mi > mor) mi = mor, idx = cnt;
            }
            else {
                sort(ls.begin(), ls.end());
                for (int i = 0; i < mp.size() - cnt; i++) mor += ls[i];
                if (mi > mor) mi = mor, idx = cnt;
            }
        }
        cout << mi << "\n";
        if (mp.size() <= idx) {
            vector<int> change;
            for (int i = 0; i < n; i++) {
                if (mp[s[i]] > n / idx) {
                    change.push_back(i);
                    mp[s[i]]--;
                }
            }
            for (int i = 0; i < n; i++) {
                while (mp[s[i]] < n / idx) {
                    mp[s[i]]++;
                    s[change.back()] = s[i];
                    change.pop_back();
                }
            }
            char res = 'a';
            while (!change.empty()) {
                while (mp[res] == n / idx) res++;
                while (mp[res] < n / idx) {
                    s[change.back()] = res;
                    change.pop_back();
                    mp[res]++;
                }
            }
            cout << s << "\n";
        }
        else {
            vector<pair<char, int>> ls;
            for (auto [x, y] : mp) if (y < n / idx) ls.push_back({x, y});
            sort(ls.begin(), ls.end(), [&](P a, P b){ return a.second < b.second; });
            vector<int> change;
            map<char, int> cn;
            for (int i = 0; i < mp.size() - idx; i++) cn[ls[i].first] = true;
            for (int i = 0; i < n; i++) {
                if (cn[s[i]]) {
                    change.push_back(i);
                }
                if (mp[s[i]] > n / idx) {
                    change.push_back(i);
                    mp[s[i]]--;
                }
            }
            for (int i = 0; i < n; i++) {
                while (mp[s[i]] < n / idx and !cn[s[i]]) {
                    mp[s[i]]++;
                    s[change.back()] = s[i];
                    change.pop_back();
                }
            }
            cout << s << "\n";
        }
    }
    return 0;
}
