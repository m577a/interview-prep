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

        // FATAL if fails
        // ASSERT_TRUE(myList->contains(1));

        // logs result then continues to later tests
        EXPECT_TRUE(myList->contains(1));

//        if ( myList->contains(1) ) {
//           cout << "found value 1" << endl;
//        } else {
//           cout << "could not find value 1"  << endl;
//        }

//        typedef MyIter FwdNodeIterator<int>;
        FwdNodeIterator<int>* myIterator = myList->getIterator();
        FwdNodeIterator<int> index = myList->begin();

        while (index != myList->end()) {
           cout << "iterator got value = " << index->value << endl;
        }


}
