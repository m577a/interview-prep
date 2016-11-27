#include "gtest/gtest.h"
#include <math.h>
#include <iostream>

#include "../../../src/data-structures/list/SinglyLinkedList.cpp"

using namespace std;
using namespace ds;

TEST(ListTests, ListCreation) {
        //EXPECT_EQ(1000, pow(10,3));

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

        cout << "done" << endl;

}
