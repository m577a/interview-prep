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
#include "../include/algorithms/WordCounter.h"

using namespace std;
using namespace ds;

int main(int ac, char* av[]) {
	cout << "!!!Hello World!!!" << endl;

	WordCounter testWordCount = WordCounter();

	testWordCount.count();

	testing::InitGoogleTest(&ac, av);
	  return RUN_ALL_TESTS();

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
