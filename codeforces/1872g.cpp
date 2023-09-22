/*************************************************************************
  > File Name: 1872g.cpp
  > Author:123emm
  > Mail: 2542142016@qq.com
  > Created Time: Thu Sep  7 23:41:09 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0); cin.tie(0);
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        vector<int> res, id;
        for (int i = 1; i <= n; i++) cin >> arr[i];
        for (int i = 1; i <= n; i++) {
            if (arr[i] != 1) {
                res.push_back(arr[i]);
                id.push_back(i);
            }
        }
        int l = 1;
        while (l <= n and arr[l] == 1) l++;
        if (l == n + 1) {
            cout << n << " " << n << '\n';
            continue;
        }

        int tmp = 1;
        bool ok = false;
        for (auto x : res) {
            tmp *= x;
            if (tmp >= 1e8) {
                ok = true;
                break;
            }
        }
        if (ok) {
            cout << id[0] << " " << id.back() << "\n";
            continue;
        }


        int ans = 0;
        int L, R;
        vector<int> pfx(n + 1), suf(n + 2);
        for (int i = 1; i <= n; i++) {
            pfx[i] = pfx[i - 1] + arr[i];
        }
        for (int i = n; i >= 1; i--) {
            suf[i] = suf[i + 1] + arr[i];
        }
        for (int i = 0; i < res.size(); i++) {
            int rt=1;
            for (int j = i; j < res.size(); j++) {
                rt*=res[j];
                //                int rt = pfxres[j + 1];
                //                if (i != 0) rt /= pfxres[i];
                /*
                   for (int k = i; k <= j; k++) {
                   rt *= res[k];
                   }
                   */
                // cout << i << " " <<  j << " rt: " << rt << '\n';
                int idi = id[i], idj = id[j];
                // cout <<  rt + pfx[idi - 1] + suf[idj + 1] << "\n";
                if (rt + pfx[idi - 1] + suf[idj + 1] > ans) {
                    ans = rt + pfx[idi - 1] + suf[idj + 1];
                    L = idi;
                    R = idj;
                }
            }
        }
        cout << L << " " << R << "\n";
    }
    return 0;
}


