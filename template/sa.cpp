/*************************************************************************
	> File Name: 3809.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Sep  8 21:52:21 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 1000;
vector<int> s(N);
int n, M;
int sa[N], tax[N], rnk[N], tp[N], height[N];
void Qsort() {
    for (int i = 0; i <= M; i++) tax[i] = 0;
    for (int i = 1; i <= n; i++) tax[rnk[i]]++;
    for (int i = 1; i <= M; i++) tax[i] += tax[i - 1];
    for (int i = n; i >= 1; i--) sa[tax[rnk[tp[i]]]--] = tp[i];
}
void SA() {
    M = 1000010;
    for (int i = 1 ; i <= n; i++) rnk[i] = s[i], tp[i] = i;
    Qsort();
    for (int w = 1, p = 0; p < n; M = p, w <<= 1) {
        p = 0;
        for (int i = 1; i <= w; i++) tp[++p] = n - w + i;
        for (int i = 1; i <= n; i++) if (sa[i] > w) tp[++p] = sa[i] - w;
        Qsort();
        swap(tp, rnk);
        rnk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++) {
            rnk[sa[i]] = (tp[sa[i - 1]] == tp[sa[i]] and tp[sa[i - 1] + w] == tp[sa[i] + w]) ? p : ++p;
        }
    }
}
void lcp() {
    for (int i = 1, k = 0; i <= n; i++) {
        if (rnk[i] == 0) continue;
        if (k) --k;
        while (s[i + k] == s[sa[rnk[i] - 1] + k]) ++k;
        height[rnk[i]] = k;
    }
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    int k;
    cin >> n >> k;
    for (int i = 1; i <= n; i++) cin >> s[i];
    SA();
    lcp();
    auto check = [&](int mid) -> bool {
        int mx = 0;
        int last = -1;
        int cnt = 0;
        for (int i = 1; i <= n; i++) {
            if (height[i] >= mid) {
                if (last == -1 or i - last == 1) {
                    cnt++;
                    last = i;
                }
            }
            mx = max(mx, cnt);
        }
        if (mx >= k - 1) return true;
        else return false;
    };
    int left = 0, right = 2e5 + 10;
    while (left <= right) {
        int mid = left + right >> 1;
        if (check(mid)) left = mid + 1;
        else right = mid - 1;
    }
    cout << right << "\n";
    return 0;
}


