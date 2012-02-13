#ifndef _1b_
#define _1b_

#include <iostream>
#include <vector>
#include <stdio.h>

using namespace std;

template <class T>
class tDds {

    T*** array;
    vector<T> retVector;

    public:

    void alloc3D(tDds<T> &a, int m, int n, int p);
    void dealloc3D(tDds<T> &a, int m, int n, int p);
    vector<T> & add(const tDds<T> &a, const tDds<T> &b, tDds<T> &c, int m, int n, int p);
    void read(tDds<T> &a, int m, int n, int p);
    void print(tDds<T> &a, int m, int n, int p);
    void isWord(const vector<T> &a, vector<T> &b, vector<T> &c);
};

#endif
