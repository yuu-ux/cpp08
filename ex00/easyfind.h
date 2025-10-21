#ifndef EASYFIND_H
#define EASYFIND_H

#include <iostream>
#include <algorithm>
#include <list>
#include <vector>

template <typename Iter>
void print_iter(Iter first, Iter end) {
    for (Iter it = first; it != end; ++it) {  // NOLINT
        std::cout << *it << ' ';
    }
}

template <typename T>
typename T::iterator easyfind(T& container, int target) {
    return std::find(container.begin(), container.end(), target);
}

#endif
