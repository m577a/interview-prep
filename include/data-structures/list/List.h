/*
 * List.h
 *
 */

#ifndef LIST_H_
#define LIST_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdexcept>

namespace ds {

    template<typename T> class List {
    private:
        T* elements;            // list elements
        uint32_t capacity;      // list capacity
        uint32_t size;          // current list size
        uint32_t first;         // index of the first element
        uint32_t last;          // index of the last element
        const static uint32_t DEFAULT_CAPACITY = 10;
        enum RelationType { LESS, EQUAL, GREATER };

        struct ListException: public std::runtime_error
        {
            ListException(const std::string& message)
                : std::runtime_error(message) {}
        };

        List(const List&);
        List& operator=(const List&);

    public:
        List();
        List(uint32_t max);
        ~List();

        void insert_last(const T& element);
        void insert_at(const T& element, const int insert_index);
        void remove(const T& element);
        const T& retrieve(const T& element);
        const T& get_next(const T& element) const;
        const bool is_found(const T& element) const;
        const RelationType compareTo(const T& element);
        void make_empty();
        const bool is_empty() const;
        const bool is_full() const;

        int get_first() { return first; }
        int get_last() { return last; }
        int get_capacity()  { return capacity; }
        int get_size() { return size; }
    };
}
#endif /* LIST_H_ */
