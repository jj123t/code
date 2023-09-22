/*************************************************************************
	> File Name: matrx.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed 03 May 2023 12:17:01 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
typedef vector<int> vec;
typedef vector<vec> mat;
const int M = 10000;
mat mul(mat &A, mat &B) {
    mat C(A.size(), vec(B[0].size()));
    for (int i = 0; i < A.size(); i++) {
        for (int k = 0; k < B.size(); k++) {
            for (int j = 0; j < B[0].size(); j++) {
                C[i][j] += A[i][k] * B[k][j];
            }
        }
    }
    return C;
}
mat pow(mat A, ll n) {
    mat B(A.size(), vec(A.size()));
    for (int i = 0; i < A.size(); i++) {
        B[i][i] = 1;
    }
    while (n) {
        if (n & 1) B = mul(B, A);
        A = mul(A, A);
        n >>= 1;
    }
    return B;
}
int main () {
    return 0;
}
