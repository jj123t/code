/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu 27 Apr 2023 01:22:34 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    if (n & 1) n++;
    vector<int> pnum(n, 0);
    iota(pnum.begin(), pnum.end(), 1);
    for (int i = 1; i < n; i++) {
        cout << "第" << i << "天比赛：";
        for (int j = 0; j < n / 2; j ++) {
            cout << pnum[j] << "and" << pnum[n - 1 - j] << " ";
        }
        cout << "\n";
        rotate(pnum.begin() + 1, pnum.begin() + 2, pnum.end());
    }
    return 0;
}
