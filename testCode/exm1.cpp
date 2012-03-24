#include <iostream>

using namespace std;
int main(int argc, const char *argv[])
{
    cout << "balz"<<endl;
    double dp[10];
    for (int i = 0; i < 10; i++) {
        dp[i]=0.0+i;
    }
    cout <<*dp<<endl;
    return 0;
}
