/*************************************************************************
	> File Name: 4035.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug 12 21:06:04 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const double eps = 1e-8;
using vec = vector<double>;
using mat = vector<vec>;
vec gauss_jordan(const mat& A, const vec& b) {
    int n = A.size();
    mat B(n, vec(n + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < n; i++) B[i][n] = b[i];

    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i; j < n; j++) {
            if (abs(B[j][i]) > abs(B[pivot][i])) {
                pivot = j;
            }
        }
        swap(B[i], B[pivot]);

        if (abs(B[i][i]) < eps) return vec();

        for (int j = i + 1; j <= n; j++) B[i][j] /= B[i][i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                for (int k = i + 1; k <= n; k++) {
                    B[j][k] -= B[j][i] * B[i][k];
                }
            }
        }
    }
    vec x(n);
    for (int i = 0; i < n; i++) x[i] = B[i][n];
    return x;
}
int main()
{
    int n; cin >> n;
    double t[n + 1][n];
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> t[i][j];
        }
    }
    mat A = mat(n, vec(n));
    vec b = vec(n);
    for (int i = 0; i < n; i++) {
        double res = 0;
        for (int j = 0; j < n; j++) {
            A[i][j] = 2.0 * (t[i][j] - t[i + 1][j]);
            res += (t[i][j] * t[i][j]) - (t[i + 1][j] * t[i + 1][j]);
        }
        b[i] = res;
    }
    vec ans = gauss_jordan(A, b);
    cout << setprecision(3) << fixed;
    for (auto x : ans) {
        cout << x << " ";
    }
    return 0;
}

