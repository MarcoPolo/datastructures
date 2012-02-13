#include <iostream>
#include <stdio.h>
#include <vector>
#include <set>
#include "1bc.h"
#include <string.h>

using namespace std;

template <class T>
void tDds<T>::alloc3D(tDds<T> &a, int m, int n, int p) {
    a.array = new T**[m];
    for(int i=0; i<m; i++)
        a.array[i] = new T*[n];
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            a.array[i][j] = new T[p];
}

template <class T>
void tDds<T>::dealloc3D(tDds<T> &a, int m, int n, int p) {
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            delete [] a.array[i][j];
    for(int i=0; i<m; i++)
        delete [] a.array[i];
    delete [] a.array;
}

template <class T>
vector<T> & tDds<T>::add(const tDds<T> &a, const tDds<T> &b, tDds<T> &c, int m,
                                                                int n, int p) {
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<p; k++) {
                c.array[i][j][k] = a.array[i][j][k]+b.array[i][j][k];
                c.retVector.push_back(c.array[i][j][k]);
            }
    return c.retVector;
}

template <class T>
void tDds<T>::read(tDds<T> &a, int m, int n, int p) {

    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<p; k++)
                cin >> a.array[i][j][k];
}

template <class T>
void tDds<T>::print(tDds<T> &a, int m, int n, int p) {
    int counter=0;
    for(int i=0; i<m; i++)
        for(int j=0; j<n; j++)
            for(int k=0; k<p; k++)
                    cout << a.array[i][j][k] << endl;
    printf("\n");
}

struct ltstr
{
      bool operator()(const char* s1, const char* s2) const
            {
                    return strcmp(s1, s2) < 0;
            }
};

template <class T>
void tDds<T>::isWord(const vector<T> &a, vector<T> &b, vector<T> &c) {
    cout << "Illegal Vector" << endl;
}

template <>
void tDds<string>::isWord(const vector<string> &a, vector<string> &b,
                                                vector<string> &c) {
    set<const char*, ltstr> words;
    int n;
    char str[1000];
    FILE *fp = fopen("words.txt", "r");

    while(fscanf(fp," %s", str)>0) {
        words.insert(strdup(str));
    }

    for(int i=0; i<a.size(); i++) {
        if(words.find(a[i].c_str()) != words.end())
            b.push_back(a[i]);
        else
            c.push_back(a[i]);
    }

    cout << b.size() << endl;
    for(int i=0; i<b.size(); i++) {
        cout << b[i] << endl;
    }
    cout << c.size() << endl;
    for(int i=0; i<c.size(); i++) {
        cout << c[i] << endl;
    }

}


main() {
    tDds<int> a, b, c;
    tDds<string> astr, bstr, cstr;
    int m,n,p, type;

    scanf(" %d %d %d %d", &m, &n, &p, &type);

   if(type != 0) {
    a.alloc3D(a,m,n,p);
    b.alloc3D(b,m,n,p);
    c.alloc3D(c,m,n,p);

    a.read(a,m,n,p);
    b.read(b,m,n,p);

    vector<int> &intVec = c.add(a,b,c,m,n,p);

    a.print(a,m,n,p);
    b.print(b,m,n,p);
    c.print(c,m,n,p);

    vector<int> parta, partb;
    c.isWord (intVec, parta, partb);

   } else {
    astr.alloc3D(astr,m,n,p);
    bstr.alloc3D(bstr,m,n,p);
    cstr.alloc3D(cstr,m,n,p);

    astr.read(astr,m,n,p);
    bstr.read(bstr,m,n,p);

    vector<string> & retstr = cstr.add(astr,bstr,cstr,m,n,p);

    astr.print(astr,m,n,p);
    bstr.print(bstr,m,n,p);
    cstr.print(cstr,m,n,p);

    vector<string> parta, partb;
    cstr.isWord (retstr, parta, partb);
   }
}
