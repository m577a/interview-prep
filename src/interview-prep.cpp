//============================================================================
// Name        : interview-prep.cpp
// Author      : Melanie Davis
// Version     :
// Copyright   : (c) 2016
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>

//#include "data-structures/queue/Queue.cpp"
#include "data-structures/SinglyLinkedList.cpp"


using namespace std;
using namespace ds;

int main() {


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



    /*
	cout << "!!!Hello World!!!" << endl; // prints !!!Hello World!!!
	int count = 3;
    int total = count++ * 3;
	cout << total << endl;
    cout << RAND_MAX << endl;
    double value1 = 10.5;
    cout << INT_MAX << endl;
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
