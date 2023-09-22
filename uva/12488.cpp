/*************************************************************************
  > File Name: 12488.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Sat Sep 16 19:57:13 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (cin >> n) {
        vector<int> start(n + 1), ending(n + 1);
        for (int i = 1; i <= n; i++) cin >> start[i];
        for (int i = 1; i <= n; i++) cin >> ending[i];
        map<int, int> mp;
        int weight = 1;
        for (int i = 1; i <= n; i++) {
            mp[ending[i]] = weight++;
        }
        int ans = 0;
        for (int i = 1; i <= n; i++) {
            for (int j = 1; j < i; j++) {
                if (mp[start[j]] > mp[start[i]]) {
                    ans++;
                }
            }
        }
        cout << ans << "\n";
    }
    return 0;
}

