/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul  1 19:59:11 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> arr(8);
    for (auto &x : arr) cin >> x;
    auto brr = arr;
    sort(arr.begin(), arr.end());
    bool flag = true;
    if (arr != brr) flag = false;
    for (int i = 0; i < 8; i++) {
        if (arr[i] < 100 || arr[i] > 675 || arr[i] % 25 != 0) {
            flag = false;
        }
    }
    if (flag) cout << "Yes\n";
    else cout << "No\n";
    return 0;
}

