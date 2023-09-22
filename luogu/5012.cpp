/*************************************************************************
	> File Name: 5012.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 24 19:58:56 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e6;
vector<int> par(N), siz(N);
void init(int n) {
    for (int i = 1; i <= n; i++) par[i] = i, siz[i] = 1;
}
int Find(int x) {
    if (x == par[x]) return x;
    return par[x] = Find(par[x]);
}
void Unite(int x, int y) {
    int a = Find(x), b = Find(y);
    siz[a] += siz[b];
    par[b] = a;
}
bool Same(int x, int y) {
    return Find(x) == Find(y);
}
signed main() 
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int n, m; cin >> n >> m;
    vector<int> vis(n + 1);
    init(n);
    vector<int> arr(n + 2);
    for (int i = 1; i <= n; i++) cin >> arr[i];
    arr[0] = arr[n + 1] = 1e9;
    auto brr = arr;
    sort(brr.begin() + 1, brr.end());
    map<int, vector<int>> index;
    for (int i = 1; i <= n; i++) index[arr[i]].push_back(i);
    int sz = 0, sum = 0;
    vector<int> res(n + 1);
    vector<int> ord(n + 1);
    vector<int> w(n + 1);
    for (auto [x, y] : index) {
        for (auto idx : y) {
            int a = idx - 1;
            int b = idx + 1;
            int sza = siz[Find(a)];
            int szb = siz[Find(b)];
            if (vis[a] and vis[b]) {
                if (arr[a] <= x and arr[b] <= x) {
                    sum -= sza * sza + szb * szb;
                    Unite(a, idx); Unite(b, idx);
                    sum += siz[Find(idx)] * siz[Find(idx)];
                    sz--;
                } 
                else if (arr[a] > x and arr[b] > x) sz++, sum++;
                else if (arr[a] <= x) {
                    sum -= sza * sza;
                    Unite(a, idx);
                    sum += siz[Find(idx)] * siz[Find(idx)];
                }
                else if (arr[b] <= x) {
                    sum -= szb * szb;
                    Unite(b, idx);
                    sum += siz[Find(idx)] * siz[Find(idx)];
                }
            }
            else if (vis[a]) {
                if (arr[a] <= x) {
                    sum -= sza * sza;
                    Unite(a, idx);
                    sum += siz[Find(idx)] * siz[Find(idx)];
                }
                else sz++, sum++;
            }
            else if (vis[b]) {
                if (arr[b] <= x) {
                    sum -= szb * szb;
                    Unite(b, idx);
                    sum += siz[Find(idx)] * siz[Find(idx)];
                }
                else sz++, sum++;
            }
            else {
                sz++, sum++;
            }
            vis[idx] = true;
        }
        //cout << "w is " << x << " " << sz << " and " << sum / x << "\n";
        if (x != 0 and sum > res[sz] * x) {
            res[sz] = sum / x;
            ord[sz] = sum;
            w[sz] = x;
        }
        //res[sz] = max(res[sz], sum);
    }
    /*
    cout << "\n";
    for (int i = 1; i <= 20; i++) {
        cout << res[i] << " ";
    }
    cout << "\n";
    cout << "\n";
    */
    auto compare = [&](int a, int b) -> int {
        if (res[a] == res[b]) {
            return a;
        }
        else {
            if (res[a] < res[b]) {
                return b;
            }
            else {
                return a;
            }
        }
    };
    vector<vector<int>> st(1e4, vector<int>(30, 0));
    for (int i = 1; i <= n; i++) st[i][0] = i;
    for (int j = 1; j <= log(n); j++) {
        for (int i = 1; i + (1 << (j - 1)) - 1 <= n; i++) {
            st[i][j] = compare(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
    auto get = [&](int l, int r) -> int {
        int x = log(r - l + 1);
        return compare(st[l][x], st[r - (1 << x) + 1][x]);
    };
    int lastans = 0;
    for (int i = 0; i < m; i++) {
        int a, b, x, y; cin >> a >> b >> x >> y;
        int l = (a * lastans + x - 1) % n + 1;
        int r = (b * lastans + y - 1) % n + 1;
        if (l > r) swap(l, r);
        int d = get(l, r);
        int ans1 = ord[d];
        int ans2 = w[d];
        if (ans2 == 0) {
            cout << -1 << " " << -1 << "\n";
            lastans = 1;
        }
        else {
            cout << ans1 << " " << ans2 << "\n";
            lastans = ans1 * res[d];
        }
        cout << l << " " << r << " " << lastans % n << "\n";
       // cout << "\n";
    }
    return 0;
}
