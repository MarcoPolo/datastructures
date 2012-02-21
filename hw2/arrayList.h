// array implementation of a linear list
// derives from abstract class linearList just to make sure
// all methods of the ADT are implemented
// USES STL ALGORITHMS TO SIMPLIFY CODE
// iterator class for arrayList included

#ifndef arrayList_
#define arrayList_

#include<iostream>
#include<sstream>
#include<string>
#include<algorithm>
#include<iterator>
#include "linearList.h"
#include "myExceptions.h"
#include "changeLength1D.h"

using namespace std;

template<class T>
class arrayList : public linearList<T> 
{
   public:
      // constructor, copy constructor and destructor
      arrayList(int initialCapacity = 10);
      arrayList(const arrayList<T>&);
      ~arrayList() {delete [] element;}

      // ADT methods
      bool empty() const {return listSize == 0;}
      int size() const {return listSize;}
      T& get(int theIndex) const;
      int indexOf(const T& theElement) const;
      void erase(int theIndex);
      void insert(int theIndex, const T& theElement);
      void output(ostream& out) const;

      // additional method
      int capacity() const {return arrayLength;}

      void reverse();

      //Question 5
      T& operator[](ptrdiff_t n) const 
      {
        return element[n];
    
      }
      
      // iterators to start and end of list
      class iterator ; // declaration for the iterator class
      iterator begin() {return iterator(element);}
      iterator end() {return iterator(element + listSize);}
      
      class seamlessPointer ; // declaration for the seamlessPointer class
      seamlessPointer beginRA() {return seamlessPointer(element) ;}
      seamlessPointer endRA() {return seamlessPointer(element + listSize) ; }
      
      
      // iterator for arrayList
      class iterator 
      {
         public:
            // typedefs required by C++ for a bidirectional iterator
            typedef bidirectional_iterator_tag iterator_category;
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;

            // constructor
            iterator(T* thePosition = 0) {position = thePosition;}

            // dereferencing operators
            T& operator*() const {return *position;}
            T* operator->() const {return &*position;}
            
            // increment
            iterator& operator++()   // preincrement
                      {++position; return *this;}
            iterator operator++(int) // postincrement
                    {iterator old = *this;
                     ++position;
                     return old;
                    }

            // decrement
            iterator& operator--()   // predecrement
                      {--position; return *this;}
            iterator operator--(int) // postdecrement
                    {iterator old = *this;
                     --position;
                     return old;
                    }

            // equality testing
            bool operator!=(const iterator right) const
                  {return position != right.position;}
            bool operator==(const iterator right) const
                  {return position == right.position;}
                  
                 

         protected:
            T* position;
      };  // end of iterator class
  
      class seamlessPointer : public iterator
      {
  public:
      // typedefs required by C++ for a bidirectional iterator
            typedef random_access_iterator_tag iterator_category;
            typedef T value_type;
            typedef ptrdiff_t difference_type;
            typedef T* pointer;
            typedef T& reference;
      
      // constructor
      seamlessPointer(T* thePosition = 0) {this->position = thePosition ;}
      
      // increment
      seamlessPointer& operator+=(ptrdiff_t n)
      {
    // NOTE: random iterators do arbitrary jumps in O{1) time
          // I saw that some of you  used a for loop by incrementing and decrementing using ++ or --. 
    //This completely shatters the idea of random access iterators.
        iterator::position = iterator::position + n ; 
        return *this ;
    
      }
      seamlessPointer operator+(ptrdiff_t n)
      {
        // increment in O(1) time
        //also I noted in this function that many of you did not create a new iterator by calling the constructor. 
        //This will give you wrong results because what ths operator does is something like c = a + n and not a += n.
        // so here the sum a+n is stored in a different new iterator which is created by calling the constructor seamlessIterator.
        // This function operator+ is different from operator+= that is written above.
        return seamlessPointer(iterator::position+n) ;
      }
      
      //decrement DO IT yourself
      seamlessPointer& operator-=(ptrdiff_t n)
      {
        //TODO  decrement in constant time and do not use a for loop.
          iterator::position = iterator::position - n ; 
          return *this ;
      }
      seamlessPointer operator-(ptrdiff_t n)
      {
        //TODO decerement in constant time.
        return seamlessPointer(iterator::position-n) ;

      }
      ptrdiff_t operator-(seamlessPointer ptr)
      {
         
        return (iterator::position - ptr.position) ;
      }
      bool operator<(const seamlessPointer &ptr) const
      {
        
        return iterator::position < ptr.position ;
      }
      // Here now I guess you basically do not need the functions that are commented below: (only < will suffice for sorting). BUt I cannot guarantee. 
      //Check it yourself whether or not you get correct results or not.
      
