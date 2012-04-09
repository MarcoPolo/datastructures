// test linked binary tree class

#include <iostream>
#include "linkedBinaryTree.h"

using namespace std;

int main(void)
{
   linkedBinaryTree<int> a,x,y,z;
   y.makeTree(1,a,a);
   z.makeTree(2,a,a);
   x.makeTree(3,y,z);
   y.makeTree(4,x,a);
   cout << "Number of nodes = ";
   cout << y.size() << endl;
   cout << "height = ";
   cout << y.height() << endl;
   cout << "Preorder sequence is ";
   y.preOrderOutput();
   cout << "Inorder sequence is ";
   y.inOrderOutput();
   cout << "Postorder sequence is ";
   y.postOrderOutput();
   cout << "Level order sequence is ";
   y.levelOrderOutput();
   
   
   /////////////////// test for iterators
      
   cout << "Preorder sequence is ";
   cout << endl;
   //POSTORDER ITERATOR
   linkedBinaryTree<int>::postOrderIterator ip = y.beginPO() ;
   while(ip.hasNext())
     y.output(ip.next()) ;
   cout << endl;
   
   //INORDER ITERATOR
		// Do it yourself
    
   cout << "Inorder sequence is ";
   cout << endl;
   linkedBinaryTree<int>::inOrderIterator jp = y.beginIO() ;
   while(jp.hasNext())
     y.output(jp.next()) ;

   return 0;
}
