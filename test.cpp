#include <iostream>
#include <string>
using namespace std;
class Vect {
    private:
        int vectSize ;
    public:
        int* theVect ;
        Vect(int size = 10)
        {
            vectSize = size ;
            theVect = new int[size] ;
        }
        string print()
        {
            cout << theVect[0] ;
        }
        ~Vect()
        { delete [] theVect ;}
} ;
int main()
{
    Vect a(100) ;
    Vect c ;
    c = a ;
    cout << c.print() ;
}