      /*bool operator>(const seamlessPointer &ptr) const
      {
        return iterator::position > ptr.position ;
        
      }
      bool operator<=(const seamlessPointer &ptr) const
      {
        return iterator::position <= ptr.position ;
      }
      bool operator>=(const seamlessPointer &ptr) const
      {
        return iterator::position = ptr.position ;
      }*/
      T& operator[](ptrdiff_t n) const // probably you dont need this one too for sorting
      {
        return this->position[n] ;
      }
      
      
  
      } ; // end of seamlessPointer class


        

   protected:  // additional members of arrayList
      void checkIndex(int theIndex) const;
            // throw illegalIndex if theIndex invalid
      T* element;            // 1D array to hold list elements
      int arrayLength;       // capacity of the 1D array
      int listSize;          // number of elements in list
};

template<class T>
arrayList<T>::arrayList(int initialCapacity)
{// Constructor.
   if (initialCapacity < 1)
   {ostringstream s;
    s << "Initial capacity = " << initialCapacity << " Must be > 0";
    throw illegalParameterValue(s.str());
   }
   arrayLength = initialCapacity;
   element = new T[arrayLength];
   listSize = 0;
}

template<class T>
arrayList<T>::arrayList(const arrayList<T>& theList)
{// Copy constructor.
   arrayLength = theList.arrayLength;
   listSize = theList.listSize;
   element = new T[arrayLength];
   copy(theList.element, theList.element + listSize, element);
}

template<class T>
void arrayList<T>::checkIndex(int theIndex) const
{// Verify that theIndex is between 0 and listSize - 1.
   if (theIndex < 0 || theIndex >= listSize)
   {ostringstream s;
    s << "index = " << theIndex << " size = " << listSize;
    throw illegalIndex(s.str());
   }

}

template<class T>
T& arrayList<T>::get(int theIndex) const
{// Return element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);
   return element[theIndex];
}

template<class T>
int arrayList<T>::indexOf(const T& theElement) const
{// Return index of first occurrence of theElement.
 // Return -1 if theElement not in list.

   // search for theElement
   int theIndex = (int) (find(element, element + listSize, theElement)
                         - element);

   // check if theElement was found
   if (theIndex == listSize)
     // not found
     return -1;
   else return theIndex;
 }

template<class T>
void arrayList<T>::erase(int theIndex)
{// Delete the element whose index is theIndex.
 // Throw illegalIndex exception if no such element.
   checkIndex(theIndex);

   // valid index, shift elements with higher index
   copy(element + theIndex + 1, element + listSize,
                                element + theIndex);

   --listSize;
   //element[--listSize].~T(); // invoke destructor
}

template<class T>
void arrayList<T>::insert(int theIndex, const T& theElement)
{// Insert theElement so that its index is theIndex.
   if (theIndex < 0 || theIndex > listSize)
   {// invalid index
      ostringstream s;
      s << "index = " << theIndex << " size = " << listSize;
      throw illegalIndex(s.str());
   }

   // valid index, make sure we have space
   if (listSize == arrayLength)
      {// no space, double capacity
         changeLength1D(element, arrayLength, 2 * arrayLength);
         arrayLength *= 2;
      }

   // shift elements right one position
   copy_backward(element + theIndex, element + listSize,
                 element + listSize + 1);

   element[theIndex] = theElement;

   listSize++;
}

template<class T>
void arrayList<T>::output(ostream& out) const
{// Put the list into the stream out.
   copy(element, element + listSize, ostream_iterator<T>(cout, "  "));
}

// overload <<
template <class T>
ostream& operator<<(ostream& out, const arrayList<T>& x)
   {x.output(out); return out;}


// reverse member function
template <class T>
void arrayList<T>::reverse()
{
   for( int k = 0; k<listSize/2 ; k++ ) 
   {
      swap( element[k], element[listSize-k-1] );
   }
}


// reverse
template <class T>
void reverse(arrayList<T>& arr)
{
  int listSize = arr.size();
  T temp1, temp2;
  for( int k = 0; k<listSize/2 ; k++ ) 
   {
      temp1 = arr.get(k );
      temp2 = arr.get( listSize-k-1 );
      arr.erase( listSize - k -1 );
      arr.erase( k);
      arr.insert( k, temp2 );
      arr.insert( listSize-k-1, temp1 );
      
   }
  
}


#endif
