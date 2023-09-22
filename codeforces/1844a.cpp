#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        int a, b; cin >> a >> b;
        if (a > b) swap(a, b);
        if (a * 2 < b) {
            cout << a * 2 << "\n";
        }
        else {
            cout << a + b << "\n";
        }
    }
    return 0;
}

