#include "Span.h"

#include <algorithm>
#include <iostream>
#include <stdexcept>
#include <vector>

Span::Span(unsigned int N) : numbers_(0), size_(N) {}

void Span::addNumber(int n) {
    if (numbers_.size() >= size_) {
        throw std::length_error("Span is full");
    };
    numbers_.push_back(n);
}

Span::Span(const Span& other) : numbers_(other.numbers_), size_(other.size_) {}

Span& Span::operator=(const Span& rhs) {
    if (this != &rhs) {
        Span tmp(rhs);
        std::swap(this->numbers_, tmp.numbers_);
        std::swap(this->size_, tmp.size_);
    }
    return *this;
}

Span::~Span() {}

std::vector<int> sorted(const std::vector<int>& v) {
    std::vector<int> copy = v;
    std::sort(copy.begin(), copy.end());
    return copy;
}

std::size_t Span::shortestSpan() {
    std::size_t const numbers_size = numbers_.size();
    if (numbers_size < 2) {
        throw std::logic_error("need at least two numbers");
    }
    std::vector<int> sorted_numbers = sorted(numbers_);
    std::size_t ans = sorted_numbers[1] - sorted_numbers[0];
    for (std::size_t i = 1; i < numbers_size - 1; ++i) {
        std::size_t const tmp = sorted_numbers[i + 1] - sorted_numbers[i];
        ans = std::min(ans, tmp);
    }
    return ans;
}

std::size_t Span::longestSpan() {
    std::size_t const numbers_size = numbers_.size();
    if (numbers_size < 2) {
        throw std::logic_error("need at least two numbers");
    }
    int const max_num = *std::max_element(numbers_.begin(), numbers_.end());
    int const min_num = *std::min_element(numbers_.begin(), numbers_.end());
    return max_num - min_num;
}

void Span::print_numbers() const {
    for (std::size_t i = 0; i < numbers_.size(); ++i) {
        std::cout << numbers_[i] << ' ';
    }
}
