/*************************************************************************
	> File Name: 1762b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 28 06:02:37 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<pair<int, int>> arr(n);
        for (int i = 0; i < n; i++) {
            cin >> arr[i].first;
            arr[i].second = i + 1;
        }
        sort(arr.begin(), arr.end());
        vector<pair<int, int>> t; 
        for (int i = 1; i < n; i++) {
            if (arr[i].first % arr[i - 1].first != 0) {
                int d = arr[i].first % arr[i - 1].first;
                t.emplace_back(arr[i].second, arr[i - 1].first - d);
                arr[i].first += arr[i - 1].first - d;
            }
        }
        cout << t.size() << "\n";
        for (auto [x, y] : t) cout << x << " " << y << "\n";
    }
        
    return 0;
}

