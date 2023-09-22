/*************************************************************************
	> File Name: 1861c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug 31 22:07:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        int n = s.size();
        int res = 0;
        int tmp = 0;
        int t = 0;
        bool flag = true;
        int last = 0; 
        int idx = 0;
        queue<int> st;
        for (int i = 0; i < n; i++) {
            if (s[i] == '-') {
                st.push(-1);
                tmp--;
            }
            else if (s[i] == '+') {
                st.push(1);
                tmp++;
            }
            else {
                if (s[i] == '1') {
                    if (last == 1) {
                        last = 1;
                    }
                    else {
                        int tmp = 0;
                        bool ok = false;
                        while (!q.empty()) {
                            if (sz - tmp <= t) ok = true;  
                            if (q.front() == -1) tmp--;
                            else tmp++;
                            q.pop();
                        }
                        if (ok) {
                            last = 1;
                            t = n;
                        }
                        else {
                            flag = false;
                        }
                    }
                }
                else {

                }
            }
        }
        if (flag) cout << "YES\n";
        else cout << "No\n";
    }
    return 0;
}

