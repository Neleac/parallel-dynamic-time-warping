#include <limits>
#include <algorithm>
#include <stdlib.h>

using namespace std;

int costFunction(int v1, int v2) {
    return abs(v1 - v2);
}

int dtw(int* s, int* t, int n, int m) {
    int** DP = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        DP[i] = new int[m + 1];
        for (int j = 0; j <= m; j++) {
            DP[i][j] = numeric_limits<int>::max();
        }
    }
    DP[0][0] = 0;

    for (int i = 1; i <= n; i++) {
        for (int j = 1; j <= m; j++) {
            int cost = costFunction(s[i], t[j]);
            DP[i][j] = cost + min({DP[i - 1][j], DP[i][j - 1], DP[i - 1][j - 1]});
        }
    }

    int result = DP[n][m];

    for (int i = 0; i <= n; i++) {
        delete[] DP[i];
    }
    delete[] DP;

    return result;
}