#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Span.h"

void print_header(const std::string &message) {
    std::cout << "--------------------" << message
              << " test--------------------\n";
}

namespace test {
void basic_test() {
    print_header("basic");
    Span sp(5);
    sp.addNumber(6);
    sp.addNumber(3);
    sp.addNumber(17);
    sp.addNumber(9);
    sp.addNumber(11);
    assert(sp.shortestSpan() == 2);
    assert(sp.longestSpan() == 14);
    std::cout << "[OK] Basic test passed\n";
}
void out_of_range_test() {
    Span sp(2);
    sp.addNumber(1);
    sp.addNumber(2);
    try {
        sp.addNumber(3);
        assert(false && "Exception not thrown on overflow");
    } catch (const std::exception &e) {
        std::cout << "[OK] Capacity overflow test passed\n";
    }
}

void not_enough_elem() {
    Span sp(5);
    sp.addNumber(42);
    try {
        sp.shortestSpan();
        assert(false && "Exception not thrown with only one element");
    } catch (const std::exception &e) {
        std::cout << "[OK] Single element exception test passed\n";
    }
}

void ten_thousand_test() {
    const unsigned int N = 10000;  // NOLINT
    Span sp(N);
    std::srand(static_cast<unsigned int>(std::time(NULL)));  // NOLINT
    for (unsigned int i = 0; i < N; ++i) {
        sp.addNumber(std::rand());  // NOLINT
    }
    std::cout << "[INFO] shortestSpan: " << sp.shortestSpan() << "\n";
    std::cout << "[INFO] longestSpan: " << sp.longestSpan() << "\n";
    std::cout << "[OK] Large-scale test (10,000 numbers) passed\n";
}

void range_add_test() {
    std::vector<int> vec;
    for (int i = 10; i <= 50; i += 10) {
        vec.push_back(i);
    }
    Span sp(5);
    sp.addRange(vec.begin(), vec.end());
    assert(sp.shortestSpan() == 10);
    assert(sp.longestSpan() == 40);
    std::cout << "[OK] Range add test passed\n";
}
}  // namespace test
int main() {
    try {
        test::basic_test();
        test::out_of_range_test();
        test::not_enough_elem();
        test::ten_thousand_test();
        test::range_add_test();
        std::cout << "\n✅ All tests passed successfully.\n";
    } catch (const std::exception &e) {
        std::cerr << "❌ Unexpected exception: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
