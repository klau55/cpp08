#include "span.hpp"

// Constructor
Span::Span(unsigned int N) : _maxSize(N) {
    _numbers.reserve(N);  // Reserve space for efficiency
}

// Copy constructor
Span::Span(const Span& other) : _numbers(other._numbers), _maxSize(other._maxSize) {
}

// Assignment operator
Span& Span::operator=(const Span& other) {
    if (this != &other) {
        _numbers = other._numbers;
        _maxSize = other._maxSize;
    }
    return *this;
}

// Destructor
Span::~Span() {}

// Add a single number
void Span::addNumber(int number) {
    if (_numbers.size() >= _maxSize) {
        throw SpanFullException();
    }
    _numbers.push_back(number);
}

// Find the shortest span between any two numbers
unsigned int Span::shortestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }
    
    // Create a sorted copy to find minimum adjacent differences
    std::vector<int> sorted_numbers = _numbers;
    std::sort(sorted_numbers.begin(), sorted_numbers.end());
    
    unsigned int min_span = static_cast<unsigned int>(sorted_numbers[1] - sorted_numbers[0]);
    
    // Check all adjacent pairs in sorted array
    for (size_t i = 1; i < sorted_numbers.size(); ++i) {
        unsigned int current_span = static_cast<unsigned int>(sorted_numbers[i] - sorted_numbers[i - 1]);
        if (current_span < min_span) {
            min_span = current_span;
        }
    }
    
    return min_span;
}

// Find the longest span between any two numbers
unsigned int Span::longestSpan() const {
    if (_numbers.size() < 2) {
        throw NoSpanException();
    }
    
    // Find min and max elements
    std::vector<int>::const_iterator min_it = std::min_element(_numbers.begin(), _numbers.end());
    std::vector<int>::const_iterator max_it = std::max_element(_numbers.begin(), _numbers.end());
    
    return static_cast<unsigned int>(*max_it - *min_it);
}

// Utility functions
unsigned int Span::size() const {
    return static_cast<unsigned int>(_numbers.size());
}

unsigned int Span::maxSize() const {
    return _maxSize;
}

bool Span::empty() const {
    return _numbers.empty();
}

bool Span::full() const {
    return _numbers.size() >= _maxSize;
}

// Exception implementations
const char* Span::SpanFullException::what() const throw() {
    return "Span is full: cannot add more numbers";
}

const char* Span::NoSpanException::what() const throw() {
    return "No span available: need at least 2 numbers";
}

const char* Span::RangeTooBigException::what() const throw() {
    return "Range too big: adding this range would exceed span capacity";
}
