#define _CRT_SECURE_NO_WARNINGS
#include "Kucha.h"
#include <fstream>

int main()
{
    freopen("testin.txt", "r", stdin);
    freopen("testout.txt", "w", stdout);
    int n;
    cin >> n;
    vector<int>A(n),B;
    for (int i = 0; i < n; ++i) {
        cin >> A[i];
    }
    Heap hp(A, n);
    for (int i = 0; i < n; ++i) {
        hp.ADDD(A[i],B);
    }
   // hp.HEAPING(A);
    hp.SSORT();
    for (int i = 0; i < n; ++i) {
        cout << B[i] << " ";
    }
    cout << endl;
    for (int i = 0; i < n; ++i) {
        cout << hp.sort_massiv[i] << " ";
    }
}