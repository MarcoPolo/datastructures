#ifndef olsm_H_
#define olsm_H_

#include <iostream>
#include <list>


using namespace std;

class Node{
    public:
        Node(){};
        Node(int row, int col, int val, Node* down=NULL, Node* right=NULL){
            this->row=row;
            this->col=col;
            this->val=val;
            this->down=down;
            this->right=right;
        }
        int row;
        int col;
        int val;
        ~Node(){};
        Node* down;
        Node* right;
};

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
        int setInitials(int rows, int cols, int size){
            this->rows=rows;
            this->cols=cols;
            this->size=size;
        }
        int getRowSize(){return rows;};
        int getColSize(){return cols;};
        int getSize(){return size;};
        Node* getHeader(){return header;};
        
    void transpose(olsm& c){
        list<Node*> listicle;

        Node* node = header;
        Node* nextNode = node->right;
        Node* tempNode;
        Node* previousNode = c.getHeader();
        while (nextNode != header){
            tempNode = new Node(nextNode->col, nextNode->row, nextNode->val);
            previousNode->right = tempNode;
            previousNode = previousNode->right;
            nextNode = nextNode->right;

        }
    }

        
};

#endif
