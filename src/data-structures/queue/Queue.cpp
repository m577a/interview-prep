/*
 * Queue.cpp
 *
 * Description: Queue implementation using a circular array
 */

#include "../../../include/data-structures/queue/Queue.h"
#include <cstddef>

namespace ds {

    // @params max - maximum number of elements that can be stored in queue
    // Create a Queue with max_capacity initialized
    // @return pointer to the newly constructed Queue
    template<typename T> Queue<T>::Queue(uint32_t max)
    {
        this->elements = new T[max](); // Note: the empty parenthesis indicate that it should be value-initialized
        this->size = 0;
        this->capacity = max;
        this->head = 0;
        this->tail = -1;
    }

    // Default constructor creates a Queue with max_capacity of DEFAULT_CAPACITY elements
    // @return pointer to the newly constructed Queue
    template<typename T> Queue<T>::Queue()
    {
        this->elements = new T[DEFAULT_CAPACITY](); // Note: the empty parenthesis indicate that it should be value-initialized
        this->size = 0;
        this->capacity = DEFAULT_CAPACITY;
        this->head = 0;
        this->tail = -1;
    }

    // Destructor deletes array
    template<typename T> Queue<T>::~Queue() {
        delete [] elements; // TODO: what if the array contains objects - should that memory be freed? When the object is dequeued,
        // if a ref is returned, then the client can delete the object to free the memory
    }

    // Remove element from head of queue
    template<typename T> const T& Queue<T>::dequeue() {

        if (size == 0) {
            return nullptr;
        }

        T element = elements[head];
        elements[head] = nullptr;
        // Removing an element is equivalent to incrementing index of head by one
        // TODO: is this bad design if the queue holds objects, because we are maintaining
        // a reference to the "deleted" object
        size--;

        // Loop back to start of array if reached end of array
        head = (head + 1) % capacity;

        return element;
    }

    // Peek at element at head of queue
    // TODO: what happens if the value later becomes overriden? What does this return type mean here?
    template<typename T> const T& Queue<T>::peek() const {
        if (size == 0) {
            return nullptr;
        }
        return elements[head];
    }

    // Add element to tail of queue
    template<typename T> void Queue<T>::enqueue(const T& element) {
        // If the Queue is full, we cannot push an element into it
        // as there is no space for it.
        if (size == capacity) {
            throw new QueueException("Queue is full - new element can't be added");
        }

        size++;

        // Loop back to start of array if reached end of array
        tail = (tail + 1) % capacity;

        // Insert the element in tail
        elements[tail] = element;

        return;
    };

    template<typename T> void Queue<T>::make_empty() {
        // Re-initialize array
        for (int i = 0; i < capacity; i++) {
            elements[i] = nullptr;
        }

        this->size = 0;
        this->head = 0;
        this->tail = -1;
    }

    // Check whether queue is empty
    template<typename T> bool Queue<T>::is_empty() const {
        return (size == 0);
    };

    // Check whether queue is full
    template<typename T> bool Queue<T>::is_full() const {
        return (size == capacity);
    };
}
