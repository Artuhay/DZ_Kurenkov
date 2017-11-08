#ifndef GRAPH_H_21092017
#define GRAPH_H_21092017

#include <iostream>
#include <vector>
#include <algorithm>
#include <fstream>
#include <map>
#define oll(x) x.begin, x.end

using namespace std;


class Graph
{
    public:
        vector<int>I, J, IJ, H, L, W;
        map<int, int>most_weig;
        int n,m;
        Graph() {}

        Graph(const vector<int> I_, const vector<int>J_, const int n_)
        {
            I = I_;
            J = J_;
            n = n_;
            m = I.size();
            IJ.resize(m * 2);
            Make(I,J,m);

        }

        Graph(const vector<int> I_, const vector<int> J_, const vector<int> W_, const int n_)
        {
            I = I_;
            J = J_;
            W = W_;
            n = n_;
            m = I.size();
            IJ.resize(m * 2);
            Make(I, J, m);
        }

        void Make(vector<int>I1_, vector<int>J1_, int m_);

        
        void PUCHOK(vector<int>IJ_, vector<int>H_, vector<int>L_);


        void PUCHOK(vector<int>I1_, vector<int>J1_, vector<int>H_, vector<int>L_, int n1_, int m1_);

        void PUCHOK(vector<int>I1_, vector<int>J1_, vector<int>H_, vector<int>L_, vector<int>W_, int n1_, int m1_);

        void OBHOD(vector<int>H_, vector<int>L_);

};

void Graph:: Make(vector<int>I1_, vector<int>J1_, int m_)
{
    for (int i = 0; i < m_; ++i) {
    IJ[i] = I1_[i];
    IJ[2 * m_ - 1 - i] = J1_[i];
    }
}

void Graph::PUCHOK(vector<int>IJ_, vector<int>H_, vector<int>L_)
{
    for (int i = 0; i < m * 2-1; ++i) {
        int v = IJ_[i];
        L[i] = H[i];
        H[i] = i;
    }
}

void Graph::PUCHOK(vector<int>I1_, vector<int>J1_, vector<int>H_, vector<int>L_, int n1_,int m1_)
{
    H.assign(n1_, -1);
    L.assign(m1_,0);
    for (int k = 0; k < m; k++) {
        int i = I[k];
        L[k] = H[i];
        H[i] = k;
    }
    
    
}

void Graph::PUCHOK(vector<int>I1_, vector<int>J1_, vector<int>H_, vector<int>L_, vector<int>W_, int n1_, int m1_)
{
    H.assign(n1_, -1);
    L.assign(m1_, 0);
    for (int k = 0; k < m; k++) {
        int i = I[k];
        L[k] = H[i];
        H[i] = k;
    }


}

void Graph::OBHOD(vector<int>H_, vector<int>L_)
{
    for (int i = 0; i < n; ++i) {
        for (int k = H_[i]; k != -1; k = L_[k]) {
            cout << i << "->" << J[k] <<" weight:"<<W[k]<< endl;
            most_weig[J[k]] += W[k];
        }
    }
    int maxx, maxxver;
    maxx = most_weig.begin()->second;
    for (auto it = most_weig.begin(); it != most_weig.end(); ++it) {
        if (maxx <= it->second) {
            maxx = it->second;
            maxxver = it->first;
        }
    }
    cout <<"MOST WEIGHT VER: "<< maxxver << " with weight:" << maxx << endl;
}


#endif