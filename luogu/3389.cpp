/*************************************************************************
	> File Name: 3389.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 11 18:11:53 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
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
signed main()
{
    int n; cin >> n;
    mat A = mat(n, vec(n));
    vec b(n);
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
        cin >> b[i];
    }
    vec x = gauss_jordan(A, b);
    if (x.size() == 0) {
        cout << "No Solution\n";
        return 0;
    }
    cout << setprecision(2) << fixed;
    for (auto y : x) cout << y << "\n";
    return 0;
}

