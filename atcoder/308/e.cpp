/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul  1 20:35:05 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
        if (arr[i] == 0) arr[i] = 0;
        else if (arr[i] == 1) arr[i] = 1;
        else arr[i] = 2;
    }
    string s; cin >> s;
    map<char, map<int, int>> mp;
    int ans =0 ;
    for (int i = 0; i < n; i++) {
        if (s[i] == 'X') {
            for (int j = 0; j < 8; j++) {
                mp['X'][j | (1 << arr[i])] += mp['E'][j];
            }
            for (int j = 0; j < 8; j++) {
                for (int k = 0; k <= 4; k++) {
                    if (j >> k & 1) ;
                    else {
                        ans += mp['X'][j] * k;
                        break;
                    }
                }
            }
            for (int j = 0; j < 8; j++) {
                mp['X'][j] = 0;
            }
        }
        else if (s[i] == 'E') {
            for (int j = 0; j < 8; j++) {
                mp['E'][j | (1 << arr[i])] += mp['M'][j];
            }
        }
        else {
            mp[s[i]][1 << arr[i]]++;
        }
    }
    cout << ans << "\n";
    return 0;
}

