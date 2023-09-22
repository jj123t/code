/*************************************************************************
  > File Name: 1660d.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Wed Sep  6 21:37:05 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        vector<int> odd, even;
        vector<int> zero(n + 1);
        vector<int> pfx(n + 1, 1);
        int tmp = 0;
        for (int i = 1; i <= n; i++) {
            zero[i] = zero[i - 1] + (arr[i] == 0);
            tmp += (arr[i] < 0);
            pfx[i] = pfx[i - 1] * arr[i];
            if (tmp & 1) odd.push_back(i);
            else even.push_back(i);
        }

        tmp = 0;
        for (auto l : odd) {

        }
        for (auto l : even) {

        }
    }
    return 0;
}

