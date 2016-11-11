/*
 * apples *= oranges + 2;
 *
 * total = ++count * 3 + ++count * 5;
 * -- statement modifies the value of a variable more than once and
 * the result is undefined in C++
 *
 * int total = count++ * 3;
 *
 * static_cast<int>(value1)
 * -- cast is checked statically, when the code is compiled
 * -- (int) value1 is the old-style of casting & is more prone to error because
 * it is not always clear what you intended. There are four different kinds of
 * casts, and using the old-style casting syntax covers them all.
 * static_cast<>, const_cast<>, dynamic_cast<>, reinterpret_cast<>
 *
 * produce values of 0 to limit (not including limit)
 * const double limit = 11.0;
 * double random_value = limit * rand() / (RAND_MAX + 1.0);
 *
 * numeric_limits<int>::max() // max int value
 * INT_MAX
 * numeric_limits<int>::digits // number of binary digits
 *
 * bit manipulation
 * as long as bits aren't lost, shifting n bits to the left is equivalent
 * to multiplying the value by 2. Shifting to the right is equivalent to
 * divinding by 2 n times.
 *
 * effect of the right shift operator on signed integers can vary between different
 * systems & it depends on your compiler's implementation.
 *
 */
