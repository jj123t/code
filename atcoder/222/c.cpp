/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat May 13 18:40:57 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>
const int N =  60;
vector<string> s(N * 2);
vector<int> ans(N * 2);
bool check(char a, char b) {
        if (a == 'P' && b == 'C') return false;
        if (a == 'C' && b == 'G') return false;
        if (a == 'G' && b == 'P') return false;
        return true;
}
int main()
{
    int n, m; cin >> n >> m;
    for (int i = 0; i < 2 * n; i++) cin >> s[i];
    using P = pair<int, int>;
    vector<P> rnk(2 * n);
    for (int i = 0; i < 2 * n; i++) rnk[i].second = i;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            int x = rnk[j * 2].second;
            int y = rnk[j * 2 + 1].second;
            if (s[x][i] == s[y][i]) continue;
            if (check(s[x][i], s[y][i])) {
                rnk[j * 2].first--;
            }
            else {
                rnk[j * 2 + 1].first--;
            }
        }
        sort(rnk.begin(), rnk.end());
    }
    for (int i = 0; i < 2 * n; i++) {
        cout << rnk[i].second + 1 << "\n";
    }
    return 0;
}

