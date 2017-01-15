/*
 * LinkedList.cpp
 *
 *  Created on: Oct 30, 2016
 *      Author: melanie
 */

#include <stddef.h>
#include <cstddef>

//using namespace std;
//using std;


#include "../../../include/data-structures/list/DoublyLinkedList.h"


namespace ds {





   template<typename T> DoublyLinkedList<T>::DoublyLinkedList(){
       SinglyLinkedList<T>::head = nullptr;
       SinglyLinkedList<T>::tail = nullptr;
   }

   template<typename T> DoublyLinkedList<T>::~DoublyLinkedList() {}

   template<typename T> void DoublyLinkedList<T>::append(const T& element) {

       Node<T>* node = new Node<T>();
       node->value = element;
       node->next = nullptr;
       node->previous = SinglyLinkedList<T>::tail;

       if (SinglyLinkedList<T>::head == nullptr) {
           SinglyLinkedList<T>::head = node;
           SinglyLinkedList<T>::tail = SinglyLinkedList<T>::head;
       } else {
           SinglyLinkedList<T>::tail->next = node;
           SinglyLinkedList<T>::tail = node;
       }
   }

   // TODO: ADD SEPARATE METHODS FOR GETTING A FORWARD ITERATOR AND A REVERSE ITERATOR

   template<typename T> BwdNodeIterator<T>* DoublyLinkedList<T>::getIterator() {
      return new BwdNodeIterator<T>(SinglyLinkedList<T>::tail);
   }

   template<typename T> bool DoublyLinkedList<T>::remove(const T& element) {}

//   template<typename T> bool DoublyLinkedList<T>::contains(const T& element) {
//
//       Node<T>* node = head;
//
//       while (node != nullptr) {
//           if (node->value == element) {
//               return true;
//           } else {
//               node = node->next;
//           }
//       }
//       return false;
//   }


}



