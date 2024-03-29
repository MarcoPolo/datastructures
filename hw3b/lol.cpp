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

        bool static sortCols(Node<T>* first, Node<T>* second){
            if (first->col == second->col){
                return first->row < second->row;
            
            }else{
                return first->col < second->col;
            }
        }
        bool static sortRows(Node<T>* first, Node<T>* second){
            if (first->row == second->row){
                return first->col < second->col;
            
            }else{
                return first->row < second->row;
            }
        }

        void transpose(olsm& c){
            list<Node<T>*> listicle;

            Node<T>* node = header;
            Node<T>* nextNode = node->right;
            Node<T>* tempNode;
            Node<T>* previousNode = c.getHeader();
            typename list<Node<T>*>::iterator it;
            c.setInitials(cols, rows, size);
            while (nextNode != header){
                tempNode = new Node<T>(nextNode->col, nextNode->row, nextNode->val);
                previousNode->right = tempNode;
                previousNode = previousNode->right;
                nextNode = nextNode->right;
                listicle.push_back(tempNode);
            }
            previousNode->right = c.getHeader();

            listicle.sort(olsm::sortRows);
            previousNode = c.getHeader();

            //lets fix the sorting
            for (it=listicle.begin(); it!=listicle.end(); it++){
                previousNode->right = *it;
                previousNode = previousNode->right;
            }
            previousNode->right = c.getHeader();

            listicle.sort(olsm::sortCols);
            previousNode = c.getHeader();

            //we need to also remember to link the down nodes as well
            for (it=listicle.begin(); it!=listicle.end(); it++){
                previousNode->down = *it;
                previousNode = previousNode->down;
            }
            previousNode->down = c.getHeader();
        }

        int add(olsm& otherOlsm, olsm& out){
            //they are not the same size;
            if(rows != otherOlsm.rows || cols != otherOlsm.cols){
                cout << "the row col dimensions are incorrect" << endl;
                return false;
            }

            //here we go again, lets make a list to store a sort our nodes
            list<Node<T>*> listicle;
            typename list<Node<T>*>::iterator it;
            Node<T> *thisNode, *otherNode, *outNode, *tempNode;
            thisNode = header;
            otherNode = otherOlsm.getHeader();
            outNode = out.getHeader();

            //we need this to keep track of the nodes being placed
            int outSize = 0;

            thisNode=thisNode->right;
            otherNode = otherNode->right;

            
            while (thisNode != header && otherNode != otherOlsm.getHeader()){
                cout << "inside here mate" << endl;
                //If we are inserting a node from this we will find it first in the right chain so it will have a lower row or same row and lower col #
                //insert from this
                if (thisNode->row < otherNode->row || (thisNode->row == otherNode->row && thisNode->col < otherNode->col) ) {
                    cout << "this" << endl;
                    tempNode = new Node<T>(thisNode->row, thisNode->col, thisNode-> val);
                    thisNode = thisNode->right;
                    outNode->right = tempNode;
                    outNode = outNode->right;
                    listicle.push_back(tempNode);
                    outSize++;
                }
                //insert from other
                //if the other olsm appears first then that means that it will have the opposite of above
                if (otherNode->row < thisNode->row || (otherNode->row == thisNode->row && otherNode->col < thisNode->col) ) {
                    cout << "other" << endl;
                    tempNode = new Node<T>(otherNode->row, otherNode->col, otherNode-> val);
                    otherNode = otherNode->right;
                    outNode->right = tempNode;
                    outNode = outNode->right;
                    listicle.push_back(tempNode);
                    outSize++;

                }

                //if they are in the same spot then we need to add them!
                if (otherNode->row == thisNode->row && otherNode->col == thisNode->col)  {
                    cout << "they are the same!!" << endl;
                    int newSum = thisNode->val + otherNode->val;
                    
                    if(newSum == 0){
                        //the sum is zero so nothing to see here, carry on
                        continue;
                    }

                    tempNode = new Node<T>(thisNode->row, thisNode->col, thisNode->val + otherNode->val);
                    thisNode = thisNode->right;
                    otherNode = otherNode->right;
                    outNode->right = tempNode;
                    outNode = outNode->right;
                    listicle.push_back(tempNode);
                    outSize++;
                }

            }
            //maybe we still need to fill in some spots
            while (thisNode != header){
                tempNode = new Node<T>(thisNode->row, thisNode->col, thisNode->val);
                listicle.push_back(tempNode);
                outNode->right = tempNode;
                outNode = outNode->right;
                thisNode = thisNode->right;
                outSize++;
                cout << "monkey";
            }
            //maybe we still need to fill in some spots
            while (otherNode != otherOlsm.getHeader()){
                tempNode = new Node<T>(otherNode->row, otherNode->col, otherNode->val);
                listicle.push_back(tempNode);
                outNode->right = tempNode;
                outNode = outNode->right;
                otherNode = otherNode->right;
                outSize++;
                cout << "ballllz";
            }
            outNode->right = out.getHeader();
            outNode = out.getHeader();
            //lets set the down links now

            
            listicle.sort(olsm::sortCols);
            outNode;
            for( it = listicle.begin(); it!=listicle.end(); it++){
                outNode->down = (*it);
                outNode = outNode->down;
            }
            outNode->down = out.getHeader();
            out.setInitials(rows, cols, outSize);
            listicle.clear();
        }
            
};



#endif
