/*************************************************************************
	> File Name: 3279.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Sep 15 21:20:06 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6;
int par[N];
void init(int n) {
    for (int i = 1; i <= n; i++) par[i] = i;
}
int Find(int x) {
    if (par[x] == x) return x;
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
    int n; cin >> n;
    vector<int> odd(n + 1);
    for (int i = 1; i <= n; i++) cin >> odd[i];
    vector<int> even(n + 1);
    for (int i = 1; i <= n - 1; i++) cin >> even[i];
    vector<int> res(2, 0);
    for (int i = 1; i <= n; i++) {
        res.push_back(odd[i] / 2);
        res.push_back(even[i] / 2);
    }
    res.push_back(0);
    n = res.size();
    init(n);
    vector<int> f(n + 1);
    int maxright = 0, mid = 0;
    for (int i = 1; i < n; i++) {
        if (i < maxright) f[i] = min(f[mid * 2 - i], maxright - i);
        else f[i] = 1;
        while (res[i] - 2 * f[i] + 1 >= 0) {
            Unite(f[i] - i, f[i] + i);
            f[i]++;
            res[i]--;
        }
        if (f[i] + i > maxright) {
            maxright = f[i] + i;
            mid = i;
        }
    }
    for (int i = 1; i <= n; i++)  cout  << Find(i) << " ";
    cout << "\n";
    char c = 'a' - 1;
    map<int, char> mp;
    string s = "";
    for (int i = 1; i <= n; i++) {
        int x = Find(i);
        if (!mp[x]) mp[x] = ++c;
        s += mp[x];
    }
    cout << s << "\n";
    return 0;
}

