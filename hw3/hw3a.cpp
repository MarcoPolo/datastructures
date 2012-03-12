#include <iostream>
#include "chain.h"

int main(int argc, const char *argv[])
{
    cout << "lolz" << endl;

    chain<int> a ;
    chain<int> b ;
    chain<int> d ;
    chain<int> e ;

    a.insert(0, 2);
    a.insert(0, 3);
    b.insert(0, 4);
    b.insert(0, 5);
    b.insert(b.size(),9);
    // initialize a and b.

    chain<int> c ;
    cout << "a is: ";
    a.output(cout);
    cout << endl;
    cout << "b is: ";
    b.output(cout);
    cout << endl;
    cout << " a at index is " << a.size();
    cout << endl;
    


    c.meld(a,b) ;



    cout << "c is: ";
    c.output(cout);
    cout << endl;
    c.reverse();
    cout << "c is now: ";
    c.output(cout);
    cout << endl;
    
    c.split(d,e);
    
    cout << "d is: ";
    d.output(cout);
    cout << endl;
    cout << "e is: ";
    e.output(cout);
    cout << endl;
    

    //we are going to reverse c
    for (int i = 0; i < c.size()/2; i++) {
        this->swapNode(this->operator[](i), this->operator[](this->size()-(1+i)) );
        int temp=c.get(i);
        c.erase(i);
        c.insert(0,c.get(c.size-(1+i)));
        c.erase(c.size()-1);
        c.insert(c.size(),temp);
    }
    cout << "c is now: ";
    c.output(cout);
    cout << endl;
    



    return 0;
}


