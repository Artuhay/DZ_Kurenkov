#define _CRT_SECURE_NO_WARNINGS
#include "2.h"

using namespace std;

int main()
{
    freopen("testin.txt", "r", stdin);
    freopen("testout.txt", "w", stdout);
    
    int m,n;
    cin >> n >> m;
    vector<int>I, J, W;
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        I.push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        J.push_back(a);
    }
    for (int i = 0; i < m; ++i) {
        int a;
        cin >> a;
        W.push_back(a);
    }
    Graph gr(I, J,W, n);
    gr.PUCHOK(gr.I, gr.J, gr.H, gr.L, gr.n, gr.m);
    gr.OBHOD(gr.H, gr.L);
}
