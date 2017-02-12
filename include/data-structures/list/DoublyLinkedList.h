#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_


#include <iterator>

#include "SinglyLinkedList.h"

//using std;

namespace ds {


// TODO : CONVERT THIS FROM A BACKWARD ITERATOR INTO A BI-DIRECTIONAL ITERATOR
template<typename T> class BwdNodeIterator
        : std::iterator<std::bidirectional_iterator_tag,
                        T,
                        ptrdiff_t,
                        T*,
                        T&> {

  private:
   Node<T>* current;

  public:


//   /Applications/Xcode.app/Contents/Developer/Toolchains/XcodeDefault.xctoolchain/usr/bin/../include/c++/v1/iterator:540:56: error: no type named 'iterator_category' in 'std::__1::iterator_traits<ds::BwdNodeIterator<int> >'
//       : public iterator<typename iterator_traits<_Iter>::iterator_category,
//                         ~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~~^~~~~~~~~~~~~~~~~
//   ../test/data-structures/list/Test-List.cpp:85:51: note: in instantiation of template class 'std::__1::reverse_iterator<ds::BwdNodeIterator<int> >' requested here
//           for (MyRevIter myIterator = myDoubleList->rbegin(); myIterator != myDoubleList->rend(); ++myIterator) {
//                                                     ^
//   In file included from ../test/data-structures/list/Test-List.cpp:1:
//
// TODO: THE STRUCT BELOW WAS A FAILED ATTEMPT TO FIX THE COMPLIATION ERROR ABOVE.
// SEE P.284 OF STL BOOK
  template <class U>
  struct iterator_traits {
      typedef U value_type;
      typedef ptrdiff_t difference_type;
      typedef U* pointer;
      typedef U& reference;
      typedef std::bidirectional_iterator_tag iterator_category;
  };

  BwdNodeIterator(Node<T>* startNode)
  {
      current = startNode;
  }


  BwdNodeIterator(const BwdNodeIterator& other)
  {
      current = other.current;
  }

  

  BwdNodeIterator& operator++()
          {
             current = current->next;
             return *this;
          }


  BwdNodeIterator& operator--()
          {
             current = current->previous;
             return *this;
          }


  BwdNodeIterator operator++(int)
          {
             BwdNodeIterator temp = BwdNodeIterator(*this);
             current = current->next;
             return temp;
          }


  BwdNodeIterator operator--(int)
          {
             BwdNodeIterator temp = BwdNodeIterator(*this);
             current = current->previous;
             return temp;
          }
  
  bool operator==(const BwdNodeIterator<T>& otherIterator) const
       {
           return current == otherIterator.getConstPtr();
       }

  bool operator!=(const BwdNodeIterator<T>& otherIterator) const
       {
           return current != otherIterator.getConstPtr();
       }

  T& operator*()
       {
           return current->value;
       }

  T* operator->()
       {
           return &(current->value);
       }

  const Node<T>* getConstPtr()const
  {
//      return std::const_cast<Node <T>>(current);
      return current;
  }

};

template<typename T> class DoublyLinkedList : public SinglyLinkedList<T> {


   public:
   DoublyLinkedList();
   
   ~DoublyLinkedList();
   
   BwdNodeIterator<T>* getIterator();
   
   void append(const T& element);
   
   bool remove(const T& element);
   
   bool contains(const T& element);

   public:
       typedef BwdNodeIterator<T>    BwdIterator;
       typedef std::reverse_iterator< BwdNodeIterator<T> > reverse_iterator;

       BwdIterator begin() {return BwdIterator(DoublyLinkedList<T>::head);}
       BwdIterator end() {return nullptr;}

       reverse_iterator rbegin() {return reverse_iterator(BwdIterator(DoublyLinkedList<T>::tail));}
       reverse_iterator rend() {return reverse_iterator(nullptr);}

       friend class BwdNodeIterator<T>;

};

}

#endif   /* DOUBLY_LINKED_LIST_H_ */
