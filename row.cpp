#include <limits>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int costFunction(int v1, int v2) {
    return abs(v1 - v2);
}

int dtw(int** DP, int* s, int* t, int n, int m) {
    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = costFunction(s[i - 1], t[j - 1]);
            DP[i][j] = cost + min({DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1]});
        }
    }
    return DP[n][m];
}