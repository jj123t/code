/*************************************************************************
	> File Name: 3805.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Jul 30 21:13:46 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    string t; cin >> t;
    string s = "##";
    for (auto c : t) { s += c; s += '#'; } 

    int maxright = 0, mid = 0;
    vector<int> f(s.size() + 1, 0);
    int n = s.size();

    for (int i = 1; i < n; i++) {
        if (i < maxright) {
            f[i] = min(f[mid * 2 - i], maxright - i);
        }
        else f[i] = 1;
        while (s[i + f[i]] == s[i - f[i]]) ++f[i];
        if (f[i] + i > maxright) {
            maxright = f[i] + i;
            mid = i;
        }
    }
    int ans = 1;
    for (int i = 0; i < n; i++) {
        ans = max(ans, f[i]);
    }
    cout << ans - 1 << "\n";
    return 0;
}

