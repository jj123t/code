/*************************************************************************
	> File Name: p3952.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon May 29 23:18:42 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

#define int long long 
signed main()
{
    int qq; cin >> qq;
    while (qq--) {
        int n; string s; cin >> n >> s;
        int k = 0;
        if (s == "O(1)") k = 0;
        else {
            int idx = 4;
            while (isdigit(s[idx])) {
                k = k * 10 + (s[idx++] - '0');
            }
        }

        int ans = 0;
        stack<string> st;
        map<string, bool> mp;
        vector<int> res(210);
        int lev = -1;
        bool err = false;
        for (int i = 0; i < n; i++) {
            char c; cin >> c;
            if (c == 'E') {
                int tmp = 0;
                for (int j = 0; j <= lev; j++) {
                    if (res[j] == 2) tmp++;
                    if (res[j] == 0) break;
                }
                ans = max(ans, tmp);
                lev--;
                if (st.empty()) err = true;
                else {
                    mp[st.top()] = false;
                    st.pop();
                }
            }
            else {

                lev++;
                string bl, x, y; cin >> bl >> x >> y;
                st.push(bl);
                if (mp[bl]) err = true;
                else mp[bl] = true;
                int a = 0, b = 0;
                int idx = 0;

                while (isdigit(x[idx])) a = a * 10 + (x[idx++] - '0');
                idx = 0;
                while (isdigit(y[idx])) b = b * 10 + (y[idx++] - '0');

                if (a == 0 && b != 0 || a > b) res[lev] = 0;
                else if (b == 0 && a != 0) res[lev] = 2;
                else if (a <= b) res[lev] = 1;

            }
        }
        if (err || !st.empty()) cout << "ERR\n";
        else cout << (ans == k ? "Yes\n" : "No\n");
    }
    return 0;
}
