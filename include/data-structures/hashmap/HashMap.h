#ifndef HASHMAP_H_
#define HASHMAP_H_

#include <vector>
//  #include <list>

#include "../list/SinglyLinkedList.h"

using namespace std;

namespace ds {
	template <typename Key, typename Value, typename HashFunction> class HashMap {
		private:
			vector<SinglyLinkedList<pair<Key,Value>>>* keyValueMap;
            int hashMapSize = 0;
            HashFunction hashFunction;
            
		public:
			HashMap(int size);
			
			virtual ~HashMap();
			
			void add(Key key, Value value);
			
			Value* get(Key key);
			
			vector<pair<Key, Value>>* getVector(); 
	};
} /* namespace ds */

#endif   /* HASHMAP_H_ */
