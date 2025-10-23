#ifndef SPAN_H
#define SPAN_H

#include <iterator>
#include <stdexcept>
#include <vector>

class Span {
   public:
    Span();
    Span(const Span& other);
    Span& operator=(const Span& rhs);
    ~Span();
    explicit Span(unsigned int N);
    void addNumber(int n);
    std::size_t shortestSpan();
    std::size_t longestSpan();

    template <typename Iterator>
    void addRange(Iterator begin, Iterator end) {
        if (std::distance(begin, end) >
            static_cast<long>((size_ - numbers_.size()))) {
            throw std::length_error("Span is full");
        }
        numbers_.insert(numbers_.end(), begin, end);
    }
    void print_numbers() const;

   private:
    std::vector<int> numbers_;
    unsigned int size_;
};

#endif
