// linked implementation of a linear list
// derives from abstract class linearList just to make sure
// all methods of the ADT are implemented

#ifndef chain_
#define chain_

#include<iostream>
#include<sstream>
#include<string>
#include "linearList.h"
#include "chainNode.h"
#include "myExceptions.h"

using namespace std;

class linkedDigraph;
template <class T> class linkedWDigraph;

template<class T>
class chain : public linearList<T> 
{
   public:
      // constructor, copy constructor and destructor
      chain(int initialCapacity = 10);
      chain(const chain<T>&);
      ~chain();

      // ADT methods
      bool empty() const {return listSize == 0;}
      int size() const {return listSize;}
      T& get(int theIndex) const;
      int indexOf(const T& theElement) const;
      void erase(int theIndex);
      void insert(int theIndex, const T& theElement);
      void output(ostream& out) const;
      void meld(chain a, chain b);
      void split(chain& a, chain& b);
      void reverse();
      void swapNode(chainNode<T>* a, chainNode<T>* b);
      chainNode<T>* operator[](int index);

   protected:
      void checkIndex(int theIndex) const;
            // throw illegalIndex if theIndex invalid
      chainNode<T>* firstNode;  // pointer to first node in chain
      int listSize;             // number of elements in list
};

template<class T>
chain<T>::chain(int initialCapacity)
{// Constructor.
   if (initialCapacity < 1)
   {ostringstream s;
    s << "Initial capacity = " << initialCapacity << " Must be > 0";
    throw illegalParameterValue(s.str());
   }
   firstNode = NULL;
   listSize = 0;
}

template<class T>
chain<T>::chain(const chain<T>& theList)
{// Copy constructor.
   listSize = theList.listSize;

   if (listSize == 0)
   {// theList is empty
      firstNode = NULL;
      return;
   }

   // non-empty list
   chainNode<T>* sourceNode = theList.firstNode;
                    // node in theList to copy from
   firstNode = new chainNode<T>(sourceNode->element);
                    // copy first element of theList
   sourceNode = sourceNode->next;
   chainNode<T>* targetNode = firstNode;
                    // current last node in *this
   while (sourceNode != NULL)
   {// copy remaining elements
      targetNode->next = new chainNode<T>(sourceNode->element);
      targetNode = targetNode->next;
      sourceNode = sourceNode->next;
   }
   targetNode->next = NULL; // end the chain
}

template<class T>
chain<T>::~chain()
{// Chain destructor. Delete all nodes in chain.
   while (firstNode != NULL)
   {// delete firstNode
      chainNode<T>* nextNode = firstNode->next;
      delete firstNode;
      firstNode = nextNode;
   }
}

template<class T>
void chain<T>::checkIndex(int theIndex) const
{// Verify that theIndex is between 0 and listSize - 1.
   if (theIndex < 0 || theIndex >= listSize)
   {ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
   }

}

template<class T>
T& chain<T>::get(int theIndex) const
{// Return element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);

   // move to desired node
   chainNode<T>* currentNode = firstNode;
   for (int i = 0; i < theIndex; i++)
      currentNode = currentNode->next;

   return currentNode->element;
}

template<class T>
int chain<T>::indexOf(const T& theElement) const
{// Return index of first occurrence of theElement.
 // Return -1 if theElement not in list.

   // search the chain for theElement
   chainNode<T>* currentNode = firstNode;
   int index = 0;  // index of currentNode
   while (currentNode != NULL && 
          currentNode->element != theElement)
   {
      // move to next node
      currentNode = currentNode->next;
      index++;
   }

   // make sure we found matching element
   if (currentNode == NULL)
      return -1;
   else
      return index;
}

template<class T>
void chain<T>::erase(int theIndex)
{// Delete the element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);

   // valid index, locate node with element to delete
   chainNode<T>* deleteNode;
   if (theIndex == 0)
   {// remove first node from chain
      deleteNode = firstNode;
      firstNode = firstNode->next;
   }
   else 
   {  // use p to get to predecessor of desired node
      chainNode<T>* p = firstNode;
      for (int i = 0; i < theIndex - 1; i++)
         p = p->next;
   
      deleteNode = p->next;
      p->next = p->next->next; // remove deleteNode from chain
   }
   listSize--;
   delete deleteNode;
}

