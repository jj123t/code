/*************************************************************************
	> File Name: 1020.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Mon Jul 17 19:57:51 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> arr(1001000);
int main()
{
    int n = 1;
    while (cin >> arr[n]) n++;
    n--;
    vector<int> brr(n + 1);
    int top = 1; brr[top] = arr[1];
    for (int i = 2; i <= n; i++) {
        if (brr[top] >= arr[i]) brr[++top] = arr[i];
        else *upper_bound(brr.begin() + 1, brr.begin() + top + 1, arr[i], greater<int>()) = arr[i];
    }
    int ans = 0;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        auto it = st.lower_bound(arr[i]);
        if (it == st.end()) {
            ans++;
            st.insert(arr[i]);
        }
        else {
            st.erase(it);
            st.insert(arr[i]);
        }
    }
    cout << top << " " << ans << "\n";
    return 0;
}

