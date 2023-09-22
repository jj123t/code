/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul  1 20:13:23 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
signed main()
{
    int n; cin >> n;
    using P = pair<int, int>;
    using PP = pair<P, int>;
    vector<PP> arr(n);
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        arr[i].first = {x, y};
        arr[i].second = i + 1;
    }
    sort(arr.begin(), arr.end(), [&](PP a, PP b) {
         int x = a.first.first * (b.first.first + b.first.second);
         int y = b.first.first * (a.first.first + a.first.second);
         if (x == y) return a.second < b.second;
         else return x > y;
        });
    for (int i  =0 ; i < n; i++) {
        cout << arr[i].second << "\n";
    }
    return 0;
}

