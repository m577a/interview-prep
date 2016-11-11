/*
 * Queue.h
 *
 */

#ifndef QUEUE_H_
#define QUEUE_H_

#include <stdbool.h>
#include <stdint.h>
#include <stdexcept>

namespace ds {

    template<typename T> class Queue {
    private:
        T* elements;            // queue elements
        uint32_t capacity;      // queue capacity
        uint32_t size;          // current queue size
        uint32_t head;          // index of the first element
        uint32_t tail;          // index of the last element
        const static uint32_t DEFAULT_CAPACITY = 10;

        struct QueueException: public std::runtime_error
        {
            QueueException(const std::string& message)
                : std::runtime_error(message) {}
        };

        Queue(const Queue&);
        Queue& operator=(const Queue&);

    public:
        Queue();
        Queue(uint32_t max);
        ~Queue();

        const T& dequeue();
        const T& peek() const; // Note: the const after the method name indicates that the method can't change the member variables
        void enqueue(const T& element);
        void make_empty();
        bool is_empty() const;
        bool is_full() const;

        int get_tail() { return tail; }
        int get_head() { return head; }
        int get_capacity()  { return capacity; }
        int get_size() { return size; }
    };
}
#endif /* QUEUE_H_ */
