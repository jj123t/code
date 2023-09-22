/*************************************************************************
	> File Name: 12467.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Sep  7 21:22:08 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> z(1e6 + 10);
void Z(string s) {
    string rs = s; reverse(rs.begin(), rs.end());
    s = s + "$" + rs;
    int n = s.size();
    z[0] = n;
    for (int i = 1, j = 1, k; i < n; i = k) {
        if (j < i) j = i;
        while (j < n and s[j] == s[j - i]) j++;
        z[i] = j - i, k = i + 1;
        while (k + z[k - i] < j) z[k] = z[k - i], k++;
    }
    int mx = 0;
    for (int i = 1; i < n; i++) {
        mx = max(mx, z[i]);
    }
    string t = "";
    for (int i = 0; i < mx; i++) {
        t += s[i];
    }
    reverse(t.begin(), t.end());
    cout << t << "\n";
}
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        string s; cin >> s;
        Z(s);
    }
    return 0;
}

