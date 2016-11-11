/*
 * LinkedList.cpp
 *
 *  Created on: Oct 30, 2016
 *      Author: melanie
 */

#include <stddef.h>
//#include <stdbool.h>
//#include <stdint.h>
//#include <stdexcept>

//using namespace std;
//using std;


#include "../../include/SinglyLinkedList.h"

namespace ds {


  template<typename T> NodeIterator<T>::NodeIterator(Node<T>* startNode) {
      start = startNode;
      current = startNode;
  }

  template<typename T> Node<T>* NodeIterator<T>::begin() {
      return start;
  }

  template<typename T> Node<T>* NodeIterator<T>::end() {
      return current->next;
  }





   template<typename T> SinglyLinkedList<T>::SinglyLinkedList(){
//       head = std::nullptr_t();
//       tail = std::nullptr_t();
       head = NULL;
       tail = NULL;
   }

   template<typename T> SinglyLinkedList<T>::~SinglyLinkedList() {}

   template<typename T> void SinglyLinkedList<T>::append(const T& element) {

       Node<T>* node = new Node<T>();
       node->value = element;
       node->next = NULL;

       if (head == NULL) {
           head = node;
           tail = head;
       } else {
           tail->next = node;
           tail = node;
       }
   }

   template<typename T> NodeIterator<T>* SinglyLinkedList<T>::getIterator() {
      return new NodeIterator<T>(head);
   }

   template<typename T> bool SinglyLinkedList<T>::remove(const T& element) {}

   template<typename T> bool SinglyLinkedList<T>::contains(const T& element) {

       Node<T>* node = head;

       while (node != NULL) {
           if (node->value == element) {
               return true;
           } else {
               node = node->next;
           }
       }
       return false;
   }


}



