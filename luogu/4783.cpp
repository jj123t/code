/*************************************************************************
	> File Name: 4783.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 11 19:33:00 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
using vec = vector<int>;
using mat = vector<vec>;
const int p = 1e9 + 7;
int mypow(int a, int b) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % p;
        a = a * a % p;
        b >>= 1;
    }
    return res;
}
int inv(int x) {
    return mypow(x, p - 2);
}
mat gauss_jordan(const mat& A, const vec& b) {
    int n = A.size();
    mat B(n, vec(n + n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            B[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < n; i++) {
        B[i][i + n] = 1;
    }

    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i; j < n; j++) {
            if (abs(B[j][i]) > abs(B[pivot][i])) {
                pivot = j;
            }
        }
        swap(B[i], B[pivot]);

        if (abs(B[i][i]) == 0) return mat();

        for (int j = i + 1; j < 2 * n; j++) B[i][j] = B[i][j] * inv(B[i][i]) % p;
        for (int j = 0; j < n; j++) {
            if (i != j) {
                for (int k = i + 1; k < 2 * n; k++) {
                    B[j][k] = (B[j][k] - (B[j][i] * B[i][k] % p) + p) % p;
                }
            }
        }
    }
    mat x(n, vec(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            x[i][j] = B[i][j + n];
        }
    }
    return x;
}
signed main()
{
    int n; cin >> n;
    mat A = mat(n, vec(n));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cin >> A[i][j];
        }
    }
    vec B = vec(n, 0);
    mat C = gauss_jordan(A, B);
    if (C.size() == 0) {
        cout << "No Solution\n";
        return 0;
    }
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << C[i][j] << " ";
        }
        cout << "\n";
    }
    return 0;
}

