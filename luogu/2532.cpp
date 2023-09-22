/*************************************************************************
	> File Name: 2532.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 11 12:43:36 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
string mul(string a, string b) {
    reverse(b.begin(), b.end());
    string ans = "0";
    auto plus = [&](string tmp) {
        int i = 0;
        string res = "";
        reverse(ans.begin(), ans.end());
        reverse(tmp.begin(), tmp.end());
        int flag = 0;
        while (i < tmp.size() && i < ans.size()) {
            int x = (ans[i] - '0' + tmp[i] - '0' + flag);
            res += (char)(x % 10 + '0');
            flag = x / 10;
            i++;
        }
        while (i < ans.size()) {
            int x = (ans[i] - '0' + flag) ;
            res += (char)(x % 10 + '0');
            flag = x / 10;
            i++;
        }
        while (i < tmp.size()) {
            int x = (tmp[i] - '0' + flag) ;
            res += (char)(x % 10 + '0');
            flag = x / 10;
            i++;
        }
        while (flag) {
            res += (char)(flag % 10 + '0');
            flag /= 10;
        }
        reverse(res.begin(), res.end());
        ans = res;

    };
    string res = "";
    for (int i = 0; i < b.size(); i++, res += "0") {
        string tmp = a;
        int x = b[i] - '0';
        reverse(tmp.begin(), tmp.end());
        int flag = 0;
        for (int i = 0; i < tmp.size(); i++) {
            int t = (tmp[i] - '0') * x + flag;
            tmp[i] = (char)(t % 10 + '0');
            flag = t / 10;
        }
        while (flag) {
            tmp += (char)(flag % 10 + '0');
            flag /= 10;
        }
        reverse(tmp.begin(), tmp.end());
        plus(tmp + res);
    }
    return ans;
}

string div(string a, int b)
{
    string ans = "";
    int d = 0;
    for (int i = 0; i < a.size(); i++) {
        ans += (char)((d * 10 + a[i] - '0') / b + '0');
        d = (d * 10 + a[i] - '0') % b;
    }
    return ans;
}


int main()
{
    int n; cin >> n;
    // 1/(n + 1) * C(2 * n, n);
    string ans = "1";
    for (int i = 2 * n; i > 2 * n - n; i--) ans = mul(ans, to_string(i));
    for (int i = 1; i <= n; i++) ans = div(ans, i);
    ans = div(ans, n + 1);
    reverse(ans.begin(), ans.end());
    while (!ans.empty() and ans.back() == '0') ans.pop_back();
    reverse(ans.begin(), ans.end());
    if (ans.empty()) ans = "0";
    cout << ans << "\n";
    return 0;
}

