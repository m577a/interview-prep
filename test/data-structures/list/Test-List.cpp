#include "gtest/gtest.h"
#include <math.h>
#include <iostream>

#include "../../../src/data-structures/list/SinglyLinkedList.cpp"
#include "../../../src/data-structures/list/DoublyLinkedList.cpp"

using namespace std;
using namespace ds;

TEST(ListTests, ListCreation) {
        //EXPECT_EQ(1000, pow(10,3));

    //--------------Singly Linked List tests----------------

        SinglyLinkedList<int> * myList = new SinglyLinkedList<int>();

        cout << "adding value 1 to list" << endl;
        myList->append(1);
        cout << "adding value 2 to list" << endl;
        myList->append(2);
        cout << "adding value 3 to list" << endl;
        myList->append(3);

        // FATAL if fails
        // ASSERT_TRUE(myList->contains(1));

        // logs result then continues to later tests
        EXPECT_TRUE(myList->contains(1));

//        if ( myList->contains(1) ) {
//           cout << "found value 1" << endl;
//        } else {
//           cout << "could not find value 1"  << endl;
//        }

        typedef FwdNodeIterator<int> MyIter;

        for (FwdNodeIterator<int>* myIterator = myList->getIterator(); *myIterator != myList->end(); ++(*myIterator)) {
            cout << "iterator style #1 got value = " << myIterator->getConstPtr()->value << endl;
        }

        for (MyIter myIterator = myList->begin(); myIterator != myList->end(); ++myIterator) {
            cout << "iterator style #2 got value = " << *myIterator << endl;
        }

        for (int myIterator : *myList) {
            cout << "iterator style #3 got value = " << myIterator << endl;
        }

        //--------------Doubly Linked List tests----------------

        DoublyLinkedList<int> * myDoubleList = new DoublyLinkedList<int>();

        cout << "adding value 1 to double list" << endl;
        myDoubleList->append(1);
        cout << "adding value 2 to double list" << endl;
        myDoubleList->append(2);
        cout << "adding value 3 to double list" << endl;
        myDoubleList->append(3);

        // FATAL if fails
        // ASSERT_TRUE(myList->contains(1));

        // logs result then continues to later tests
        //
        //  TODO : FIX THIS SO THAT IT LINKS CORRECTLY
        //
        //EXPECT_TRUE(myDoubleList->contains(1));

//        if ( myList->contains(1) ) {
//           cout << "found value 1" << endl;
//        } else {
//           cout << "could not find value 1"  << endl;
//        }

        typedef BwdNodeIterator<int> MyBwdIter;
        typedef DoublyLinkedList<int>::reverse_iterator MyRevIter;

        // Cannot use this style of loop with a reverse iterator
//        for (BwdNodeIterator<int>* myIterator = myDoubleList->getIterator(); *myIterator != myDoubleList->rend(); ++(*myIterator)) {
//            cout << "reverse iterator style #1 got value = " << myIterator->getConstPtr()->value << endl;
//        }

        for (MyRevIter myIterator = myDoubleList->rbegin(); myIterator != myDoubleList->rend(); ++myIterator) {
            cout << "reverse iterator style #2 got value = " << *myIterator << endl;
        }

        // Cannot use for-each syntax to invoke a reverse iterator with C++ 2011
        // so the for-each syntax will always invoke the forward iterator in C++ 2011
        // Need to upgrade to C++ 2014 to exercise the reverse iterator
        for (int myIterator : *myDoubleList) {
            cout << "reverse iterator style #3 got value = " << myIterator << endl;
        }

        //-------------

        cout << "done" << endl;

}
