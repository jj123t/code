/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May  7 06:04:42 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n, m; cin >> n >> m;
    vector<int> a(n, 0), b[n + 1];
    auto f = [&] (int i) {
        int x = a[i];
        b[x].push_back(i);
        if (b[x].size() == 2) {
        }
    };
    return 0;
}
