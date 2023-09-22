/*************************************************************************
	> File Name: 1288.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug  4 14:21:27 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<int> arr(n);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i - 1];
    }
    int a = 0;
    while (arr[a] != 0) a++;
    int b = n - 1;
    while (arr[b] != 0) b--;
    b = (n - 1) - b;
    if ((a & 1) or (b & 1)) {
        cout << "YES\n";
    }
    else {
        cout << "NO\n";
    }
    return 0;
}

