#include "olsm.h"
ostream& operator<<(ostream& out, olsm obj){

    obj.printMatrix();
    return out;
}

istream& operator>>(istream in, olsm obj){
}
