/*************************************************************************
	> File Name: a.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sat Jul 22 20:12:36 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int n ;cin >> n;
    string s; cin >> s;
    set<char> st;
    int i  =0;
    for (i = 0; i < s.size(); i++) {
        st.insert(s[i]) ;
        if (st.size() == 3) {
            break;
        }
    }
    cout << i + 1 << "\n";
    return 0;
}

