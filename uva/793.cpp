/*************************************************************************
	> File Name: 793.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Sep  5 21:25:31 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> par(1e6 + 10);
void init(int n) {
    for (int i = 1; i <= n; i++) par[i] = i;
}
int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}
void Unite(int x, int y) {
    par[Find(x)] = Find(y);
}
bool Same(int x, int y) {
    return Find(x) == Find(y);
}
int main()
{
    int tt; cin >> tt;
    string op; char s; int u, v;
    while(tt--){
        int ans1 = 0, ans2 = 0;
        if(!getline(cin, op) || op.empty()) break;
        sscanf(op.c_str(), "%c%d%d", &s, &u, &v);
        if (s == 'c') {
            Unite(u, v);
        }
        else {
            if (Same(u, v)) ans1++;
            else ans2++;
        }
        cout << ans1 << " " << ans2 << "\n";
        if (tt--) cout << "";
    }
    return 0;
}

