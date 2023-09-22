/*************************************************************************
	> File Name: 2150.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Aug  8 14:45:18 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    vector<int> vis(550);
    vector<int> res;
    for (int i = 2; i <= 500; i++) {
        if (!vis[i]) res.push_back(i); 
        for (int j = 2 * i; j <= 500; j += i) {
            vis[j] = true;
        }
    }
    cout << res.size() << "\n";
    return 0;
}

