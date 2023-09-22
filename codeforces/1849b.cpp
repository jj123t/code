/*************************************************************************
	> File Name: 1849b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul 27 22:24:26 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        using P = pair<int, int>;
        vector<P> arr(n + 1);
        for (int i = 1; i <= n; i++) {
            cin >> arr[i].first;
            arr[i].second = i;
        }
        sort(arr.begin() + 1, arr.end(), [&](P a, P b) {
             int x = a.first % k;
             int y = b.first % k;
             if (x == 0) x += k;
             if (y == 0) y += k;
             if (x == y) return a.second < b.second;
             else return x > y;
             });
        for (int i = 1; i <= n; i++) cout << arr[i].second << " ";
        cout << "\n";
    }
    return 0;
}

