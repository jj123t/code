/*************************************************************************
	> File Name: 3370.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 18:30:47 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
#define int long long 
int mypow(int a, int b, int M) {
    int res = 1;
    while (b) {
        if (b & 1) res = res * a % M;
        a = a * a % M;
        b >>= 1;
    }
    return res;
}
const int B = 17;
int Hash(string s, int M) {
    int res = 0;
    for (int i = 0; i < s.size(); i++) {
        res = (res * B % M + (s[i] - 'a' + 1)) % M + 233;
    }
    return res;
}
signed main()
{
    ios::sync_with_stdio(0);
    cin.tie(0), cout.tie(0);
    const int p1 = 212370440130137957ll;
    const int p2 = 998244353;
    int n; cin >> n;
    using P = pair<int, int>;
    set<int> st;
    for (int i = 1; i <= n; i++) {
        string s; cin >> s;
            int a = Hash(s, p1);
        //int b = Hash(s, p2);
        st.insert(a);
    }
    cout << st.size() << "\n";
    return 0;
}

