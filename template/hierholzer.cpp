int in[60], e[60][60];
void hierholzer(int u) {
    for (int i = 1; i <= 50; i++) {
        if (e[u][i]) {
            e[u][i]--; e[i][u]--;
            hierholzer(i);
            cout << i << " " << u << "\n";
        }
    }
}
