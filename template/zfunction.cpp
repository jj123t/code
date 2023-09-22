/*************************************************************************
	> File Name: zfunction.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu Sep  7 21:06:49 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> z(1e6);
void Z(string s) {
    z[0] = s.size();
    for (int i = 1, j = 1, k; i < s.size(); i = k) {
        if (j < i) j = i;
        while (j < s.size() and s[j] == s[j - i]) j++;
        z[i] = j - i, k = i + 1;
        while (k + z[k - i] < j) z[k] = z[k - i], k++;
    }
}
int main()
{
    string s, p; cin >> s >> p;
    string t = p + "$" + s;
    Z(t);
    for (int i = 0; i < t.size(); i++) {
        cout << z[i] << " ";
    }
    cout << "\n";
    //12467
    return 0;
}

