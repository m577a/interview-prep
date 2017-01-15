
#ifndef SINGLY_LINKED_LIST_H_
#define SINGLY_LINKED_LIST_H_

#include <iterator>

namespace ds {

template<typename T> struct Node {

  public:
   T value;
   Node* next; 
   Node* previous;

};

template<typename T> class FwdNodeIterator
        : std::iterator<std::input_iterator_tag,
                        T,
                        ptrdiff_t,
                        T*,
                        T&> {

  private:
   Node<T>* current;

  public:
  FwdNodeIterator(Node<T>* startNode)
  {
      current = startNode;
  }

  
  FwdNodeIterator operator++()
          {
             current = current->next;
             return current;
          }
  
  bool operator==(const FwdNodeIterator<T>& otherIterator) const
       {
           return current == otherIterator.getConstPtr();
       }

  bool operator!=(const FwdNodeIterator<T>& otherIterator) const
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

template<typename T> class SinglyLinkedList {

   protected:
    Node<T>* head;
    Node<T>* tail;

   public:
   SinglyLinkedList();
   
   ~SinglyLinkedList();
   
   FwdNodeIterator<T>* getIterator();
   
   void append(const T& element);
   
   bool remove(const T& element);
   
   bool contains(const T& element);

   public:
       typedef FwdNodeIterator<T>    iterator;

       iterator begin() {return iterator(head);}
       iterator end() {return iterator(nullptr);}

       friend class FwdNodeIterator<T>;

};

}

#endif   /* SINGLY_LINKED_LIST_H_ */
