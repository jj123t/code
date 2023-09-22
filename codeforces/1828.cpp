/*************************************************************************
	> File Name: 1828.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Jul  6 16:38:30 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        vector<int> p;
        for (int i = 0; i < n; i++) {
            p.push_back(abs(i + 1 - arr[i]));
        }
        int g = p[0];
        for (int i = 0; i < p.size(); i++) g = gcd(g, p[i]); 
        cout << g << '\n';
    }
    return 0;
}

