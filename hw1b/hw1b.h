#ifndef _1b_
#define _1b_

#include <iostream>
#include <vector>
#include <stdio.h>
using namespace std;


template <class T>
class tript {
    vector<T> vect;

    public:
    T*** arr;
    void dealloc3dArray(tript<T> &x, int m, int n, int p);
    void alloc3dArray(tript<T> &x, int m, int n, int p);
    vector<T>& allOperations(tript<T> &x, tript<T> &y, tript<T> &z,vector<T>& lolz, int m, int n, int p);
    void print3dArray(tript<T> &x,int m,int n,int p);
    void printVector(vector<T>& a);

    void isWord(vector<string>& dict,vector<T>& wordlist,vector<string>& valid,vector<string>& notValid);
    const vector<T>& loadDict(vector<T>& dict);
    void writeVector(vector<T>& a, string name);
};

#endif
