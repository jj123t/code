/*************************************************************************
  > File Name: 1657c.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Tue Sep  5 22:13:19 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        string s; cin >> s;
        int l = 0; 
        int ans = 0;
        while (l + 1 < n) {
            if (s[l] == '(' or (s[l] == ')' and s[l + 1] == ')')) {
                l += 2;
            }
            else {
                int r = l + 1;
                while (r < n and s[r] != ')') {
                    r++;
                }
                if (r == n) break;
                l = r + 1;
            }
            ans++;
        }
        cout << ans << " " << n - l << '\n';
    }
    return 0;
}
