/*************************************************************************
	> File Name: d.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Sun 30 Apr 2023 02:20:06 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
const int N = 1e5 + 10;
vector<int> fac(N);
void init(int n) {
    fac[0] = 1;
    for (int i = 1; i <= n; i++) {
        fac[i] = fac[i - 1] * i;
    }
}
class BIT {
    int size;
    vector<int> tree;
    public: BIT(int n) {
        size = n + 1;
        tree.resize(size);
    }
    void add(int i, int x) {
        while (i <= size) {
            tree[i] += x;
            i += i & -i;
        }
    }
    int qry(int i) {
        int tmp = 0;
        while (i >= 1) {
            tmp += tree[i];
            i -= i & -i;
        }
        return tmp;
    }
};
int Cantuo(int n, vector<int>& arr) {
    BIT* fit = new BIT(n);
    int res = 0;
    for (int i = 0; i < n; i++) {
        int x = arr[i];
        int inv = x -  1 - fit->qry(x);
        fit->add(x, 1);
        res += inv * fac[n - i - 1];
    }
    return res;
}
vector<int> invCantuo(int n, int x) {
    vector<int> arr(n);
    set<int> st;
    for (int i = 1; i <= n; i++) st.insert(i);
    for (int i = 0, idx = 0, res = n - 1; i < n; i++, idx++) {
        int q = x / fac[res];
        x %= fac[res--];
        auto it = st.begin();
        while (q--) it++;
        arr[idx] = *it;
        st.erase(it);
    }
    return arr;
}
int main () {
    cout << "输入排列大小\n";
    int n; cin >> n;
    init(n);
    cout << "输入排列\n";
    vector<int> arr(n);
    for (auto &a : arr) cin >> a;
    int x = Cantuo(n, arr);
    cout << "字典序为：" << x << "\n";
    x++;
    vector<int> brr = invCantuo(n, x);
    cout << "下一个排列是\n";
    for (auto c : brr) cout << c << " ";
    return 0;
}
