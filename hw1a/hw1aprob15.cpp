#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
using namespace std;

void calcPi(int N);

int main(){


  int decimalPrecision = 1;
  cout << "Specify the precision of PI: ";
  cin >> decimalPrecision;
  calcPi(decimalPrecision);


  return 0;
}

void calcPi(int decimalPrecision){
  srand( time(NULL) );

  int pointcount=0;
  int N = pow(10,decimalPrecision+1); //lets increase N to make sure we can calculate the necessary decimal precision.

  //lets specify the numbers of decimals showing up cout
  cout.precision(decimalPrecision+1);


  //lets iterate over some really big number
  for(int i=0; i<N;i++){
    double x = rand()/(double)RAND_MAX;
    double y = rand()/(double)RAND_MAX;

    //now lets calculate to see if the number is actually falls within the circle
    if ( sqrt(x*x + y*y)  < 1 ){
      pointcount++;
    }
  }
  cout << N;
  cout << "\t" <<(double)pointcount/N*(double)4 << endl;
}


