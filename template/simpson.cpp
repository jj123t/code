double a, b, c, d;
double f(double x) {
    return (c * x + d) / (a * x + b);
}
double simpson(double l, double r) {
    double t = l + (r - l) / 2.0;
    return (f(l) + 4.0 * f(t) + f(r)) * (r - l) / 6.0;
}
double ssimpson(double A, double B, double eps, double sps) {
    double C = (A + B) * 0.5;
    double L = simpson(A, C), R = simpson(C, B);
    if (abs(L + R - sps) <= 15 * eps) return L + R + (L + R - sps) / 15;
    else return ssimpson(A, C, eps * 0.5, L) + ssimpson(C, B, eps * 0.5, R);
}
cout << fixed << setprecision(6);
cout << ssimpson(l, r, 1e-7, simpson(l, r));


