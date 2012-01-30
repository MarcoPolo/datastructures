#include <iostream>
#include <cstdlib>
#include <time.h>
#include <math.h>
using namespace std;

void calcPi(int N);

int main(){
  calcPi(10e3);
  calcPi(10e4);
  calcPi(10e5);
  calcPi(10e6);
  calcPi(10e7);


  return 0;
}

void calcPi(int N){
  srand( time(NULL) );

  //lets amp up the precision cout
  cout.precision(15);

  int pointcount=0;

  //lets iterate over some really big number
  for(int i=0; i<N;i++){
    double x = rand()/(double)RAND_MAX;
    double y = rand()/(double)RAND_MAX;

    //now lets calculate to see if the number is actually falls within the circle
    if ( sqrt(x*x + y*y)  <= 1 ){
      pointcount++;
    }
  }
  cout << N;
  cout << "\t" <<(double)pointcount/N*(double)4 << endl;
}
