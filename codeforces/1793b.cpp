/*************************************************************************
	> File Name: 1793b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 11 14:13:27 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int a, b; cin >> a >> b;
        if (a > 0 and b > 0) {
            if (a - b == 1) cout << 2 << "\n" << a << " " << b << "\n";
            else {
                vector<int> ans;
                for (int i = a; i > b; i--) {
                    ans.push_back(i);
                }
                for (int i = b; i < a; i++) {
                    ans.push_back(i);
                }
                cout << ans.size() << "\n";
                for (auto x : ans) cout << x << " ";
                cout << "\n";
            }
        }
        else if (a < 0 and b < 0) {
            if (abs(a - b) == 1) cout << 2 << "\n" << a << " " << b << "\n";
            else {
                vector<int> ans;
                for (int i = a; i > b; i--) {
                    ans.push_back(i);
                }
                for (int i = b; i < a; i++) {
                    ans.push_back(i);
                }
                cout << ans.size() << "\n";
                for (auto x : ans) cout << x << " ";
                cout << "\n";
            }
        }
        else {
            vector<int> ans;
            for (int i = 0; i < a; i++) {
                ans.push_back(0);
                ans.push_back(1);
            }
            for (int i = 0; i < abs(b); i++) {
                ans.push_back(0);
                ans.push_back(-1);
            }
            cout << ans.size() << "\n";
            for (auto x : ans) cout << x << " ";
            cout << "\n";
        }
    }
    return 0;
}

