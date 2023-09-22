// a * x + b * y = gcd(a, b);
// x0 = 1, y0 = 0;
// x = x0 + k * b, y = y0 - k * a;
int extgcd(int a, int b, int &x, int &y) {
    if (b == 0) {
        x = 1, y = 0;
        return a;
    }
    int d = extgcd(b, a % b, y, x);
    y -= a / b * x;
    return d;
}
