#ifndef olsm_H_
#define olsm_H_

#include <iostream>


using namespace std;

class Node{
    private:
    public:
        Node(){};
        Node(int row, int col, int val, *Node down=NULL, *Node right=NULL){
            this.row=row;
            this.col=col;
            this.val=val;
            this.down=down;
            this.right=right;
        }
        int row;
        int col;
        int val;
        ~Node(){};
        Node* down;
        Node* right;
}

class olsm{
    private:
        Node* header;
        int rows;
        int cols;
        int size;

    public:
        olsm(){
            header = new Node(0, 0, 0);
            header->down=header;
            header->right=header;
            
        };
        ~olsm(){
            Node* node = header;
            Node* nextNode = node->right;
            for (int i=0;i<(size+1);i++){
                delete node;
                node = nextNode;
                nextNode= node->right;
            }
        }
        int getRowSize();
        int getColSize();
        int getHeader();
        int printMatrix();
        

        
}

void transpose(olsm& c){
    list<Node*> listicle;

    Node* node = headerNode;
    Node* nextNode = node->right;
    Node* tempNode;
    Node* previousNode = olsm.getHeader();
    while (nextNode != headerNode){
        tempNode = new Node(nextNode.col, nextNode.row, nextNode.val);
        previousNode->right = tempNode;
        previouNode = previousNode->right;
        nextNode = nextNode->right;

    }

}
