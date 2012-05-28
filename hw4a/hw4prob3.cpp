// Name: Andrew Kennedy
// UFID: 1561865
// Discussion: 1085

#include <iostream>
#include <fstream>
#include <vector>

using namespace std;

int getPrimeTableSize(int);

class HashTableEntry {
    public:
        string key;
        int value;
        HashTableEntry(string key, int value) {
            this->key = key;
            this->value = value;
        } 
};

class HashTable {
    
    public:
        HashTable() {
            this->tableSize = 0;
        }

        HashTable(int size) { 
            this->tableSize = size;
            this->hashTable = new HashTableEntry*[tableSize];
            this->initializeHashTable();
        }

        ~HashTable() {
            for (int i = 0; i < tableSize; i++)
                delete[] hashTable[i];
            delete[] hashTable;
        }

        void insert(string key, int value) {
            int hashVal = hash(key);
            while (this->hashTable[hashVal] != NULL)
                hashVal = (hashVal+1) % this->tableSize;
            this->hashTable[hashVal] = new HashTableEntry(key, value);
        }

        int getValue(string key) {
            int hashVal = hash(key);
            while (this->hashTable[hashVal] != NULL && key != this->hashTable[hashVal]->key) 
                hashVal = (hashVal+1) % this->tableSize;
            if (hashTable[hashVal] == NULL)
                return -1;
            else 
                return this->hashTable[hashVal]->value;
            }
        
    private:
        int tableSize;
        HashTableEntry **hashTable;

        int hash(string word) {
            int hashVal = 0;
            int shifter = 127;
            
            for (string::iterator iter = word.begin(); iter != word.end(); iter++) 
                hashVal = (shifter * hashVal + (int)*iter) % this->tableSize;
            
            return hashVal;
        }

        void initializeHashTable() {
            for (int i = 0; i < this->tableSize; i++)
                this->hashTable[i] = NULL;
        }
};

int main() {
    ifstream inFile;
    inFile.open("hw4prob3in");
    if (!inFile) {
        cout << "There was an error opening hw4prob3in";
        return 1;
    }

    int wordsToSearch;
    inFile >> wordsToSearch;
    string words[wordsToSearch];
    
    for (int i = 0; i < wordsToSearch; i++) {
       inFile >> words[i]; 
    }

    string longWord;
    inFile >> longWord;

    inFile.close();

    int tableSize = getPrimeTableSize(longWord.size());
    HashTable * myHashTable = new HashTable(tableSize);

    int lengthOfWords = (int)words[0].size();
    for (int i = 0; i <= (int)longWord.size() - lengthOfWords; i++) {
        string wordToHash = longWord.substr(i, lengthOfWords); 
        myHashTable->insert(wordToHash, i);
    }

    ofstream outFile;
    outFile.open("hw4prob3out");
    
    outFile << "start end" << endl;
    
    for (int i = 0; i < wordsToSearch; i++) {
        int value = myHashTable->getValue(words[i]);
        if (value == -1) {
            outFile << "-1 -1" << endl;
        } else {
            outFile << value << " " << value + (int)words[i].size() - 1 << endl;
        }
    }

    outFile.close();

    myHashTable = NULL;
    delete[] myHashTable;
    return 0;
}

    
int getPrimeTableSize(int wordSize) {
    wordSize = wordSize*2 + 1;
    bool isNotPrime = true;
    
    while (isNotPrime) {
        wordSize += 2;
        isNotPrime = false;
        for (int i = 3; i < wordSize; i++) 
            if (wordSize % i == 0)
                isNotPrime = true;
    }
    return wordSize;
}
