/*************************************************************************
	> File Name: 1788b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 11 19:55:53 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        if (n % 2 == 0) {
            cout << n / 2 << " " << n / 2 << '\n';
        }
        else {
            vector<int> odd, even;
            int res = 1;
            while (n) {
                int x = n % 10;
                if (x & 1) odd.push_back(x * res);
                else even.push_back(x * res);
                res *= 10;
                n /= 10;
            }
            int a = 0, b = 0;
            for (auto x : even) a += x / 2, b += x / 2;
            bool flag = false;
            for (auto x : odd) {
                string s = to_string(x);
                int sz = s.size() - 1;
                int r = s[0] - '0';
                int t = (long long)(pow(10, sz));
                if (flag) {
                    a += (r / 2) * t;
                    b += (r / 2 + 1) * t;
                    flag = false;
                }
                else {
                    a += (r / 2 + 1) * t;
                    b += (r / 2) * t;
                    flag = true;
                }
            }
            cout << a << " " << b << '\n';
        }
    }
    return 0;
}

