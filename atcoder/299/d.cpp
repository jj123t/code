/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat 22 Apr 2023 07:52:33 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
int ans = 0;
void  dfs(int left, int right, int valleft, int valright) {
    if (right - left == 1) {
        ans = left;
        return ;
    }
    int mid = left + right >> 1;
    cout <<  "?" << mid << endl;
    int valmid; cin >> valmid;
    if (valmid == valleft && valmid == valright) {
        dfs(left, mid, valleft, valmid);
        dfs(mid, right, valmid, valright);
    }
    else if (valmid == valleft) {
        dfs(mid, right, valmid, valright);
    }
    else {
        dfs(left, mid, valleft, valmid);
    }
}
int main () {
    int n; cin >> n;
    cout << "? 1" << endl;
    int l; cin >> l;
    cout << "?" << " " << n << endl;
    int r; cin >> r;
    dfs(1, n, l, r);
    cout << "!" << ans << endl;
    return 0;
}
