#ifndef DOUBLY_LINKED_LIST_H_
#define DOUBLY_LINKED_LIST_H_


#include <iterator>

#include "SinglyLinkedList.h"

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
  BwdNodeIterator(Node<T>* startNode)
  {
      current = startNode;
  }

  
  BwdNodeIterator operator--()
          {
             current = current->next;
             return current;
          }


  BwdNodeIterator operator++()
          {
             current = current->previous;
             return current;
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

       BwdIterator rbegin() {return BwdIterator(SinglyLinkedList<T>::tail);}
       BwdIterator rend() {return BwdIterator(nullptr);}

       friend class BwdNodeIterator<T>;

};

}

#endif   /* DOUBLY_LINKED_LIST_H_ */
