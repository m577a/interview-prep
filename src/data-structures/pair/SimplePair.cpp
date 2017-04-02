/*
 * SimplePair.cpp
 *
 *  Created on: Apr 1, 2017
 *      Author: milsted
 */

#include "../../../include/data-structures/pair/SimplePair.h"

namespace ds {

template <typename First, typename Second>
SimplePair<First, Second>::SimplePair(): first(First()), second(Second()) {

}


template <typename First, typename Second>
SimplePair<First, Second>::SimplePair(const First& firstValue, const Second& secondValue): first(firstValue), second(secondValue) {

}


template <typename First, typename Second>
SimplePair<First, Second>::~SimplePair() {
    // TODO Auto-generated destructor stub
}

} /* namespace ds */
