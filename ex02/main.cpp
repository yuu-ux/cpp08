#include <cassert>
#include <iostream>
#include <string>
#include <vector>

#include "MutantStack.h"

void print_header(const std::string& message) {
    std::cout << "--------------------" << message
              << " test--------------------\n";
}

namespace test {
void top_and_push_test() {
    print_header("top and push");
    MutantStack<int> m_stack;
    std::stack<int> o_stack;

    m_stack.push(1);
    m_stack.push(2);

    o_stack.push(1);
    o_stack.push(2);
    std::cout << "[Check] top(): MutantStack=" << m_stack.top()
              << ", std::stack=" << o_stack.top() << '\n';
    assert(m_stack.top() == o_stack.top());
    std::cout << "✅ Passed\n";
}

void empty_test() {
    print_header("empty");
    MutantStack<int> const m_stack;
    std::stack<int> const o_stack;
    std::cout << "[Check] empty(): MutantStack=" << std::boolalpha
              << m_stack.empty() << ", std::stack=" << o_stack.empty() << '\n';
    assert(m_stack.empty() == o_stack.empty());
    std::cout << "✅ Passed\n";
}

void size_test() {
    print_header("size");
    MutantStack<int> m_stack;
    std::stack<int> o_stack;

    m_stack.push(1);
    m_stack.push(2);

    o_stack.push(1);
    o_stack.push(2);

    std::cout << "[Check] size(): MutantStack=" << m_stack.size()
              << ", std::stack=" << o_stack.size() << '\n';
    assert(m_stack.size() == o_stack.size());
    std::cout << "✅ Passed\n";
}

void pop_test() {
    print_header("pop");
    MutantStack<int> m_stack;
    std::stack<int> o_stack;

    m_stack.push(1);
    m_stack.push(2);
    m_stack.pop();

    o_stack.push(1);
    o_stack.push(2);
    o_stack.pop();

    std::cout << "[Check] top() after pop: MutantStack=" << m_stack.top()
              << ", std::stack=" << o_stack.top() << '\n';
    assert(m_stack.top() == o_stack.top());
    std::cout << "✅ Passed\n";
}

void iter_test() {
    print_header("iter");
    MutantStack<int> m_stack;
    std::vector<int> o_vec;

    m_stack.push(1);
    m_stack.push(2);
    m_stack.push(3);

    for (MutantStack<int>::iterator it = m_stack.begin(); it != m_stack.end();
         ++it) {
        o_vec.push_back(*it);
    }

    std::vector<int> df_vec;
    for (int i = 1; i <= 3; ++i) {
        df_vec.push_back(i);
    }
    std::cout << "[Check] iterator contents: MutantStack=[ ";
    for (int i = 0; i < 3; ++i) std::cout << o_vec[i] << " ";
    std::cout << "], expected=[ ";
    for (int i = 0; i < 3; ++i) std::cout << df_vec[i] << " ";
    std::cout << "]" << '\n';
    assert(o_vec == df_vec);
    std::cout << "✅ Passed\n";
}
}  // namespace test

int main() {
    test::top_and_push_test();
    test::empty_test();
    test::size_test();
    test::pop_test();
    test::iter_test();
    std::cout << "\nAll MutantStack tests passed." << '\n';
    return 0;
}
