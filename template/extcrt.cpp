const int N = 1e5 + 10;
int a[N], m[N];
int n;
int extgcd(int &x, int &y, int a, int b) {
    if (!b) {
        x = 1, y = 0;
        return a;
    }
    int d = extgcd(y, x, b, a % b);
    y -= a / b * x;
    return d;
}
int extcrt() {
    int A = a[1], M = m[1];
    for (int i = 2; i <= n; i++) {
        int d = gcd(M, m[i]);
        int rlc = M * m[i] / d;
        if ((a[i] - A) % d != 0) return -1;
        int t1, t2; extgcd(t1, t2, M / d, m[i] / d);
        int k1 = t1 * (a[i] - A) / d;
        A = ((A + k1 * M % rlc) + rlc) % rlc;
        M = rlc;
    }
    return A;
}
for (int i = 1; i <= n; i++) cin >> m[i] >> a[i];
cout << extcrt() << "\n";

