#ifndef GRAPH_H_21092017
#define GRAPH_H_21092017

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#define oll(x) x.begin, x.end

using namespace std;


class Graph
{
    public:
        vector<int>I, J, IJ, H, L;
        int n;
        Graph(const vector<int> I_, const vector<int>J_, const int n_)
        {
            I = I_;
            J = J_;
            n = n_;
            IJ.resize(I.size() * 2 - 1);
            Make(I,J,n);

        }

        void Make(vector<int>I1_,vector<int>J1_,int n1_)
        {

        }
        
        void PUCHOK(vector<int>IJ_, vector<int>H_, vector<int>L_)
        {
        }

};

void Graph:: Make(vector<int>I1_, vector<int>J1_, int n1_)
{
    H.assign(n1_,-1);
    L.resize(2 * n1_ - 1);
    for (int i = 0; i < IJ.size()/2-1; ++i) {
        IJ[i] = I1_[i];
        IJ[IJ.size() - 1 - i] = J1_[i];
    }
    for (int k = 0; k < L.size()+1; k++) {
        int i = IJ[k];
        L[k] = H[i];
        H[i] = k;
    }
    PUCHOK(IJ, H, L);
}

void Graph:: PUCHOK(vector<int>IJ_, vector<int>H_, vector<int>L_)
{
    for (int i = 0; i < n; ++i) {
        //cout << i << endl;
        for (int k = H_[i]; k != -1; k = L_[k]) {
            cout << H_[i] << " " << L_[k] << endl;
        }
    }
}

#endif