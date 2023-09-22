/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue 25 Apr 2023 08:56:12 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
#define int long long 
signed main () {
    ios::sync_with_stdio(0);
    cin.tie(0); cout.tie(0);
    string s1, s2, s3; cin >> s1 >> s2 >> s3;
    set<char> st;
    for (auto c : s1) st.insert(c);
    for (auto c : s2) st.insert(c);
    for (auto c : s3) st.insert(c);
    reverse(s1.begin(), s1.end());
    reverse(s2.begin(), s2.end());
    reverse(s3.begin(), s3.end());
    if (st.size() > 10) {
        cout << "UNSOLVABLE";
        return 0;
    }
    vector<int> per(10, 0);
    iota(per.begin(), per.end(), 0);
    int m = st.size();
    do {
        vector<int> mp(26, 0);
        int cnt = 0;
        for (auto c : st) {
            mp[ll(c - 'a')] = per[cnt++];
        }
        if (mp[ll(s1.back() - 'a')] == 0 || mp[ll(s2.back() - 'a')] == 0 || mp[ll(s3.back() - 'a')] == 0) continue; 
        int res1 = 0, res2 = 0, res3 = 0;
        for (int i = 0, tmp = 1; i < s1.size(); i++, tmp *= 10) {
            res1 += mp[ll(s1[i] - 'a')] * tmp;
        }
        for (int i = 0, tmp = 1; i < s2.size(); i++, tmp *= 10) {
            res2 += mp[ll(s2[i] - 'a')] * tmp;
        }
        for (int i = 0, tmp = 1; i < s3.size(); i++, tmp *= 10) {
            res3 += mp[ll(s3[i] - 'a')] * tmp;
        }
        if (res1 + res2 == res3) {
            cout << res1 << "\n" << res2 << "\n" << res3 << "\n";
            return 0;
        }
    } while (next_permutation(per.begin(), per.end()));
    cout << "UNSOLVABLE";
    return 0;
}
