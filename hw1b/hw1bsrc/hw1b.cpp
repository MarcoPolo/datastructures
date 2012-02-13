#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "hw1b.h"

using namespace std;



template <class T>
void tript<T>::alloc3dArray(tript<T> &x, int m, int n, int p){
    x.arr = new T** [m];
    for (int i = 0; i < m; i++) {
        x.arr[i] = new T* [n];
        for (int j = 0; j < n; j++) {
            x.arr[i][j] = new T [p];
        }
    }
}

template <class T>
void tript<T>::dealloc3dArray(tript<T> &x, int m, int n, int p){
    cout << "ballz" << endl;
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            cout << "deleting x.arr[" << i << "][" << j << "]" << endl;
            delete[] x.arr[i][j];
        }
        cout << "deleting x.arr[" << i << "]" <<endl;
        delete [] x.arr[i];
    }
    cout << "deleting x.arr" <<endl;
    delete [] x.arr;
    x.arr = 0; //wooo lets make sure no one (me) causes unwanted segfaults
}


template <class T>
vector<T>& tript<T>::allOperations(tript<T> &x, tript<T> &y, tript<T> &z,vector<T>& lolz, int m, int n, int p){
    for (int i = 0; i < m; i++) {
        for (int j = 0; j < n; j++) {
            for (int l = 0; l < p; l++) {
                z.arr[i][j][l] = x.arr[i][j][l] + y.arr[i][j][l];
                lolz.push_back(z.arr[i][j][l]);
            }
        }
    }
    return lolz;
}

int compareWord(string& a, string& b){

    string d = "pi";
    string acpy = a;
    int i = 0;
    while (acpy[i]){
        acpy[i]=tolower(acpy[i]);
        i++;
    }
    string bcpy = b;
    i = 0;
    while (bcpy[i]){
        bcpy[i]=tolower(bcpy[i]);
        i++;
    }
    return acpy.compare(bcpy);
}

template <class T>
void tript<T>::isWord(vector<string>& dict,vector<T>& wordlist,vector<string>& valid,vector<string>& notValid){
    cout << "Illegal Vector" << endl;
    valid.push_back("Illegal Vector");
}

template <>
void tript<string>::isWord(vector<string>& dict,vector<string>& wordlist,vector<string>& valid,vector<string>& notValid){
    int i=0;
    int j = 0;
    for (i = 0; i < wordlist.size(); i++) {
        for (j = 0; j < dict.size(); j++) {
            if ( compareWord(wordlist.at(i), dict.at(j)) == 0){
                valid.push_back(wordlist.at(i));
            }else{
                notValid.push_back(wordlist.at(i));
            }
        }
    }
}


template <class T>
const vector<T>& loadDict(vector<T>& dict){
    ifstream dictFile;
    dictFile.open("/usr/share/dict/words");
    string line;
    if (dictFile.is_open()){
        while (dictFile.good() ){
            getline( dictFile, line );
            dict.push_back(line);
        }
    }
    return dict;
}


template <class T>
void tript<T>::print3dArray(tript<T> &x,int m,int n,int p){
    for (int i = 0; i < m; i++) 
        for (int j = 0; j < n; j++) 
            for (int l = 0; l < p; l++) 
                cout << x.arr[i][j][l] << endl;

}

template <class T>
void tript<T>::printVector(vector<T>& a){
    typename vector<T>::iterator it;
    for (it=a.begin(); it != a.end(); it++){
        cout << *it << endl;
    }
}

template <class T>
void tript<T>::writeVector(vector<T>& a, string namez){
    typename vector<T>::iterator it;
    ofstream outfile;
    outfile.open(namez.c_str());
    for (it=a.begin(); it != a.end(); it++){
        outfile << *it << endl;
    }
    outfile.close();
}


int main(int argc, const char *argv[])
{
    tript<int> x;
    tript<int> y;
    tript<int> z;

    tript<string> xstr;
    tript<string> ystr;
    tript<string> zstr;

    int m,n,p,type;
    scanf( " %d %d %d %d", &m, &n, &p, &type);
    cout << "the numbers where " << m << n << p << type << endl;
    
    vector<string> dict;
    vector<string> valid;
    vector<string> notValid;
    if (type == 0){ //the input is a string
        xstr.alloc3dArray(xstr,3,3,3);
        ystr.alloc3dArray(ystr,3,3,3);
        zstr.alloc3dArray(zstr,3,3,3);
        string temp[m*n*p];
        for (int i = 0; i < m*n*p; i++) {

            cin >> temp[i]; 
            cout << "xstr.arr["<<i/(n*p)%m<<"]["<<(i/p)%n<<"]["<<i%p<<"]" << " = " << temp[i] << endl;
            xstr.arr[(i/(n*p))%m][(i/p)%n][i%p] = temp[i];
        }

        

        for (int i = 0; i < m*n*p; i++) {

            cin >> temp[i]; 
            //cout << "ystr.arr["<<i/(n*p)%m<<"]["<<(i/p)%n<<"]["<<i%p<<"]" << " = " << temp[i] << endl;
            ystr.arr[(i/(n*p))%m][(i/p)%n][i%p] = temp[i];
        }
    
        vector<string> lolz;
        lolz = xstr.allOperations(xstr,ystr,zstr,lolz,m,n,p);

        xstr.printVector(lolz);
        //writing operations are more clear if they are implemented in a different function
        xstr.writeVector(lolz, "hw1bout1");
        
        loadDict(dict);
        xstr.isWord(dict, lolz, valid, notValid);
        xstr.writeVector(valid, "hw1bout2");

        xstr.printVector(valid);
    } else {  //we will assume it is going to be a number
        x.alloc3dArray(x,3,3,3);
        y.alloc3dArray(y,3,3,3);
        z.alloc3dArray(z,3,3,3);
        int temp[m*n*p];
        vector<int> lolz;

        for (int i = 0; i < m*n*p; i++) {

            cin >> temp[i]; 
            cout << "x.arr["<<i/(n*p)%m<<"]["<<(i/p)%n<<"]["<<i%p<<"]" << " = " << temp[i] << endl;
            x.arr[(i/(n*p))%m][(i/p)%n][i%p] = temp[i];
        }
        for (int i = 0; i < m*n*p; i++) {

            cin >> temp[i]; 
            cout << "y.arr["<<i/(n*p)%m<<"]["<<(i/p)%n<<"]["<<i%p<<"]" << " = " << temp[i] << endl;
            y.arr[(i/(n*p))%m][(i/p)%n][i%p] = temp[i];
        }

        lolz = x.allOperations(x,y,z,lolz,m,n,p);

        z.print3dArray(z,m,n,p);
        x.isWord(dict, lolz, valid, notValid);

        x.writeVector(lolz, "hw1bout1");
        xstr.writeVector(valid, "hw1bout2");

    }



    return 0;
}
