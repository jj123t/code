/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun May  7 06:13:13 2023
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
 
int main () {
    int n; cin >> n;
    vector<string> a(n), b(n);
    for (auto &x : a) cin >> x;
    for (auto &x : b) cin >> x;
    {
        vector<string> c;
        string res = "";
        for (int i = 0; i < n; i++) res += ".";
        int idx1 = n - 1, idx2 = 0, idx3 = n - 1, idx4 = 0;
        for (int i = 0; i < n; i++) if (b[i] != res) { idx1 = i; break; }
        for (int i = n - 1; i > -1; i--) if (b[i] != res) { idx2 = i; break; }
        for (int i = 0; i < n; i++) {
            string tres = "";
            for (int j = 0; j < n; j++) {
                tres += b[j][i];
            }
            if (tres != res) {
                idx3 = i;
                break;
            }
        }
        for (int i = n - 1; i > -1; i--) {
            string tres = "";
            for (int j = 0; j < n; j++) {
                tres += b[j][i];
            }
            if (tres != res) {
                idx4 = i;
                break;
            }
        }
        for (int i = idx1; i <= idx2; i++) {
            string tres = "";
            for (int j = idx3; j <= idx4; j++) {
                tres += b[i][j];
            }
            c.push_back(tres);
        }
        b = c;
    }
    bool flag = false;
    for (int i = 0; i < 4; i++) {
        auto tmp = a;
        {
            vector<string> c;
            string res = "";
            for (int i = 0; i < n; i++) res += ".";
            int idx1 = n - 1, idx2 = 0, idx3 = n - 1, idx4 = 0;
            for (int i = 0; i < n; i++) if (a[i] != res) { idx1 = i; break; }
            for (int i = n - 1; i > -1; i--) if (a[i] != res) { idx2 = i; break; }
            for (int i = 0; i < n; i++) {
                string tres = "";
                for (int j = 0; j < n; j++) {
                    tres += a[j][i];
                }
                if (tres != res) {
                    idx3 = i;
                    break;
                }
            }
            for (int i = n - 1; i > -1; i--) {
                string tres = "";
                for (int j = 0; j < n; j++) {
                    tres += a[j][i];
                }
                if (tres != res) {
                    idx4 = i;
                    break;
                }
            }
            for (int i = idx1; i <= idx2; i++) {
                string tres = "";
                for (int j = idx3; j <= idx4; j++) {
                    tres += a[i][j];
                }
                c.push_back(tres);
            }
            if (c == b) flag = true;
        }
        for (int x = 0; x < n; x++) {
            for (int y = 0; y < n; y++) {
                tmp[n - 1 - y][x] = a[x][y];
            }
        }
        a = tmp;
    }
    cout << (flag ? "Yes\n" : "No\n");
    return 0;
}
