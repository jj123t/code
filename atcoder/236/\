/*************************************************************************
	> File Name: e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu May 18 04:43:43 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#include <iostream>

int main()
{
    int n; cin >> n;
    vector<int> a(n); 
    for (auto &x : a) cin >> x;
    {
        const double esp = 1e-9;
        auto check = [&](vector<double> b) {
            vector<double> f(2, 0);
            for (int i = 0; i < n; i++) {
                double x = f[1];
                double y = max(f[0], f[1]) + b[i];
                f[0] = x;
                f[1] = y;
            }
            if (max(f[0], f[1]) > 0) return true;
            return false;
        };
        double left = 0.0, right = 1000000000.0;
        for (int i = 0; i < 100; i++) {
            double mid = (left + right + esp) / 2.0;
            vector<double> b(n);
            for (int j = 0; j < n; j++) {
                b[j] = (double)a[j] - mid;
            }
            if (check(b)) left = mid;
            else right = mid; 
        }
        cout << setprecision(20) << fixed << left << "\n";
    }
    {
        auto check = [&](vector<int> b) {
            vector<int> f(2, 0);
            for (int i = 0; i < n; i++) {
                int x = f[1];
                int y = max(f[0], f[1]) + b[i];
                f[0] = x;
                f[1] = y;
            }
            if (max(f[0], f[1]) > 0) return true;
            return false;
        };
        int left = 0, right = 1e9;
        for (int i = 0; i < 100; i++) {
            int mid = (left + right + 1) / 2;
            vector<int> b(n);
            for (int j = 0; j < n; j++) {
                if (a[j] < mid) b[j] = -1;
                else b[j] = 1;
            }
            if (check(b)) left = mid;
            else right = mid - 1;
        }
        cout << left << "\n";
    }
    return 0;
}

