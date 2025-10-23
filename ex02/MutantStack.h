#ifndef MUTANTSTACK_H
#define MUTANTSTACK_H

#include <deque>
#include <stack>

template <typename T, typename Container = std::deque<T> >
class MutantStack : public std::stack<T, Container> {
   public:
    MutantStack() : std::stack<T>() {};
    MutantStack(const MutantStack& other) : std::stack<T>(other) {};
    MutantStack& operator=(const MutantStack& rhs) {
        if (this != rhs) {
            std::stack<T>::operator=(rhs);
        }
        return *this;
    };
    virtual ~MutantStack() {};

    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;

    iterator begin() { return this->c.begin(); }
    iterator end() { return this->c.end(); }

    const_iterator begin() const { return this->c.begin(); }
    const_iterator end() const { return this->c.end(); }
};

#endif
