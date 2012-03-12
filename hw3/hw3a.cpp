#include <iostream>
#include "chain.h"

int main(int argc, const char *argv[])
{

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
    


    //lets show how we meld two objects together
    //the melded chain is stored in the c chain
    c.meld(a,b);

    cout << "c is: ";
    c.output(cout);
    cout << endl;

    //lets reverse the c chain from the member methods
    c.reverse();
    cout << "c is now: ";
    c.output(cout);
    cout << endl;
    
    //we are going to reverse c again using nonmember methods
    //this should re reverse c to get what we originally had
    for (int i = 0; i < (int)c.size()/2; i++) {
        int temp=c.get(i);
        c.erase(i);
        c.insert(i,c.get(c.size()-(1+i)));
        c.erase(c.size()-(1+i));
        c.insert(c.size()-(i),temp);
    }
    cout << "c is back to: ";
    c.output(cout);
    cout << endl;

    //now lets split the chain c into two empty chains d and e.
    c.split(d,e);
    
    cout << "d is: ";
    d.output(cout);
    cout << endl;
    cout << "e is: ";
    e.output(cout);
    cout << endl;
    

    



    return 0;
}


