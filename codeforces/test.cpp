#include <bits/stdc++.h>

#define itn int
#define all(x) (x).begin(), (x).end()
#define make_unique(x) sort(all((x))); (x).resize(unique(all((x))) - (x).begin())

using namespace std;

inline int nxt() {
	int x;
	cin >> x;
	return x;
}

const int N = 1'111'111;
vector<int> a[N];

void remove_par(int v, int p) {
	if (auto it = find(all(a[v]), p); it != a[v].end()) {
		a[v].erase(it);
	}
	for (int x : a[v]) {
		remove_par(x, v);
	}
}

int h[N];

map<vector<int>, int> cache;

int get(const vector<int>& v) {
	if (auto it = cache.find(v); it == cache.end()) {
		int x = cache.size();
		cache[v] = x;
		return x;
	} else {
		return it->second;
	}
}

void find_hashes(int v) {
	vector<int> sons;
	for (int x : a[v]) {
		find_hashes(x);
		sons.push_back(h[x]);
	}
	sort(all(sons));
	h[v] = get(sons);
}

vector<int> trees[228];

void solve() {
	int n = nxt();
	for (int i = 0; i < n - 1; ++i) {
		int u = nxt() - 1, v = nxt() - 1;
		a[u].push_back(v);
		a[v].push_back(u);
	}
	remove_par(0, 0);
	find_hashes(0);
	const auto S = cache;

	vector<int> vec;
	auto rec = [&](auto self, vector<int>& where, int rem, int cur, int i, vector<int>& v) {
		if (rem == 0) {
			auto u = v;
			sort(all(u));
			if (!S.count(u)) {
				vec = u;
				return true;
			}
			where.push_back(get(u));
			return false;
		}
		if (rem < cur) {
			cur = rem;
			i = 0;
		}
		while (cur > 0 && i >= (int)trees[cur].size()) {
			cur -= 1;
			i = 0;
		}
		if (cur <= 0) {
			return false;
		}
		v.push_back(trees[cur][i]);
		if (self(self, where, rem - cur, cur, i, v)) {
			return true;
		}
		v.pop_back();
		if (self(self, where, rem, cur, i + 1, v)) {
			return true;
		}
		return false;
	};

	trees[1] = {0};
	for (int i = 2; i <= n; ++i) {
		vector<int> tmp;
		if (rec(rec, trees[i], i - 1, i - 1, 0, tmp)) {
			break;
		}
	}
	if (vec.empty()) {
		assert(n == 2);
		cout << "1 2\n";
		return;
	}
	
	map<int, vector<int>> inv;
	for (auto [k, v] : cache) {
		inv[v] = k;
	}
	
	vector<vector<int>> our_tree(1);
	function<void(int, vector<int>)> build = [&](int v, vector<int> sons) {
		for (int x : sons) {
			int sz = our_tree.size();
			our_tree[v].push_back(sz);
			our_tree.push_back({});
			build(sz, inv.at(x));
		}
	};
	build(0, vec);
	int from = n - our_tree.size();
	for (int i = 0; i < from; ++i) {
		cout << i + 1 << " " << i + 2 << "\n";
	}
	for (int i = 0; i < (int)our_tree.size(); ++i) {
		for (int j : our_tree[i]) {
			cout << from + 1 + i << " " << from + 1 + j << "\n";
		}
	}
}

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int t = 1; // nxt();
	while (t--) {
		solve();
	}

	return 0;
}

