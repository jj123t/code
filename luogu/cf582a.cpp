/*************************************************************************
	> File Name: cf582a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Aug  3 16:19:48 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    map<int, int> mp;
    vector<int> arr;
    for (int i = 0; i < n * n; i++) {
        int x; cin >> x;
        mp[x]++;
        arr.push_back(x);
    }
    sort(arr.begin(), arr.end());
    arr.erase(unique(arr.begin(), arr.end()), arr.end());
    vector<int> ans;

    while (true) {
        while (arr.size() and mp[arr.back()] <= 0) {
            arr.pop_back();
        }
        if (arr.empty()) break;
        int x = arr.back();
        mp[x]--;
        for (auto y : ans) {
            mp[gcd(x, y)] -= 2;
        }
        ans.push_back(x);
    }
    for (auto x : ans) cout << x << " ";
    return 0;
}

