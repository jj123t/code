/*************************************************************************
	> File Name: 4555.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Aug 11 13:20:37 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
const int N = 1e5;
vector<int> f(N);
void manacher(string t) {
    string s = "##";
    for (auto c : t) { s += c; s += '#'; }
    int n = s.size();
    int maxright = 0, mid = 0;
    for (int i = 1; i < n; i++) {
        if (i < maxright) f[i] = min(f[mid * 2 - i], maxright - i);
        else f[i] = 1;
        while (s[f[i] + i] == s[f[i] - i]) f[i]++;
        if (f[i] + i > maxright) {
            maxright = f[i] + i;
            mid = i;
        }
    }
}


int main()
{
  
    return 0;
}

