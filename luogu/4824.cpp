/*************************************************************************
  > File Name: 4824.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Sat Jul 29 18:47:32 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string s, t; cin >> s >> t;
    int n = s.size(), m = t.size();
    s = " " + s; t = " " + t;
    int j = 0;
    vector<int> nxt(m + 1);
    for (int i = 2; i <= m; i++) {
        while (j and t[i] != t[j + 1]) j = nxt[j];
        if (t[i] == t[j + 1]) j++;
        nxt[i] = j;
    }
    stack<int> st;
    vector<int> f(n + 1);
    j = 0;
    for (int i = 1; i <= n; i++) {
        while (j and s[i] != t[j + 1]) j = nxt[j];
        if (s[i] == t[j + 1]) j++;
        f[i] = j;
        st.push(i);
        if (j == m) {
            int t = m;
            while (t--) { st.pop(); }
            if (!st.empty())
                j = f[st.top()];
            else 
                j = 0;
        }
    }
    string ans = "";
    while (!st.empty()) { ans += s[st.top()]; st.pop(); }
    reverse(ans.begin(), ans.end());
    cout << ans << "\n";
    return 0;
}

