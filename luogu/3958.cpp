/*************************************************************************
	> File Name: 3958.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 22 12:23:31 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const int N = 1e5;
struct node {
    int x, y, z; 
    int up, low;
    int root;
}arr[N];
int h, r, n;
bool f(node a, node b) {
    int dx = a.x - b.x;
    int dy = a.y - b.y;
    int dz = a.z - b.z;
    return  dx * dx + dy * dy + dz * dz <= 4 * r * r;
}
int Find(int x) {
    if (x == arr[x].root) return x;
    return arr[x].root = Find(arr[x].root);
}
void Unite(node &x, node &y) {
    node &a = arr[Find(x.root)];
    node &b = arr[Find(y.root)];
    b.up = max(arr[Find(a.root)].up, b.up);
    b.low = min(arr[Find(a.root)].low, b.low);
    a.root = b.root;
}
bool check(node a) {
    return a.low <= 0 and a.up >= h;
}
signed main()
{
    int tt; cin >> tt;
    while (tt--) {
        cin >> n >> h >> r;
        for (int i = 1; i <= n; i++) {
            arr[i].root = i;
            arr[i].up = 0, arr[i].low = 0;
        }
        for (int i = 0; i < n; i++) {
            int x, y, z; cin >> x >> y >> z;
            arr[i].x = x, arr[i].y = y, arr[i].z = z;
            arr[i].low = z - r, arr[i].up = z + r;
            for (int j = 0; j < i; j++) {
                if (f(arr[i], arr[j])) {
                    Unite(arr[i], arr[j]);
                }
            }
        }
        bool flag = false;
        for (int i = 0; i < n; i++) {
            if (check(arr[i])) {
                flag = true;
                break;
            }
        }
        if (flag) cout << "Yes\n";
        else cout << "No\n";
    }
    return 0;
}