template<class T>
void chain<T>::insert(int theIndex, const T& theElement)
{// Insert theElement so that its index is theIndex.
   if (theIndex < 0 || theIndex > listSize)
   {// invalid index
      ostringstream s;
      s << "index = " << theIndex << " size = " << listSize;
      throw illegalIndex(s.str());
   }

   if (theIndex == 0)
      // insert at front
      firstNode = new chainNode<T>(theElement, firstNode);
   else
   {  // find predecessor of new element
      chainNode<T>* p = firstNode;
      for (int i = 0; i < theIndex - 1; i++)
         p = p->next;
   
      // insert after p
      p->next = new chainNode<T>(theElement, p->next);
   }
   listSize++;
}

template<class T>
void chain<T>::output(ostream& out) const
{// Put the list into the stream out.
   for (chainNode<T>* currentNode = firstNode;
                      currentNode != NULL;
                      currentNode = currentNode->next)
      out << currentNode->element << "  ";
}
template<class T>
void chain<T>::meld(chain a, chain b)
{// meld two list into one
    //first lets find which of the two chains is smaller
    int smallSize = a.size() < b.size() ? a.size() : b.size();
    chainNode <T> *currentNode;
    chainNode <T> *nextNode;
    
    //update the listSize
    listSize = a.size()+b.size();

    //check if both are empty
    if (b.size() == 0 && a.size() == 0){
        return;
    }

    //check to see if either is empty
    if (a.size() == 0) {
        firstNode = new chainNode<T>(b.get(0), 0);
        nextNode = firstNode;
        for (int i = 1; i < b.size(); i++){
            currentNode = new chainNode<T>(b.get(i), 0);
            nextNode->next = currentNode;
            nextNode = nextNode->next;
        }
        return;
    }
    if (b.size() == 0) {
        firstNode = new chainNode<T>(a.get(0), 0);
        nextNode = firstNode;
        for (int i = 1; i < a.size(); i++){
            currentNode = new chainNode<T>(a.get(i), 0);
            nextNode->next = currentNode;
            nextNode = nextNode->next;
        }
        return;
    }
     
    //lets start melding them together
    firstNode = new chainNode<T>(a.get(0), 0);
    currentNode = new chainNode<T>(b.get(0), 0);
    firstNode->next=currentNode;
    nextNode = firstNode->next;
    
    //lets only alternate for the largets common length (aka smaller size of the two)
    for (int i = 1; i < smallSize; i++) {
        currentNode = new chainNode<T>(a.get(i), 0);
        nextNode->next = currentNode;
        nextNode = nextNode->next;
        currentNode = new chainNode<T>(b.get(i), 0);
        nextNode->next = currentNode;
        nextNode = nextNode->next;
    }
    if (a.size() > b.size()) {
        //a is bigger so we will attach the rest of a to the chain
        for (int i = smallSize; i < a.size(); i++){
            currentNode = new chainNode<T>(a.get(i), 0);
            nextNode->next = currentNode;
            nextNode = nextNode->next;
        }
    }else{
        //a is bigger so we will attach the rest of a to the chain
        for (int i = smallSize; i < b.size(); i++){
            currentNode = new chainNode<T>(b.get(i), 0);
            nextNode->next = currentNode;
            nextNode = nextNode->next;
        }
    }
}

template<class T>
void chain<T>::split(chain& a, chain& b)
{// split one list into two

    int originalSize = listSize;
    for (int i = 0; i < originalSize; i++) {
        if ( i%2 == 0 ){
            a.insert(a.size(),this->get(i));
        }else{
            b.insert(b.size(),this->get(i));
        }
    }
}
template<class T>
void chain<T>::reverse()
{// lets reverse the chain
    for (int i = 0; i < (int)listSize/2; i++) {
        this->swapNode(this->operator[](i), this->operator[](this->size()-(1+i)) );
    }
}

template<class T>
void chain<T>::swapNode(chainNode<T>* first, chainNode<T>* second)
{// lets reverse the chain
    T temp;
    temp = first->element;
    first->element = second->element;
    second->element = temp;
}

template <class T>
chainNode<T>* chain<T>::operator[](int index)
{
    
    chainNode <T> *currentNode = firstNode;
    for (int i = 0; i < index; i++) {
        currentNode = currentNode->next;
    }
    return currentNode;
}


// overload <<
template <class T>
ostream& operator<<(ostream& out, const chain<T>& x)
   {x.output(out); return out;}

#endif
