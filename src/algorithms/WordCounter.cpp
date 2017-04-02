//============================================================================
// Name        : test-wordcount.cpp
// Author      : Melanie Davis
// Version     :
// Copyright   : (c) 2016
// Description : Hello World in C++, Ansi-style
//============================================================================

#include <iostream>
#include <vector>
#include <unordered_map>
#include <algorithm>

#include "../../include/algorithms/WordCounter.h"

#include "../data-structures/hashmap/HashMap.cpp"

//#include "/usr/local/Cellar/gtest/gtest/gtest.h"


using namespace std;

namespace ds {

struct hashFunc{

    int operator()(const string& input, int hashSize) const {

    int hashValue = 0;

    // loop over the characters in the string
    for (int index = 0; index < input.length(); ++index) {
        char character = input[index];

        hashValue = (hashValue + (uint)character);
    }

    hashValue = hashValue % hashSize;

    return hashValue;
    }
};


// Comparison function used for sorting.
// Returns true if the left wordStat has more words than the right wordStat
bool moreWords(const std::pair<string, int>& leftWordStat,
               const std::pair<string, int>& rightWordStat) {
    return leftWordStat.second > rightWordStat.second;
}

// Takes a series of words and produces a summary of word counts, sorted in descending order.
void WordCounter::count() {

    vector<string> wordList = {"cat", "dog", "mouse", "dog", "cat", "horse", "dog"};

    ds::HashMap<string, int, hashFunc> wordCounts = ds::HashMap<string, int, hashFunc>(16);

    // -------load the data into an unordered_map (hashmap)
    for (string word : wordList) {

        //auto iter = wordCounts.find(word);
        int* currentCountPtr = wordCounts.get(word);

        if (currentCountPtr == nullptr) {
            // found first occurrence of a new word
            wordCounts.add(word, 1);
            cout << word << endl;
        } else {
            // found an additional occurrence of a previously known word
            // increment the count
            (*currentCountPtr)++;
            wordCounts.add(word, *currentCountPtr);
            cout << *currentCountPtr << " occurrences of word = " << word << endl;
        }
    }

    // -------------------- output unsorted summary stats --------------
    cout << "Summary stats:" << endl;

    // copy the data from the unordered_map into a vector, then sort the vector
//    vector<std::pair<string, int>> sortedWordCounts = vector<std::pair<string, int>>{};
    vector<std::pair<string, int>>* sortedWordCounts = nullptr;

//    for (auto wordStat : wordCounts) {
//        sortedWordCounts.emplace_back(wordStat);
//    }
    sortedWordCounts = wordCounts.getVector();

    for (auto wordStat : *sortedWordCounts) {
        cout << wordStat.second << " occurrences of word = " << wordStat.first << endl;
    }

    // --------------------- sort ---------------------------------------
    cout << "Sorted summary stats:" << endl;

    // unordered_map has random access iterator, but cannot be sorted
    // sort(wordCounts.begin(), wordCounts.end(), moreWords);
    // for (auto wordStat: wordCounts) {
    //      cout << wordStat.second << " occurrences of word = " << wordStat.first << endl;
    // }

    // now sort the vector
    sort(sortedWordCounts->begin(), sortedWordCounts->end(), moreWords);

    // ------------------- output the sorted results -------------------
    for (auto wordStat : *sortedWordCounts) {
        cout << wordStat.second << " occurences of word = " << wordStat.first << endl;
    }

    cout << "Analysis complete." << endl;

    } // end method count()

}  // end namespace