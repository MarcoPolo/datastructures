#include "arrayList.h"
#include <string>
#include <algorithm>
#include <fstream>
#include <iostream>

int main(int argc, const char *argv[])
{
    ifstream inFile;
    inFile.open("Dictionary");
    if (!inFile) {
        cout << "Error opening 'Dictionary'.";
        return 1;
    }

    arrayList<string> dictionary;
    int index = 0;
    string word;
    while (inFile >> word){
        dictionary.insert(index,word);
    }
    inFile.close();


    //start sorting
    sort(dictionary.beginRA(), dictionary.endRA()); //provide the start and end addresses to sort
    arrayList<string>::seamlessPointer iter;
    

    ofstream outFile;
    outFile.open("sortedDictionary");

    for (iter = dictionary.beginRA(); iter != dictionary.endRA(); iter++) {
        outFile << *iter << endl;
    }
    outFile.close();

    //question 5
    cout << " the first element is " << dictionary[0] << endl;
    dictionary[0] = "monkeylolol";
    cout << " the first element is now " << dictionary[0] << endl;
    
    return 0;
}
