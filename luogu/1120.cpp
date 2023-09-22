/*************************************************************************
	> File Name: 1120.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Sep  1 15:45:39 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int n;
vector<int> arr(1e6);
bool ans = false;
vector<int> a;
void dfs(int idx) {
    if (idx == n + 1) {
        ans = true;
        return ;
    }
    for (int i = 0; i < a.size(); i++) {
        if (a[i] >= arr[idx]) {
            a[i] -= arr[idx];
            dfs(idx + 1);
            a[i] += arr[idx];
        }
    }
}
int main()
{
    cin >> n;
    for (int i = 1; i <= n; i++) cin >> arr[i];
    sort(arr.begin() + 1, arr.begin() + n + 1);
    int s = 0;
    int mx = 0;
    for (int i = 1; i <= n; i++) s += arr[i], mx = max(mx, arr[i]);
    for (int i = mx; i <= s / 2; i++) {
        if (s % i == 0) {
            int lim = i, sz = s / i;
            ans = false;
            a.resize(sz, lim);
            dfs(1);
            if (ans) {
                cout << lim << '\n';
                return 0;
            }
        }
    }
    return 0;
}

