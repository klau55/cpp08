#pragma once 

#include <vector>
#include <algorithm>
#include <stdexcept>
#include <iterator>

class Span {
private:
    std::vector<int> _numbers;
    unsigned int _maxSize;

public:
    // Constructor
    explicit Span(unsigned int N);
    
    // Copy constructor
    Span(const Span& other);
    
    // Assignment operator
    Span& operator=(const Span& other);
    
    // Destructor
    ~Span();
    
    // Member functions
    void addNumber(int number);
    
    // Template function for range-based addition
    template<typename Iterator>
    void addNumbers(Iterator begin, Iterator end);
    
    unsigned int shortestSpan() const;
    unsigned int longestSpan() const;
    
    // Utility functions
    unsigned int size() const;
    unsigned int maxSize() const;
    bool empty() const;
    bool full() const;
    
    // Custom exception classes
    class SpanFullException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class NoSpanException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
    
    class RangeTooBigException : public std::exception {
    public:
        virtual const char* what() const throw();
    };
};

// Template function implementation (must be in header)
template<typename Iterator>
void Span::addNumbers(Iterator begin, Iterator end) {
    // Calculate the distance between iterators
    size_t distance = std::distance(begin, end);
    
    // Check if adding this range would exceed capacity
    if (_numbers.size() + distance > _maxSize) {
        throw RangeTooBigException();
    }
    
    // Add all numbers from the range
    _numbers.insert(_numbers.end(), begin, end);
}
