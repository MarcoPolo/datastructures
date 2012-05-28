#include <iostream>
#include <fstream>
#include <list>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
class hw5{
    public:
        vector< vector<int> > nodes;
        vector<int> visited;
        int edges;
        int num;
        int vertices;

        hw5(){
        }

        void read(){ //this function will read the crap from the input
            ifstream inFile;
            inFile.open("hw5in");
            if (!inFile) {
                cout << "There was an error opening the file";
                return;
            }
            
            inFile >> vertices;
            inFile >> edges;

            //lets build the outer array first
            for (int i = 0; i < vertices; i++) {
                vector<int> temp;
                nodes.push_back(temp);
            }

            //now we read the network of nodes
            //effectively remembering the lines drawn btwn nodes
            
            for (int i = 0; i < edges; i++) {
                int startNode; 
                int endNode; 
                inFile >> startNode;
                inFile >> endNode;
                nodes[startNode-1].push_back(endNode);
                nodes[endNode-1].push_back(startNode);
            }

        }

        bool haveWeVisited(int &num){
            return find(visited.begin(), visited.end(), num)!=visited.end();
        }

        bool dfsSearchHasLoop(int head, int lastHead){
            if(haveWeVisited(head)) return true;
            visited.push_back(head);
            for (int i = 0; i < nodes[head-1].size(); i++) {
                if (nodes[head-1][i] != head && nodes[head-1][i] != lastHead){
                    bool hasLoop = dfsSearchHasLoop(nodes[head-1][i], head);
                    if (hasLoop) return true;
                }
            }
            return false;
        }

        void printVisited(){
            cout << "[" ;
            for (int i = 0; i < visited.size(); i++) {
                cout << " " << visited[i] << ", ";
            }
            cout << "]\n";

        }
        void printNodes(){
            for (int i = 0; i < nodes.size(); i++) {
                for (int j = 0; j < nodes[i].size(); j++) {
                    cout << "number@ (" << i << "," << j << ") is:\t" << nodes[i][j];
                    cout << endl;
                }
            }
        }

        bool hasCycle(){
            for (int i = 1; i < nodes.size()+1; i++) {
                visited.clear();
                bool hasLoop = dfsSearchHasLoop(i, 0);
                if(hasLoop) return true;
            }
            return false;
        }

        void findCycle(){
            string output = hasCycle() ? "Cycle: Yes" : "Cycle: No";
            //change this to save to a file

            ofstream outFile;
            outFile.open("hw5out");

            outFile << output << endl;
        }

};
