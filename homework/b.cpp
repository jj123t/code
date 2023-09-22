/*************************************************************************
	> File Name: b.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Thu 27 Apr 2023 12:32:16 PM CST
 ************************************************************************/

#include<bits/stdc++.h>
using namespace std;
typedef long long ll;
vector<int> arr(100, 0);
void suffer(int n, vector<int>&vt) {
    srand(time(0));
    for (int i = 0; i < n; i++) {
        vt[i] = rand() % 2000;
    }
}
int kth_sort(int left, int right, int rnk) {
    if (left == right) return arr[left];
    int x = arr[left];
    int i = left - 1, j = right + 1;
    while (i < j) {
        do i++; while (arr[i] < x);
        do j--; while (arr[j] > x);
        if (i < j) swap(arr[i], arr[j]);
    }
    int d = j - left + 1;
    if (rnk <= d) return kth_sort(left, j, rnk);
    else return kth_sort(j + 1, right, rnk - d);
}
int main () {
    int n, k; cin >> n >> k;
    suffer(n, arr);
    auto res = arr;
    sort(res.begin(), res.begin() + n);
    for (int i = 1; i <= n; i++) cout << res[i - 1] << " \n"[i % 10 == 0];
    cout << kth_sort(0, n - 1, k) << "\n";
    return 0;
}
