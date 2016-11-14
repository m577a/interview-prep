#include <iterator>

namespace ds {

template<typename T> struct Node {

  public:
   T value;
   Node* next; 

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
             return current->next;
          }
  
  bool operator==(const FwdNodeIterator<T>& otherIterator) const
       {
           return current == otherIterator.getConstPtr();
       }

  bool operator!=(const FwdNodeIterator<T>& otherIterator) const
       {
           return current != otherIterator.getConstPtr();
       }

  Node<T>& operator*()
       {
           return *current;
       }

  Node<T>* operator->()
       {
           return current;
       }

  const Node<T>* getConstPtr()const
  {
//      return std::const_cast<Node <T>>(current);
      return current;
  }

};

template<typename T> class SinglyLinkedList {

   private:
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
