/*************************************************************************
	> File Name: 1772e.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Tue Jul 11 13:32:42 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int n; cin >> n;
        vector<int> arr(n);
        for (int i = 0; i < n; i++) cin >> arr[i];
        int a = 0, b = 0, c = 0;
        for (int i = 0; i < n; i++) {
            if (arr[i] != (i + 1)) a++;
            if (arr[i] != (n - i)) b++;
            if (arr[i] != (i + 1) and (arr[i] != (n - i))) c++;
        }
        if (a + c <= b) cout << "First\n";
        else if (b + c < a) cout << "Second\n";
        else cout << "Tie\n";
    }
    return 0;
}
 
