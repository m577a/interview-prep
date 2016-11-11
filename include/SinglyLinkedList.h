namespace ds {

template<typename T> struct Node {

  public:
   T value;
   Node* next; 

};

template<typename T> class NodeIterator {

  private:
   Node<T>* start;
   Node<T>* current;
   
  public:
  NodeIterator(Node<T>* startNode);
  
  Node<T>* begin();
  
  Node<T>* end();

};

template<typename T> class SinglyLinkedList {

   private:
    Node<T>* head;
    Node<T>* tail;

   public:
   SinglyLinkedList();
   
   ~SinglyLinkedList();
   
   NodeIterator<T>* getIterator();
   
   void append(const T& element);
   
   bool remove(const T& element);
   
   bool contains(const T& element);
};

}
