/*
 * SimplePair.h
 *
 *  Created on: Apr 1, 2017
 *      Author: milsted
 */

#ifndef INCLUDE_DATA_STRUCTURES_PAIR_SIMPLEPAIR_H_
#define INCLUDE_DATA_STRUCTURES_PAIR_SIMPLEPAIR_H_

namespace ds {

template <typename First, typename Second>
class SimplePair {
public:
    First first;
    Second second;

    SimplePair();
    SimplePair(const First& firstValue, const Second& secondValue);
    virtual ~SimplePair();
};

} /* namespace ds */

#endif /* INCLUDE_DATA_STRUCTURES_PAIR_SIMPLEPAIR_H_ */
