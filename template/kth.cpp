const int B = 1000;
int N = 1e5;
int M = 2000;
void solve() {
    for (int i = 0; i < N; i++) {
        bucket[i / B].push_back(A[i]);
        num[i] = A[i];
    }
    sort(num.begin(), num.end());
    for (int i = 0; i < N / B; i++) sort(bucket[i].begin(), bucket[i].end());
    for (int i = 0; i < M; i++) {
        int l, r, k; cin >> l >> r >> k;
        r++;
        int left = -1, right = N - 1;
        while (right - left > 1) {
            int mid = left + right >> 1;
            int x = num[mid];
            int tl = l, tr = r, c = 0;
            while (tl < tr && tl % B != 0) if (A[tl++] <= x) c++;
            while (tl < tr && tr % B != 0) if (A[--tr] <= x) c++;
            
            while (tl < tr) {
                int b = tl / B;
                c += upper_bound(bucket[b].begin(), bucket[b].end(), x) - bucket[b].begin();
                tl += B;
            }
            if (c >= k) right = mid;
            else left = mid;
        }
    }
    cout << num[left];
}
