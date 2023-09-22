/*************************************************************************
	> File Name: kmp.cpp
	> Author:123emm 
	> Mail: 2542142016@qq.com
	> Created Time: Fri Jul 28 23:09:38 2023
 ************************************************************************/
#include<bits/stdc++.h>
using namespace std;
vector<int> fail(2e5);
void getfail(string p) {
    fail[0] = -1;
    int i = 0, j = -1;
    while (i < p.size() - 1) {
        if (j == -1 or p[i] == p[j]) {
            i++, j++;
            if (p[i] != p[j]) fail[i] = j;
            else fail[i] = fail[j];
        }
    }
}
bool kmp(string s, string p) {
    int i = 0, j = 0;
    while (i < s.size() and j < (int)(p.size())) {
        if (j == -1 or s[i] == p[j]) i++, j++;
        else j = fail[j];
    }
    return j == (int)p.size();
}
int main()
{

    return 0;
}

