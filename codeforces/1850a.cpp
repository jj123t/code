/*************************************************************************
	> File Name: 1850a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 21 22:28:38 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        vector<int> arr(3);
        for (int i = 0; i < 3; i++) cin >> arr[i];
        sort(arr.rbegin(), arr.rend());
        if (arr[0] + arr[1] >= 10) cout << "YES\n";
        else cout << "NO\n";
    }
    return 0;
}

