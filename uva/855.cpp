/*************************************************************************
	> File Name: 855.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Sep 16 20:32:16 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int S, A, F; cin >> S >> A >> F;
        vector<int> x(F + 1), y(F + 1);
        for (int i = 1; i <= F; i++) cin >> x[i] >> y[i];
        sort(x.begin() + 1, x.end());
        sort(y.begin() + 1, y.end());
        if (F & 1) {
            cout << "(Street: " << x[(F + 1) / 2] << ", Avenue: " << y[(F + 1) / 2] << ")\n";
        }
        else {
            cout << "(Street: " << x[F / 2] << ", Avenue: " << y[F / 2] << ")\n";
        }
    }
    return 0;
}

