#include "easyfind.h"

int main() {
    std::cout << "vector test\n";
    std::vector<int> vec;
    vec.push_back(1);
    vec.push_back(2);
    vec.push_back(3);
    {
        const std::vector<int>::iterator res = easyfind(vec, 2);
        if (res == vec.end()) {
            std::cout << "not found\n";
        } else {
            print_iter(res, vec.end());
            std::cout << '\n';
        }
    }

    {
        const std::vector<int>::iterator res = easyfind(vec, 10);  // NOLINT
        if (res == vec.end()) {
            std::cout << "not found\n";
        } else {
            print_iter(res, vec.end());
            std::cout << '\n';
        }
    }

    std::cout << "\nlist test\n";
    std::list<int> lis;
    lis.push_back(1);
    lis.push_back(2);
    lis.push_back(3);
    {
        const std::list<int>::iterator res = easyfind(lis, 2);
        if (res == lis.end()) {
            std::cout << "not found\n";
        } else {
            print_iter(res, lis.end());
            std::cout << '\n';
        }
    }

    {
        const std::list<int>::iterator res = easyfind(lis, 10);  // NOLINT
        if (res == lis.end()) {
            std::cout << "not found\n";
        } else {
            print_iter(res, lis.end());
            std::cout << '\n';
        }
    }
}
