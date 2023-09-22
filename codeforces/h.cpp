/*************************************************************************
	> File Name: h.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun Sep  3 20:41:47 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
struct node {
    int l, r, v;
    node(int l, int r, int v) {
        this->l = l;
        this->r = r;
        this->v = v;
    }
    bool operator < (const node a) const {
        if (a.l == this->l) return a.v < b.v; 
        else return a.l < b.l;
    }
};
int main()
{
    int n; cin >> n;
    vector<int> A(n + 1), D(n + 1);
    for (int i = 1; i <= n; i++) cin >> A[i];
    for (int i = 1; i <= n; i++) cin >> D[i];
    using P = pair<int, int>;
    priority_queue<node> q;
    for (int i = 1; i <= n; i++) {
        q.push(node(max(1, i - D[i]), min(n, i + D[i]), A[i]));
    }
    int left = 0, right = 1e9;
    auto check = [&](int mid) -> bool {
        auto t = q;
        for (int i = 1; i <= n; i++) {
            if (A[i] > mid) {

            }
        }
    };
    while (left <= right) {
        int mid = left + right >> 1;
        if (check(mid)) right = mid - 1;
        else left = mid + 1;
    }
    cout << right << "\n";
    return 0;
}

