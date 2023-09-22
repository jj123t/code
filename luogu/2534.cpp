/*************************************************************************
  > File Name: 2534.cpp
  > Author:123emm 
  > Mail: 2542142016@qq.com
  > Created Time: Sat Sep  2 18:01:14 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;

int n;
vector<int> C;
int get() {
    int res = 0;
    for (int i = 1; i <= n; i++) {
        if (abs(C[i + 1] - C[i]) != 1) {
            res++;
        }
    }
    return res;
}
bool ok = false;
void dfs(int step, int dep, int pre) {
    if (ok) return ;
    int x = get();
    if (step + x > dep) return ;
    if (x == 0) {
        ok = true;
        return ;
    }
    for (int i = 1; i <= n; i++) {
        if (i == pre) continue;
        reverse(C.begin() + 1, C.begin() + i + 1);
        dfs(step + 1, dep, i);
        reverse(C.begin() + 1, C.begin() + i + 1);
    }
}
int main()
{
    cin >> n;
    vector<int> arr(n + 1);
    for (int i = 1; i <= n; i++) {
        cin >> arr[i];
    }

    auto f = arr;
    sort(f.begin() + 1, f.begin() + n + 1);
    for (int i = 1; i <= n; i++) arr[i] = lower_bound(f.begin() + 1, f.begin() + n + 1, arr[i]) - f.begin();

    C = arr;
    C.push_back(n + 1);

    for (int i = 0; i < 20; i++) {
        ok = false;
        dfs(0, i, 0);
        if (ok) {
            cout << i << "\n";
            return 0; 
        }
    }
    return 0;
}

