/*************************************************************************
	> File Name: 3812gauss.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug 12 21:51:42 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
const double eps = 1e-8;
using vec = vector<int>;
using mat = vector<vec>;
vec gauss_jordan(mat& A, const vec& b) {
    int n = A.size();
    mat B(n, vec(A[0].size() + 1));
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < A[0].size(); j++) {
            B[i][j] = A[i][j];
        }
    }
    for (int i = 0; i < n; i++) B[i][A[0].size()] = b[i];

    for (int i = 0; i < n; i++) {
        int pivot = i;
        for (int j = i; j < A[0].size(); j++) {
            if (abs(B[j][i]) > abs(B[pivot][i])) {
                pivot = j;
            }
        }
        swap(B[i], B[pivot]);

        if (abs(B[i][i]) < 0) return vec();

        for (int j = i + 1; j <= A[0].size(); j++) if (B[i][i] != 0) B[i][j] /= B[i][i];
        for (int j = 0; j < n; j++) {
            if (i != j) {
                for (int k = i + 1; k <= A[0].size(); k++) {
                    B[j][k] -= B[j][i] * B[i][k];
                }
            }
        }
    }
    vec x(n);
    for (int i = 0; i < n; i++) x[i] = B[i][n];
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < A[0].size(); j++) {
            A[i][j] = B[i][j];
        }
    }
    return x;
}
signed main()
{
    int n; cin >> n;
    mat A = mat(n, vec(52));
    for (int i = 0; i < n; i++) {
        int x; cin >> x;
        for (int j = 0; j < 52; j++) {
            if (x >> j & 1) {
                A[i][j] = 1;
            }
        }
    }
    vec b = vec(n, 0);
    gauss_jordan(A, b);
    for (auto x : A) {
        for (auto y : x) {
            cout << y << " ";
        }
        cout << "\n";
    }
    int ans = 0;
    for (int i = 0; i < n; i++) {
        int res = 0;
        for (int j = 0; j < 52; j++) {
            if (A[i][j] == 1) {
                res += (1 << j);
            }
        }
        ans ^= res;
    }
    cout << ans << "\n";
    return 0;
}

