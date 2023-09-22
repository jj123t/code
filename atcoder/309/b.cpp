/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul  8 19:53:49 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n; cin >> n;
    vector<string> s(n);
    for (int i = 0; i < n; i++) cin >> s[i];
    string t = "";
    for (int i = 0; i < n; i++) t += s[0][i];
    for (int i = 1; i < n; i++) t += s[i][n - 1];
    for (int i = n - 2; i > -1; i--) t += s[n - 1][i];
    for (int i = n - 2; i > 0; i--) t += s[i][0];

    char c = t.back();
    t.pop_back();
    t = c + t;
    int cnt = 0;
    for (int i = 0; i < n; i++) s[0][i] = t[cnt++];
    for (int i = 1; i < n; i++) s[i][n - 1] = t[cnt++];
    for (int i = n - 2; i > -1; i--) s[n - 1][i] = t[cnt++];
    for (int i = n - 2; i > 0; i--) s[i][0] = t[cnt++];

    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << s[i][j] << "";
        }
        cout << "\n";
    }
    return 0;
}

