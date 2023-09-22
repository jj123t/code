/*************************************************************************
	> File Name: e.cpp
	> Author: abcemm
	> Mail: 2542142016@qq.com 
	> Created Time: Sat May  6 00:04:19 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 2e5 + 10;
const int INF = 1e18;
signed main() {
	int n, m; cin >> n >> m;
	using P = pair<int, int>;
	vector<P> arr(m);
	for (auto &[a, b] : arr) cin >> a >> b;
	sort(arr.begin(), arr.end(), [&](P a, P b) {
			if (a.second == b.second) return a.first < b.first;
			return a.second < b.second;
	});
	int g = n;
	int ans = 0;
	for (int i = 0; i < n; i++) {
		int G = gcd(g, arr[i].first);
		ans += arr[i].second * (g - G);
		g = G;
	}
	if (g > 1) cout << -1;
	else cout << ans;
	return 0;
}
