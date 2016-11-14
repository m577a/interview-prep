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


#include "../../../include/data-structures/list/SinglyLinkedList.h"

namespace ds {





   template<typename T> SinglyLinkedList<T>::SinglyLinkedList(){
       head = nullptr;
       tail = nullptr;
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

   template<typename T> FwdNodeIterator<T>* SinglyLinkedList<T>::getIterator() {
      return new FwdNodeIterator<T>(head);
   }

   template<typename T> bool SinglyLinkedList<T>::remove(const T& element) {}

   template<typename T> bool SinglyLinkedList<T>::contains(const T& element) {

       Node<T>* node = head;

       while (node != nullptr) {
           if (node->value == element) {
               return true;
           } else {
               node = node->next;
           }
       }
       return false;
   }


}



