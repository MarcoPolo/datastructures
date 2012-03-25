#include "olsm.h"
#include<list>
#include<iostream>



template <class T>
ostream& operator<<(ostream& out, olsm<T>& obj){

    cout << obj.getRowSize() << endl;
    cout << obj.getColSize() << endl;
    cout << obj.getSize() << endl;
    Node<T>* node = obj.getHeader();
    node = node->right;
    while (node != obj.getHeader()){
        cout << node->row;
        cout << " ";
        cout << node->col;
        cout << " ";
        cout << node->val;
        cout << " ";
        cout << endl;
        node = node->right;
    }
    return out;
}
template <class T>
istream& operator>>(istream& in, olsm<T>& obj){
    list<Node<T>*> listicle;
    typename list<Node<T>*>::iterator it;
    Node<T>* temp;
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
        temp = new Node<T>(row,col,size);
        listicle.push_back(temp);
    }
    listicle.sort(olsm<T>::sortRows);//lets set up a sorting of the nodes byu rows so we can fill the right linked list

    temp = obj.getHeader();
    for(it=listicle.begin(); it!=listicle.end(); it++){
        temp->right= *it;
        temp = temp->right;
    }
    temp->right=obj.getHeader();
    listicle.sort(olsm<T>::sortCols);

    //lets get th header node again and we will repeat the same proccess as above
    temp = temp->right;
    //we are linking the nodes column wise
    for(it=listicle.begin();it!=listicle.end();it++){
        temp->down = (*it);
        temp = temp->down;
    }
    temp->down = obj.getHeader();
}
