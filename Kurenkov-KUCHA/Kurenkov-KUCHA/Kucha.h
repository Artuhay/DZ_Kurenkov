#ifndef KUCHA_H_09112017
#define KUCHA_H_09112017

#include <iostream>
#include <vector>
#include <algorithm>
#define oll(x) x.begin(), x.end()

using namespace std;

class Heap
{
public:
    vector<int>massiv, sort_massiv;
    vector<int>massivvvch;
    int n;
    Heap() {}
    Heap(vector<int>& massiv_, int& n_)
    {
        massiv = massiv_;
        n = n_;
    }
    void REAM_N(int k, vector<int>&massiv1);
    void REAM_V(int k, vector<int>&massiv1);
    void HEAPING(vector<int>&massiv1);
    void SSORT();
    void DELL(int k,vector<int>&massiv1);
    void ADDD(int k, vector<int>&massiv__);
};

void Heap::ADDD(int k,vector<int>&massiv__)
{
    int nn = massiv__.size();
    massiv__.resize(nn+1);
    massiv__[massiv__.size() - 1] = k;
    REAM_V(massiv__.size() - 1, massiv__);
}

void Heap::REAM_N(int k,vector<int>&massiv1)
{
    int n_ = massiv1.size();
    int k1 = 0, k2 = 0,j=0;
    for (int i = k; i < (n_ - 1) / 2; i = j) {
        k1 = 2 * i + 1;
        k2 = k1 + 1;
        j = k1;
        if ((k2 < n_) && (massiv1[k2] < massiv1[k1])) {
            j = k2;
        }
        if (massiv1[i] < massiv1[j]) {
            break;
        }
        swap(massiv1[i], massiv1[j]);
    }
    if (n_ == 2) {
        if (massiv1[0] > massiv1[1]) {
            swap(massiv1[0], massiv1[1]);
        }
    }
}

void Heap::REAM_V(int k, vector<int>&massiv1)
{
    int k1 = 0;
    for (int i = k; i > 0; i = k1) {
        k1 = (i - 1) / 2;
        if (massiv1[k1] > massiv1[i]) {
            swap(massiv1[k1], massiv1[i]);
        }
    }
}

void Heap::HEAPING(vector<int>&massiv1) {
    for (int k = (n - 1) / 2; k >= 0; --k) {
        REAM_N(k,massiv1);
    }
}

void Heap::DELL(int k,vector<int>&massiv1)
{
    int a = massiv1[k];
    massiv1[k] = massiv1[n - 1];
    n--;
    massiv1.resize(n);
    if (massiv1[k] > a) {
        REAM_N(k, massiv1);
    }
    else {
        REAM_V(k, massiv1);
    }
    
}

void Heap::SSORT()
{
  for(int i=0;i<n;++i)
    ADDD(massiv[i],massivvvch);
  int f = massivvvch.size();
    while(f>0) {
        sort_massiv.push_back(massivvvch[0]);
        swap(massivvvch[0], massivvvch[f - 1]);
        f--;
        massivvvch.resize(f);
        REAM_N(0, massivvvch);
    }
}

#endif // !_KUCHA_09112017

