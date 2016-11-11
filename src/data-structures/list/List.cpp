/*
 * List.cpp
 *
 * Description: List implementation using a circular array
 */

#include "../../../include/data-structures/list/List.h"

namespace ds {

    // @params max - maximum number of elements that can be stored in list
    // Create a List with max_capacity initialized
    // @return pointer to the newly constructed List
    template<typename T> List<T>::List(uint32_t max)
    {
        this->elements = new T[max](); // Note: the empty parenthesis indicate that it should be value-initialized
        this->size = 0;
        this->capacity = max;
        this->first = 0;
        this->last = -1;
    }

    // Default constructor creates a List with max_capacity of DEFAULT_CAPACITY elements
    // @return pointer to the newly constructed List
    template<typename T> List<T>::List()
    {
        this->elements = new T[DEFAULT_CAPACITY](); // Note: the empty parenthesis indicate that it should be value-initialized
        this->size = 0;
        this->capacity = DEFAULT_CAPACITY;
        this->first = 0;
        this->last = -1;
    }

    // Destructor deletes array
    template<typename T> List<T>::~List() {
        delete [] elements; // TODO: what if the array contains objects - should that memory be freed? When the object is removed,
        // if a ref is returned, then the client can delete the object to free the memory
    }

    // Retrieve element from list
    template<typename T> const T& List<T>::retrieve(const T& element) {

        if (size == 0) {
            return NULL;
        }

        // TODO: fix the conditional here
        for (int i = first; i < capacity && i < last; i++) {
            if (elements[i] == element) { // TODO: what if the element is an object - how is equality defined?
                return elements[i];
            }
        }
        /*
        // Loop back to start of array if reached end of array
        head = (head + 1) % capacity;
        */
    }

    // Get next element in list starting with element
    // TODO: what happens if the value later becomes overriden? What does this return type mean here?
    template<typename T> const T& List<T>::get_next(const T& element) const {
        if (size == 0) {
            return NULL;
        }
        // TODO: fix
        return elements[0];
    }

    // Add element to tail of list
    template<typename T> void List<T>::insert_last(const T& element) {
        // If the List is full, we cannot push an element into it
        // as there is no space for it.
        if (size == capacity) {
            throw new ListException("List is full - new element can't be added");
        }

        size++;

        // Loop back to start of array if reached end of array
        first = (last + 1) % capacity;

        // Insert the element in tail
        elements[first] = element;

        return;
    };

    template<typename T> void List<T>::make_empty() {
        // Re-initialize array
        for (int i = 0; i < capacity; i++) {
            elements[i] = NULL;
        }

        this->size = 0;
        this->first = 0;
        this->last = -1;
    }

    // Check whether list is empty
    template<typename T> const bool List<T>::is_empty() const {
        return (size == 0);
    };

    // Check whether list is full
    template<typename T> const bool List<T>::is_full() const {
        return (size == capacity);
    };
}
