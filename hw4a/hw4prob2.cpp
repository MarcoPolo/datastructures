// Name: Andrew Kennedy
// UFID: 15618865
// Discussion: 1085

#include <iostream>
#include <fstream>
#include <vector>
#include <utility>
#include "binarySearchTree.h"

using namespace std;

int main() {
    
    cout << "ballz";
    ifstream inFile;
    inFile.open("prob2In.txt");
    if (!inFile) {
        cout << "There was an error opening prob2In.txt";
        return 1;
    }
    
    int elements, key;
    char elmt;
    inFile >> elements;
    
    binarySearchTree<int, char> tree;

    for (int i = 0; i < elements; i++) {
        inFile >> key; 
        inFile >> elmt;
        const pair<int, char> node (key, elmt); 
        tree.insert(node);
    }
    inFile.close();
    
    ofstream outFile;
    outFile.open("prob2Out.txt");

    if (!outFile) {
        cout << "There was an error prob2Out.txt";
        return 1;
    }

    tree.inOrderOutput();
    binarySearchTree<int, char>::inorderIterator *iterator = tree.beginIO();
    while (iterator->hasNext())
        cout <<  iterator->next()->element << endl;

    outFile.close();

    return 0;
}
