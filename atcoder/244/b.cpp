/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Jun 28 15:13:28 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    string s; cin >> s;
    int x = 0, y = 0;
    vector<int> t(4);
    int turn = 0;
    for (auto c : s) {
        if (c == 'S') {
            t[turn]++;
        }
        else {
            turn = (turn + 1) % 4;
        }
    }
    x += t[0] - t[2];
    y += -t[1] + t[3];
    cout << x << " " << y << "\n";
    return 0;
}

