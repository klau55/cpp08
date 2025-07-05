#pragma once
#include <stack>
#include <iterator>
#include <deque>

/**
 * MutantStack - An iterable version of std::stack
 * 
 * This class inherits from std::stack and adds iterator functionality
 * by providing access to the underlying container's iterators.
 * 
 * The key insight is that std::stack is a container adapter with a 
 * protected member 'c' that holds the underlying container (default: std::deque).
 * By inheriting from std::stack, we can access this protected member.
 */
template<typename T, typename Container = std::deque<T>>
class MutantStack : public std::stack<T, Container> {
public:
    // Iterator typedefs - using the underlying container's iterators
    typedef typename Container::iterator iterator;
    typedef typename Container::const_iterator const_iterator;
    typedef typename Container::reverse_iterator reverse_iterator;
    typedef typename Container::const_reverse_iterator const_reverse_iterator;
    
    // Default constructor
    MutantStack() : std::stack<T, Container>() {}
    
    // Copy constructor
    MutantStack(const MutantStack& other) : std::stack<T, Container>(other) {}
    
    // Assignment operator
    MutantStack& operator=(const MutantStack& other) {
        if (this != &other) {
            std::stack<T, Container>::operator=(other);
        }
        return *this;
    }
    
    // Destructor
    ~MutantStack() {}
    
    // Iterator methods - forward iterators
    iterator begin() {
        return this->c.begin();
    }
    
    const_iterator begin() const {
        return this->c.begin();
    }
    
    iterator end() {
        return this->c.end();
    }
    
    const_iterator end() const {
        return this->c.end();
    }
    
    // Reverse iterator methods
    reverse_iterator rbegin() {
        return this->c.rbegin();
    }
    
    const_reverse_iterator rbegin() const {
        return this->c.rbegin();
    }
    
    reverse_iterator rend() {
        return this->c.rend();
    }
    
    const_reverse_iterator rend() const {
        return this->c.rend();
    }
    
    // Const iterator methods (C++11 style)
    const_iterator cbegin() const {
        return this->c.cbegin();
    }
    
    const_iterator cend() const {
        return this->c.cend();
    }
    
    const_reverse_iterator crbegin() const {
        return this->c.crbegin();
    }
    
    const_reverse_iterator crend() const {
        return this->c.crend();
    }
};
