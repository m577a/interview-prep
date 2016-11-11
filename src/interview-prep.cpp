//============================================================================
// Name        : interview-prep.cpp
// Author      : Melanie Davis
// Version     :
// Copyright   : (c) 2016
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>

#include "/usr/local/Cellar/gtest/gtest/gtest.h"
#include "data-structures/list/SinglyLinkedList.cpp"

using namespace std;
using namespace ds;

int main(int ac, char* av[]) {
	cout << "!!!Hello World!!!" << endl;
	testing::InitGoogleTest(&ac, av);
	  return RUN_ALL_TESTS();
/*
    SinglyLinkedList<int> * myList = new SinglyLinkedList<int>();

    cout << "adding value 1 to list" << endl;
    myList->append(1);

    if ( myList->contains(1) ) {
       cout << "found value 1" << endl;
    } else {
       cout << "could not find value 1"  << endl;
    }

    NodeIterator<int>* myIterator = myList->getIterator();
    Node<int>* index = myIterator->begin();

    while (index != NULL) {
       cout << "iterator got value = " << index->value << endl;
      index = myIterator->end();
    }

*/

    /*
    Queue<int> * myQueue = new Queue<int>(3);
    myQueue->enqueue(4);
    cout << myQueue->get_size() << endl;
    int value = myQueue->dequeue();
    value = myQueue->peek();
    if (value == NULL) {
        cout << "HELLO" << endl;
    }

    cout << myQueue->get_size() << endl;
    myQueue->dequeue();
    cout << myQueue->get_size() << endl;
    vector<int> myVector(10);
    bool isEmpty = myQueue->is_empty();
    isEmpty = true;
    */
	return 0;
}
