/*************************************************************************
	> File Name: 4387.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Aug 12 20:43:17 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n + 1);
        for (int i = 1; i <= n; i++) cin >> arr[i];
        bool flag = true;
        vector<int> res(n + 1);
        for (int i = 1; i <= n; i++) cin >> res[i];
        stack<int> st;
        int j = 0;
        vector<int> vis(n + 1);
        for (int i = 1; i <= n; i++) {
            if (!vis[res[i]]) {
                while (j <= n and arr[j] != res[i]) {
                    vis[arr[j]] = true;
                    st.push(arr[j]);
                    j++;
                }
                if (j == n + 1) {
                    flag = false;
                    break;
                } 
                else {
                    j++;
                }
            }
            else {
                if (!st.empty() and st.top() == res[i]) st.pop();
                else flag = false;
            }
        }
        if (!flag) cout << "No\n";
        else cout << "Yes\n";
    }
    return 0;
}

