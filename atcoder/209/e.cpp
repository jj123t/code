/*************************************************************************
	> File Name: re.cpp
	> Author: abcemm
	> Mail: 2542142016@qq.com 
	> Created Time: Fri May  5 23:02:38 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
const int N = 1e6 + 10;
vector<int> e[N], qry(N), ans(N, -1), in(N);
map<string, int> mp;
int main() {
	int n; cin >> n;
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		string s; cin >> s;
		int l = s.size();
		string a = s.substr(0, 3);
		if (!mp[a]) mp[a] = ++cnt;
		int x = mp[a];
		string b = s.substr(l - 3, 3);
		if (!mp[b]) mp[b] = ++cnt;
		int y = mp[b];
		in[x]++;
		e[y].push_back(x);
		qry[i] = y;
	}
	queue<int> q;
	for (int i = 1; i <= cnt; i++) {
		ans[i] = -1;
		if (!in[i]) {
			q.push(i);
			ans[i] = 0;
		}
	}
	while (!q.empty()) {
		int now = q.front(); q.pop();
		for (auto v : e[now]) {
			if (ans[v] != -1) continue;
			in[v]--;
			if (ans[now] == 0) {
				ans[v] = 1;
				q.push(v);
				continue;
			}
			if (!in[v]) {
				ans[v] = 0;
				q.push(v);
			}
		}
	}
	for (int i = 0; i < n; i++) {
		if (ans[qry[i]] == 0) cout << "Takahashi\n";
		if (ans[qry[i]] == 1) cout << "Aoki\n";
		if (ans[qry[i]] == -1) cout << "Draw\n";
	}
	return 0;
}

