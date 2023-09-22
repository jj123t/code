/*************************************************************************
	> File Name: rmq.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 03 May 2023 12:30:02 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int ST_SIZE = (1 << 18) - 1;
int N, M;
int A[MAX_N];
int I[MAX_M], J[MAX_M], K[MAX_M];
int nums[MAX_N];
vector<int> dat[ST_SIZE];
void init(int k, int l, int r) {
    if (r - l == 1) dat[k].push_back(A[l]);
    else {
        int lch = k * 2 + 1, rch = k * 2 + 2;
        init(lch, l, (l + r) / 2);
        init(rch, (l + r) / 2, r);
        dat[k].resize(r - 1);
        merge(dat[lch].begin(), dat[lch].end(), dat[rch].begin(), dat[rch].end(), dat[k].begin());
    }
}
int query(int i, int j, int x, int k, int l, int r) {
    if (j <= l || r <= i) return 0;
    else if (i <= l && r <= j) {
        return upper_bound(dat[k].begin(), dat[k].end(), x) - dat[k].begin();
    }
    else {
        int lc = query(i, j, x, k * 2 + 1, l, (l + r) / 2);
        int rc = query(i, j, x, k * 2 + 2, (l + r) / 2, r);
        return lc + rc;
    }
}
int main () {

    return 0;
}
