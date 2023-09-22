#include<bits/stdc++.h>
using namespace std;
int main()
{
    int tt; cin >> tt;
    while (tt--) {
        // crgdgbergvvber
        int x, y; cin >> x >> y;
        int d = sqrt(x * x + y * y);
        if (x == 0 and y == 0) cout << 0 << '\n';
        else if (d * d == x * x + y * y) {
            cout << 1 << '\n';
        }
        // sfergbbt
        else {
            cout << 2 << '\n';
        }
    }
    return 0;
}

