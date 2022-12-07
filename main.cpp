#include <iostream>
#include <chrono>
#include <cstdlib>
#include <stdlib.h>

using namespace std;

extern int dtw(int* s, int* t, int n, int m);

int main(int argc, char** argv) 
{
    int N = atoi(argv[1]);

    int* s = new int[N];
    int* t = new int[N];

    for (int i = 0; i < N; i++) {
        int val = rand() % 100;
        s[i] = val;
        t[i] = val;
    }

    chrono::time_point<chrono::high_resolution_clock> start_time = chrono::high_resolution_clock::now();

    int minCost = dtw(s, t, N, N);
    
    chrono::time_point<chrono::high_resolution_clock> end_time = chrono::high_resolution_clock::now();
    chrono::duration<double> elapsed = end_time - start_time;

    cout << "Problem Size: " << N << endl;
    cout << "Time Elapsed: " << elapsed.count() << endl;
    
    delete[] s;
    delete[] t;

    return 0;
}