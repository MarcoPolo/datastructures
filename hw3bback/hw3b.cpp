#include "olsm.cpp"
#include <fstream>


using namespace std;
int main(int argc, const char *argv[])
{
    

    cout << "starting" << endl;
    ifstream file;
    file.open("hw3bin1");
    if(!file) cout << "error reading file";

    olsm lol;


    file >> lol;
    cout << lol;
    
    
    return 0;
}
