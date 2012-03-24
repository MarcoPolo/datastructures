#include <vector>
#include <iostream>

class Doh {
    public:
        std::vector<int> *v ;
        Doh(int size) {v = new std::vector<int>(size);}
        ~Doh() { delete v; }
};

using namespace std;
int main() { 
 Doh d1(8); 
int a = 3;
 Doh *d2 = new Doh(6) ; 
 Doh *d3 = d2 ; 
//delete &a;
 delete  d1.v ; 
 //delete d2->v ; 
 //delete d3->v ; 
 delete d2 ; 
 //delete d3 ; 

 return 0;
}
