#include <iostream>
#include <stdlib.h>

using namespace std;

extern int dtw(int* s, int* t, int n, int m);

int main(int argc, char** argv) 
{
    int N = 1000;

    int* s = new int[N];
    int* t = new int[N];

    for (int i = 0; i < N; i++) {
        int val = rand() % 100;
        s[i] = val;
        t[i] = val;
    }

    int minCost = dtw(s, t, N, N);
    cout << minCost << endl;
    
    delete[] s;
    delete[] t;

    return 0;
}