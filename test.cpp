#include <iostream>
#include <string>
using namespace std;

int main(int argc, const char *argv[])
{

    string a[3];
    for (int i = 0; i < 3; i++) {
        cin >> a[i];
    }
    for (int i = 0; i < 3; i++) {
        cout << a[i];
    }

    return 0;
}
