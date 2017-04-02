/*
 * HashMap.cpp
 *
 *  Created on: Mar 25, 2017
 *      Author: milsted
 */

#include "../../../include/data-structures/hashmap/HashMap.h"

#include "../pair/SimplePair.cpp"
#include "../list/SinglyLinkedList.cpp"

namespace ds {
    template<typename Key, typename Value, typename HashFunction>
    HashMap<Key, Value, HashFunction>::HashMap(int size) {
        hashMapSize = size;
        keyValueMap = new vector<SinglyLinkedList<SimplePair<Key, Value>>>(hashMapSize);
    }

    template<typename Key, typename Value, typename HashFunction>
    HashMap<Key, Value, HashFunction>::~HashMap() {
        // TODO Auto-generated destructor stub
    }

    template<typename Key, typename Value, typename HashFunction>
    void HashMap<Key, Value, HashFunction>::add(Key key, Value value) {

        int mapIndex = hashFunction(key, hashMapSize);
        SinglyLinkedList<SimplePair<Key,Value>> keyValuePairList = (*keyValueMap)[mapIndex];

        // search list for existing matching key

//        for (auto keyValuePair : keyValuePairList) {
//            if (keyValuePair.first == key) {
//                // replace the value
//                keyValuePair.second = value;
//            }
//        }

        for (auto iter = keyValuePairList.begin(); iter != keyValuePairList.end(); ++iter ) {
            if (iter->first == key) {
                // update the value
                iter->second = value;
                // put the updated keyValue list back into the map
                (*keyValueMap)[mapIndex] = keyValuePairList;
                return;
            }
        }

        // key not found, so add the key value pair into the list
//        keyValuePairList.emplace_back(std::pair<Key,Value>(key,value));
//        keyValuePairList.append(std::pair<Key,Value>(key,value));
        keyValuePairList.append(SimplePair<Key,Value>(key,value));

        // put the updated keyValue list back into the map
        (*keyValueMap)[mapIndex] = keyValuePairList;
    }

    template<typename Key, typename Value, typename HashFunction>
    Value* HashMap<Key, Value, HashFunction>::get(Key key) {
        int mapIndex = hashFunction(key, hashMapSize);
//        SinglyLinkedList<pair<Key,Value>> keyValuePairList = (*keyValueMap)[mapIndex];
        SinglyLinkedList<SimplePair<Key,Value>> keyValuePairList = (*keyValueMap)[mapIndex];

        // search list for matching key
//        for (int pairIndex = 0; pairIndex < keyValuePairList.size(); ++pairIndex) {
//            pair<Key,Value>* keyValuePair = keyValuePairList;
//            if ()
//        }

        for (auto iter = keyValuePairList.begin(); iter != keyValuePairList.end(); ++iter ) {
            if (iter->first == key) {
                return &(iter->second);
            }
        }

//        for (auto keyValuePair : keyValuePairList) {
//            if (keyValuePair.first == key) {
//                // found the key, so return the associated value
//                return &(keyValuePair.second);
//            }
//        }

        // could not find the key, so return nullptr
        return nullptr;
    }

    template<typename Key, typename Value, typename HashFunction>
    vector<pair<Key, Value>>* HashMap<Key, Value, HashFunction>::getVector() {

//        vector<pair<Key, Value>>* combinedVector = new vector<pair<Key, Value>>(hashMapSize);
        vector<pair<Key, Value>>* combinedVector = new vector<pair<Key, Value>>(0);

        // loop through all buckets in the hash map
        for (int mapIndex = 0; mapIndex < hashMapSize; ++mapIndex) {

//            SinglyLinkedList<pair<Key,Value>> keyValuePairList = (*keyValueMap)[mapIndex];
            SinglyLinkedList<SimplePair<Key,Value>> keyValuePairList = (*keyValueMap)[mapIndex];

            // loop through all keyValue pairs in the bucket
            for (auto iter = keyValuePairList.begin(); iter != keyValuePairList.end(); ++iter ) {

                // add the keyValue pair into the combined list
//                combinedVector->emplace_back(*iter);
                combinedVector->emplace_back(std::pair<Key,Value>(iter->first, iter->second));  // construct a std::pair from the SimplePair
            }

        }

        return combinedVector;
    }


} /* namespace ds */

