#include "olsm.h"
#include<list>
#include<iostream>


bool sortRows(Node* first, Node* second){
    if (first->row == second->row){
        return first->col < second->col;
    
    }else{
        return first->row < second->row;
    }
}

bool sortCols(Node* first, Node* second){
    if (first->col == second->col){
        return first->row < second->row;
    
    }else{
        return first->row < second->row;
    }
}

ostream& operator<<(ostream& out, olsm obj){

    obj.printMatrix();
    return out;
}

istream& operator>>(istream& in, olsm& obj){
    list<Node*> listicle;
    list<Node*>::iterator it;
    Node* temp;
    int rows, cols, size, row, col, val;
    //lets first get the row, cols, and size form the input
    in >> rows;
    in >> cols;
    in >> size;

    if (rows<0 || cols<0 || size<0){
        cout << "there was an error in the input";
    }

    obj.setInitials(rows,cols,size);

    //lets get all the nodes into our list
    for (int i=0;i<obj.getSize();i++){
        in >> row;
        in >> col;
        in >> size;
        temp = new Node(row,col,size);
        listicle.push_back(temp);
    }
    listicle.sort(sortRows);//lets set up a sorting of the nodes byu rows so we can fill the right linked list

    temp = obj.getHeader();
    for(it=listicle.begin(); it!=listicle.end(); it++){
        temp->right= *it;
        temp = temp->right;
    }
    temp->right=obj.getHeader();
    listicle.sort(sortCols);

    //lets get th header node again and we will repeat the same proccess as above
    temp = temp->right;
    //we are linking the nodes column wise
    for(it=listicle.begin();it!=listicle.end();it++){
        temp->down = (*it);
        temp = temp->down;
    }
    temp->down = obj.getHeader();
}
