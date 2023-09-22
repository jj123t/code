const int N = 2e5 + 10;
int st[N][30];
vector<int> arr(N, 0);
void init(int n) {
    for (int i = 1; i <= n; i++) st[i][0] = arr[i];
    for (int j = 1; j <= log(n); j++) {
        for (int i = 1; (i + (1 << (j - 1))) - 1 <= n; i++) {
            st[i][j] = min(st[i][j - 1], st[i + (1 << (j - 1))][j - 1]);
        }
    }
}
int get(int l, int r) {
    int x = log2(r - l + 1);
    return min(st[l][x], st[r - (1 << x) + 1][x]);
}
