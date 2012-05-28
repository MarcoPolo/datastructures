#include <vector>
#include <iostream>

using namespace std;

void ballz( vector< vector<int> > &lol ){
    int* a = new int(10);
    int k = 10;
    vector<int> l;

    lol.push_back(l);
    cout << "the number was" << endl;
    cout << lol.size() << endl;


}

int main(int argc, const char *argv[])
{
    vector< vector<int> > a;
    ballz(a);

    cout << "the number was" << endl;
    cout << a.size() << endl;

    a[0].push_back(3);
    int l = 4;

    cout << "the number was" << endl;
    cout << a[0][0] << endl;

    cout << "the number was" << endl;
    cout << a.size() << endl;

    a.clear();

    cout << "the number was" << endl;
    cout << a.size() << endl;

    return 0;
}
