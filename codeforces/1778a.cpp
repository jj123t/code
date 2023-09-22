/*************************************************************************
	> File Name: 1778a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 14 20:40:50 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        int last = 0;
        int s = 0;
        bool one = false, two = false, three = false;
        for (int i = 0; i < n; i++) {
            int x; cin >> x;
            s += x;
            if (last == -1 and x == -1) one = true; 
            else if (last == 1 and x == 1) three = true;
            else if (last * x == -1)two = true;
            last = x;
        } 
        if (one) s += 4;
        else if (two) ;
        else s -= 4;
        cout << s << "\n";
    }
    return 0;
}

