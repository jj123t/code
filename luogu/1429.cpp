/*************************************************************************
	> File Name: 1429.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jun 16 22:56:51 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long
int n; 
using P = pair<int, int>;
vector<P> arr(300100);
double dis(P a, P b) {
    return (double)sqrt((a.first - b.first) * (a.first - b.first) + (a.second - b.second) * (a.second - b.second));
}
double dfs(int left, int right) {
    if (left == right) return 1000000100.0;
    else if (left + 1 == right) return dis(arr[left], arr[right]);
    int mid = left + right >> 1ll;
    double a = dfs(left, mid);
    double b = dfs(mid + 1, right);
    double ans =  min(a, b);
    vector<P> tmp; 
    for (int i = left; i <= right; i++) {
        if (abs(double(arr[mid].first - arr[i].first)) <= ans) {
            tmp.push_back(arr[i]);
        }
    }
    sort(tmp.begin(), tmp.end(), [](P x, P y) {
         return x.second < y.second;
         });
    for (int i = 0; i < tmp.size(); i++) {
        for (int j = 0; j < i; j++) {
            ans = min(ans, dis(tmp[i], tmp[j]));
        }
    }
    return ans;
}
signed main()
{
    cin >> n;
    for (int i = 0; i < n; i++) {
        int x, y; cin >> x >> y;
        arr[i] = P(x, y);
    }
    sort(arr.begin(), arr.begin() + n);
    cout << setprecision(4) << fixed ;
    cout << dfs(0, n - 1);
    return 0;
}

