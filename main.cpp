#include <iostream>
#include <chrono>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

extern int dtw(int** DP, int* s, int* t, int n, int m);

int main(int argc, char** argv) 
{
    int N = atoi(argv[1]);
    int n = N, m = N;

    int* s = new int[n];
    int* t = new int[m];
    for (int i = 0; i < N; i++) {
        int val = rand() % 100;
        s[i] = val;
        t[i] = val;
    }

    int** DP = new int*[n + 1];
    for (int i = 0; i <= n; i++) {
        DP[i] = new int[m + 1];
        for (int j = 0; j <= m; j++) {
            DP[i][j] = numeric_limits<int>::max();
        }
    }
    DP[0][0] = 0;

    chrono::time_point<chrono::high_resolution_clock> start_time = chrono::high_resolution_clock::now();

    int minCost = dtw(DP, s, t, n, m);
    
    chrono::time_point<chrono::high_resolution_clock> end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_time - start_time;

    cout << "Problem Size: " << N << endl;
    cout << "Time Elapsed: " << elapsed.count() << endl;
    cout << "Min Cost: " << minCost << endl;
    
    delete[] s;
    delete[] t;
    for (int i = 0; i <= n; i++) {
        delete[] DP[i];
    }
    delete[] DP;

    return 0;
}