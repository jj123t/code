/*************************************************************************
	> File Name: bb.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Wed May 17 00:51:31 2023
 ************************************************************************/
#include <stdio.h>
#include <string.h>

int main()
{
    while (true) {
        int n; scanf("%d", &n);
        if (n == 0) break;

        int hour; scanf("%d", &hour);

        int fi[n], di[n], ti[n - 1];
        for (int i = 0; i < n; i++) scanf("%d", &fi[i]);
        for (int i = 0; i < n; i++) scanf("%d", &di[i]);
        for (int i = 0; i < n - 1; i++) scanf("%d", &ti[i]);

        int ans = 0;
        int pre[n]; memset(pre, 0, sizeof(pre));

        for (int k = 0, walk = 0; k < n; k++, walk += ti[k - 1] * 5) {

            int minute = hour * 60 - walk; 

            int f[n]; for (int x = 0; x < n; x++) f[x] = fi[x];
            int dohour[n]; memset(dohour, 0, sizeof(dohour));

            int now = 0, res = 0;
            while (minute - 5 >= 0) {
                int tmpcan = 0;
                int idx = now;
                for (int i = 0; i <= k; i++) {
                    if (f[i] > tmpcan) {
                        tmpcan = f[i];
                        idx = i;
                    }
                }
                if (f[idx] == 0) break;
                minute -= 5;
                res += f[idx];
                dohour[idx] += 5;
                if (f[idx] - di[idx] >= 0) f[idx] -= di[idx];
                else f[idx] = 0;
                now = idx;
            }
            if (res > ans) {
                ans = res;
                dohour[0] += minute;
                for (int x = 0; x < n; x++) pre[x] = dohour[x];
            }
        }
        for (int i = 0; i < n; i++) {
            printf("%d", pre[i]);
            if (i == n - 1) printf("\n");
            else printf(", ");
        }
        printf("Number of fish expected: %d\n\n", ans);
    }
    return 0;
}

