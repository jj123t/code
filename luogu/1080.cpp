/*************************************************************************
	> File Name: 1080.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 16 21:23:07 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int A[1000];
void plus(string a) {
    reverse(a.begin(), a.end());
    int flag = 0;
    for (int i = 0; i < a.size(); i++) {
        A[i] = (flag + (A[i] + (a[i] - '0'))) % 10;
        flag = ((A[i] + (a[i] - '0'))) / 10;
    }
    int i = a.size();
    while(flag) {
        A[i] = (A[i] + flag) % 10;
        flag = (A[i++] + flag) / 10;
    }
}
string mul(string a, string b) {
    reverse(b.begin(), b.end());
    for (int i = 0, string res = ""; i < b.size(); i++, res += "0") {
        string tmp = a;
        for (auto &x : tmp) {
            x *= b[i];
        }
        tmp = tmp + res;
        plus(tmp);
    }
    string ans = "";
    int i = 0;
    while (A[i]) {
        ans += A[i++];
    }
    return ans;
}
string div(string a, string b) {

}
int main()
{
    int n; cin >> n;
    vector<pair<string, string>> arr(n);
    string A, B; cin >> A >> B;
    for (auto &[x, y] : arr) cin >> x >> y;
    sort(arr.begin(), arr.end(), [&](pair<string, string> a, pair<string, string> b) {
         return mul(a.first * a.second) < mul(b.first * b.second);
         });
    string ans = 0;
    string tmp = A;
    for (auto [x, y] : arr) {
        ans = max(ans, tmp / y);
        tmp = mul(tmp, x);
    }
    cout << ans;
    return 0;
}
