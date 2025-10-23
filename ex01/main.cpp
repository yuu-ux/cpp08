#include <cassert>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <vector>

#include "Span.h"

int main() {
    try {
        // --- 基本テスト ---
        {
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

        // --- 容量オーバーテスト ---
        {
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

        // --- 要素数不足テスト ---
        {
            Span sp(5);
            sp.addNumber(42);
            try {
                sp.shortestSpan();
                assert(false && "Exception not thrown with only one element");
            } catch (const std::exception &e) {
                std::cout << "[OK] Single element exception test passed\n";
            }
        }

        // --- 10,000件テスト ---
        {
            const unsigned int N = 10000;  // NOLINT
            Span sp(N);
            std::srand(
                static_cast<unsigned int>(std::time(nullptr)));  // NOLINT
            for (unsigned int i = 0; i < N; ++i) {
                sp.addNumber(std::rand());  // NOLINT
            }
            std::cout << "[INFO] shortestSpan: " << sp.shortestSpan() << "\n";
            std::cout << "[INFO] longestSpan: " << sp.longestSpan() << "\n";
            std::cout << "[OK] Large-scale test (10,000 numbers) passed\n";
        }

        // --- 範囲追加テスト ---
        {
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

        std::cout << "\n✅ All tests passed successfully.\n";

    } catch (const std::exception &e) {
        std::cerr << "❌ Unexpected exception: " << e.what() << '\n';
        return 1;
    }

    return 0;
}
