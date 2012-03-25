#include "olsm.cpp"
#include <fstream>


using namespace std;
int main(int argc, const char *argv[])
{
    

    cout << "starting woo" << endl;
    ifstream file;
    file.open("hw3bin1");
    if(!file) cout << "error reading file";

    olsm<int> lol;
    olsm<int> lol2;
    olsm<int> lolT;
    olsm<int> lolADD;


    file >> lol;
    file.close();
    ifstream file2;
    file.open("hw3bin2");
    if(!file) cout << "error reading file";
    file >> lol2;
    lol.transpose(lolT);
    lolT.add(lol2, lolADD);

    cout << "this is origin" << endl;
    cout << lol <<endl;
    cout << "this is origin" << endl;
    cout << lol2 <<endl;
    cout << "this is transpose" << endl;
    cout << lolT;
    cout << endl;
    cout << "this is the addition" << endl;
    cout << lolADD;
    
    
    return 0;
}
