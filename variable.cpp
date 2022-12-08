#include <algorithm>
#include <omp.h>

using namespace std;

int costFunction(int v1, int v2) {
    return abs(v1 - v2);
}

int dtw(int** DP, int* s, int* t, int n, int m) {

    int nDiags = n + m - 1;
    int stepSize = nDiags / 9;
    int nThreads = 2;
    int minThreads = 2;
    int maxThreads = 32;
    bool increase = true;

    for (int diag = 0; diag < nDiags; diag++) {
        int i = min(diag, n - 1);
        int j = max(0, diag - n + 1);
        int count = min(i + 1, m - j);
        
        if ((diag + 1) % stepSize == 0) {
            if (increase) {
                nThreads *= 2;
            } else if (nThreads > minThreads) {
                nThreads /= 2;
            }

            if (nThreads == maxThreads) increase = false;
        }

        #pragma omp parallel for num_threads(nThreads)
        for (int idx = 0; idx < count; idx++) {
            int row = i - idx + 1;
            int col = j + idx + 1;

            int cost = costFunction(s[row - 1], t[col - 1]);
            DP[row][col] = cost + min({DP[row - 1][col], DP[row][col - 1], DP[row - 1][col - 1]});
        }
    }
    return DP[n][m];
}