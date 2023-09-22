/*************************************************************************
	> File Name: 1850b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 22:28:56 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        using P = pair<int, int>;
        int n; cin >> n;
        vector<P> arr(n);
        int res = 0;
        int id = 0;
        for (int i = 0; i < n; i++) cin >> arr[i].first >> arr[i].second;
        for (int i = 0; i < n; i++) {
            if (arr[i].first <= 10 && arr[i].second > res) {
                res = arr[i].second;
                id = i + 1;
            }
        }
        cout << id << "\n";
    }
    return 0;
}

