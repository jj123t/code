/*************************************************************************
	> File Name: 5535.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  1 17:00:57 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    long long n, k; cin >> n >> k;
    auto check = [&](long long x) -> bool {
        if (x == 1) return false; 
        if (x == 2) return true;
        for (long long i = 2; i * i <= x; i++) {
            if (x % i == 0) return false;
        }
        return true;
    };
    if (check(k + 1) and 2 * k >= n) {
        cout << 1 << "\n";
    }
    else {
        cout << 2 << "\n";
    }
    return 0;
}

