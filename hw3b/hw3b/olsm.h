#ifndef olsm_H
#define olsm_H

#include <iostream>
#include <list>


using namespace std;

template <class T>
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
        T val;
        ~Node(){};
        Node* down;
        Node* right;
};

template <class T>
class olsm{
    private:
        Node<T>* header;
        int rows;
        int cols;
        int size;

    public:
        olsm(){
            header = new Node<T>(0, 0, 0);
            header->down=header;
            header->right=header;
            
        };
        ~olsm(){
            Node<T>* node = header;
            Node<T>* nextNode = node->right;
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
        Node<T>* getHeader(){return header;};

        static bool sortCols(Node<T>* first, Node<T>* second);
        static bool sortRows(Node<T>* first, Node<T>* second);
        void transpose(olsm& c);
        int add(olsm& otherOlsm, olsm& out);
            
};



#endif

