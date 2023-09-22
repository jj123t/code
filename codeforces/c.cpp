/*************************************************************************
	> File Name: c.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed Aug 30 23:33:15 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n, k; cin >> n >> k;
        vector<int> arr(n + 1);
        for (int i = 0; i < n; i++)  cin >> arr[i];
        set<int> st;
        for (int i = 0; i < n; i++) st.insert(arr[i]);
        int idx = 0;
        for (int i = 0; i <= n; i++) {
            if (!st.count(i)) {
                idx = i;
                break;
            }
        }
        arr[n] = idx;
        k = k % (n + 1);
        deque<int> q;
        for (int i = 0; i <= n; i++) {
            q.push_back(arr[i]);
        }
        while (k--) {
            int t = q.back();
            q.pop_back();
            q.push_front(t);
        }
        while (n--) {
            cout << q.front() << " ";
            q.pop_front();
        }
        cout << "\n";
    }
    return 0;
}

