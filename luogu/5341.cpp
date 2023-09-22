/*************************************************************************
  > File Name: 5341.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Sat Sep  9 20:58:58 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 2e5 + 1000;
string s; 
int n, M, tax[N], rnk[N], sa[N], height[N], tp[N], cnt[N], q[N];
void Qsort() {
    for (int i = 1; i <= M; i++) tax[i] = 0; 
    for (int i = 1; i <= n; i++) tax[rnk[i]]++;
    for (int i = 1; i <= M; i++) tax[i] += tax[i - 1];
    for (int i = n; i >= 1; i--) sa[tax[rnk[tp[i]]]--] = tp[i];
}
void SA() {
    M = 122;
    for (int i = 1; i <= n; i++) rnk[i] = s[i] - 'a' + 1, tp[i] = i;
    Qsort();
    for (int w = 1, p = 0; p < n; M = p, w *= 2) {
        p = 0;
        for (int i = 1; i <= w; i++) tp[++p] = n - w + i;
        for (int i = 1; i <= n; i++) if (sa[i] > w) tp[++p] = sa[i] - w;
        Qsort();
        swap(tp, rnk);
        rnk[sa[1]] = p = 1;
        for (int i = 2; i <= n; i++) {
            rnk[sa[i]] = (tp[sa[i]] == tp[sa[i - 1]] and tp[sa[i] + w] == tp[sa[i - 1] + w]) ? p : ++p; 
        }
    }
}
void LCP() {
    for (int i = 1, k = 0; i <= n; i++) {
        if (rnk[i] == 0) continue;
        if (k) --k;
        while (s[i + k] == s[sa[rnk[i] - 1] + k]) k++;
        height[rnk[i]] = k;
    }
}
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        memset(cnt, 0, sizeof cnt);
        memset(height, 0, sizeof height);
        memset(tp, 0, sizeof tp);
        memset(rnk, 0, sizeof rnk);
        memset(sa, 0, sizeof sa);
        memset(q, 0, sizeof q);
        int k;
        cin >> s; cin >> k;
        n = s.size();
        s = " " + s;
        SA();
        LCP();
        int l = 1, r = 0;
        for (int i = 1; i <= k; i++) {
            while (l <= r and height[q[r]] >= height[i]) r--;
            q[++r] = i;
        }
        for (int i = k; i <= n; i++) {
            if (i - q[l] + 1 >= k) l++;
            while (l <= r and height[q[r]] >= height[i]) r--;
            q[++r] = i;
            int R;
            if (k == 1) R = n - sa[i + k - 1] + 1;
            else R = height[q[l]];
            int L = max(height[i - k + 1], height[i + 1]);
            if (L < R) {
                cnt[L + 1]++;
                cnt[R + 1]--;
            }
        }
        int sum = cnt[0], mx = 1, idx = -1;
        for (int i = 1; i <= n; i++) {
            sum += cnt[i];
            if (sum >= mx) {
                mx = sum;
                idx = i;
            }
        }
        cout << idx << "\n";
      }
    return 0;
}

