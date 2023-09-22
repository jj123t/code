#include <cstdio>
#include <iostream>
#include <queue>
#include <cstring>

typedef long long ll;

const int inf = 0x3f3f3f3f;

using namespace std;

int n, m, cnt, elast[3005], dis[3005], d[3005], num[3005];
bool vis[3005];

struct edge {
	int to, len, next;
} e[9005];

queue<int> q;

void add (int u, int v, int w) {
	e[++cnt].to = v;
	e[cnt].len = w;
	e[cnt].next = elast[u];
	elast[u] = cnt;
}

bool spfa (int x) {
	dis[x] = 0;
	q.push(x);
	vis[x] = true;
	num[x]++;
	while (!q.empty()) {
		int u = q.front();
		q.pop();
		vis[u] = false;
		for (int i = elast[u]; i != 0; i = e[i].next)
			if (dis[e[i].to] > dis[u] + e[i].len) {
				dis[e[i].to] = dis[u] + e[i].len;
				if (!vis[e[i].to]) {
					q.push(e[i].to);
					vis[e[i].to] = true;
					num[e[i].to]++;
					if (num[e[i].to] == n + 1)
						return false;
				}
			}
	}
	return true;
}

struct ybmq {
	int dis, id;
} bjhz[3005];

bool operator < (ybmq x, ybmq y) {
	return x.dis > y.dis;
}

void dijkstra (int x) {
	priority_queue<ybmq> pq;
	d[x] = 0;
	ybmq u;
	u.dis = 0;
	u.id = x;
	pq.push(u);
	while (!pq.empty()) {
		ybmq u = pq.top();
		pq.pop();
		if (vis[u.id])
			continue;
		vis[u.id] = true;
		for (int i = elast[u.id]; i != 0; i = e[i].next)
			if (d[e[i].to] > d[u.id] + e[i].len) {
				d[e[i].to] = d[u.id] + e[i].len;
				ybmq v;
				v.dis = d[e[i].to];
				v.id = e[i].to;
				pq.push(v);
			}
	}
}

int main () {
	memset(dis, inf, sizeof(dis));
	scanf("%d %d", &n, &m);
	for (int i = 1; i <= m; i++) {
		int u, v, w;
		scanf("%d %d %d", &u, &v, &w);
		add(u, v, w);
	}
	for (int i = 1; i <= n; i++)
		add(n + 1, i, 0);
	bool flag = spfa(n + 1);
    for (int i = 0; i <= n + 1; i++) {
        cout << dis[i] << " ";
    }
    cout << '\n';
	if (!flag) {
		puts("-1");
		return 0;
	}
	for (int i = 1; i <= n; i++)
		for (int j = elast[i]; j != 0; j = e[j].next)
			e[j].len += dis[i] - dis[e[j].to];
	for (int i = 1; i <= n; i++) {
		memset(d, inf, sizeof(d));
		memset(vis, false, sizeof(vis));
		dijkstra(i);
		ll ans = 0;
		for (int j = 1; j <= n; j++) {
			if (d[j] == inf)
				ans += 1ll * 1e9 * j;
			else
				ans += 1ll * (d[j] - dis[i] + dis[j]) * j;
		}
		printf("%lld\n", ans);
	}
	return 0;
}
