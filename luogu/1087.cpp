/*************************************************************************
	> File Name: 1087.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jul 26 20:33:02 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 2000;
vector<int> pfx(N);
string s;
string dfs(int l, int r) {
    int mid = l + r >> 1;
    if (l == r) {
        if (pfx[r] - pfx[l - 1] == 1) return "I";
        else return "B";
    }
    if (pfx[r] - pfx[l - 1] == 0) {
        return dfs(l, mid) + dfs(mid + 1, r) + "B";
    }
    else if (pfx[r] - pfx[l - 1] == (r - l + 1)) {
        return dfs(l, mid) + dfs(mid + 1, r) + "I";
    }
    else {
        return dfs(l, mid) + dfs(mid + 1, r) + "F";
    }
}
int main()
{
    int n; cin >> n;
    cin >> s;
    for (int i = 1; i <= (1 << n); i++) {
        pfx[i] = pfx[i - 1] + (s[i - 1] == '1');
    }
    cout << dfs(1, (1 << n));
    return 0;
}

