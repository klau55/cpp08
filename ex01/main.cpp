#include <iostream>
#include <vector>
#include <list>
#include <random>
#include <chrono>
#include <iomanip>
#include "span.hpp"

// Test colors for output
#define GREEN "\033[32m"
#define RED "\033[31m"
#define YELLOW "\033[33m"
#define BLUE "\033[34m"
#define MAGENTA "\033[35m"
#define CYAN "\033[36m"
#define RESET "\033[0m"

// Test the required example from the exercise
void testRequiredExample() {
    std::cout << BLUE << "\n=== REQUIRED EXAMPLE TEST ===" << RESET << std::endl;
    
    try {
        Span sp = Span(5);
        sp.addNumber(6);
        sp.addNumber(3);
        sp.addNumber(17);
        sp.addNumber(9);
        sp.addNumber(11);
        
        std::cout << "Shortest span: " << sp.shortestSpan() << std::endl;
        std::cout << "Longest span: " << sp.longestSpan() << std::endl;
        
        std::cout << GREEN << "✓ Required example passed!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ Required example failed: " << e.what() << RESET << std::endl;
    }
}

// Test edge cases
void testEdgeCases() {
    std::cout << BLUE << "\n=== EDGE CASES TEST ===" << RESET << std::endl;
    
    // Test empty span
    try {
        Span empty_span(10);
        empty_span.shortestSpan();
        std::cout << RED << "✗ Empty span should throw exception" << RESET << std::endl;
    } catch (const Span::NoSpanException& e) {
        std::cout << GREEN << "✓ Empty span correctly throws exception: " << e.what() << RESET << std::endl;
    }
    
    // Test single element
    try {
        Span single_span(10);
        single_span.addNumber(42);
        single_span.longestSpan();
        std::cout << RED << "✗ Single element span should throw exception" << RESET << std::endl;
    } catch (const Span::NoSpanException& e) {
        std::cout << GREEN << "✓ Single element span correctly throws exception: " << e.what() << RESET << std::endl;
    }
    
    // Test span overflow
    try {
        Span small_span(2);
        small_span.addNumber(1);
        small_span.addNumber(2);
        small_span.addNumber(3);  // This should throw
        std::cout << RED << "✗ Span overflow should throw exception" << RESET << std::endl;
    } catch (const Span::SpanFullException& e) {
        std::cout << GREEN << "✓ Span overflow correctly throws exception: " << e.what() << RESET << std::endl;
    }
    
    // Test identical numbers
    try {
        Span identical_span(3);
        identical_span.addNumber(5);
        identical_span.addNumber(5);
        identical_span.addNumber(5);
        
        std::cout << "Identical numbers - Shortest span: " << identical_span.shortestSpan() << std::endl;
        std::cout << "Identical numbers - Longest span: " << identical_span.longestSpan() << std::endl;
        std::cout << GREEN << "✓ Identical numbers test passed!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ Identical numbers test failed: " << e.what() << RESET << std::endl;
    }
}

// Test range-based addition
void testRangeAddition() {
    std::cout << BLUE << "\n=== RANGE ADDITION TEST ===" << RESET << std::endl;
    
    // Test with vector
    try {
        Span span_vec(10);
        std::vector<int> numbers = {1, 3, 5, 7, 9, 11, 13, 15};
        span_vec.addNumbers(numbers.begin(), numbers.end());
        
        std::cout << "Vector range - Size: " << span_vec.size() << std::endl;
        std::cout << "Vector range - Shortest span: " << span_vec.shortestSpan() << std::endl;
        std::cout << "Vector range - Longest span: " << span_vec.longestSpan() << std::endl;
        std::cout << GREEN << "✓ Vector range addition passed!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ Vector range addition failed: " << e.what() << RESET << std::endl;
    }
    
    // Test with list
    try {
        Span span_list(8);
        std::list<int> numbers = {100, 200, 50, 150, 75, 125};
        span_list.addNumbers(numbers.begin(), numbers.end());
        
        std::cout << "List range - Size: " << span_list.size() << std::endl;
        std::cout << "List range - Shortest span: " << span_list.shortestSpan() << std::endl;
        std::cout << "List range - Longest span: " << span_list.longestSpan() << std::endl;
        std::cout << GREEN << "✓ List range addition passed!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ List range addition failed: " << e.what() << RESET << std::endl;
    }
    
    // Test range overflow
    try {
        Span small_span(3);
        std::vector<int> big_range = {1, 2, 3, 4, 5};
        small_span.addNumbers(big_range.begin(), big_range.end());
        std::cout << RED << "✗ Range overflow should throw exception" << RESET << std::endl;
    } catch (const Span::RangeTooBigException& e) {
        std::cout << GREEN << "✓ Range overflow correctly throws exception: " << e.what() << RESET << std::endl;
    }
}

// Test large dataset (10,000+ numbers)
void testLargeDataset() {
    std::cout << BLUE << "\n=== LARGE DATASET TEST (10,000 numbers) ===" << RESET << std::endl;
    
    const unsigned int SIZE = 10000;
    
    try {
        auto start = std::chrono::high_resolution_clock::now();
        
        Span large_span(SIZE);
        
        // Generate random numbers
        std::random_device rd;
        std::mt19937 gen(rd());
        std::uniform_int_distribution<> dis(1, 100000);
        
        std::vector<int> random_numbers;
        random_numbers.reserve(SIZE);
        
        for (unsigned int i = 0; i < SIZE; ++i) {
            random_numbers.push_back(dis(gen));
        }
        
        // Add using range-based addition
        large_span.addNumbers(random_numbers.begin(), random_numbers.end());
        
        auto end_generation = std::chrono::high_resolution_clock::now();
        
        // Calculate spans
        unsigned int shortest = large_span.shortestSpan();
        unsigned int longest = large_span.longestSpan();
        
        auto end_calculation = std::chrono::high_resolution_clock::now();
        
        // Calculate durations
        auto generation_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_generation - start);
        auto calculation_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_calculation - end_generation);
        
        std::cout << "Dataset size: " << large_span.size() << std::endl;
        std::cout << "Shortest span: " << shortest << std::endl;
        std::cout << "Longest span: " << longest << std::endl;
        std::cout << "Generation time: " << generation_time.count() << " ms" << std::endl;
        std::cout << "Calculation time: " << calculation_time.count() << " ms" << std::endl;
        
        std::cout << GREEN << "✓ Large dataset test passed!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ Large dataset test failed: " << e.what() << RESET << std::endl;
    }
}

// Test even larger dataset (100,000 numbers)
void testVeryLargeDataset() {
    std::cout << BLUE << "\n=== VERY LARGE DATASET TEST (100,000 numbers) ===" << RESET << std::endl;
    
    const unsigned int SIZE = 100000;
    
    try {
        auto start = std::chrono::high_resolution_clock::now();
        
        Span very_large_span(SIZE);
        
        // Generate sequential numbers with some gaps
        std::vector<int> sequential_numbers;
        sequential_numbers.reserve(SIZE);
        
        for (unsigned int i = 0; i < SIZE; ++i) {
            sequential_numbers.push_back(i * 3);  // 0, 3, 6, 9, ...
        }
        
        // Add using range-based addition
        very_large_span.addNumbers(sequential_numbers.begin(), sequential_numbers.end());
        
        auto end_generation = std::chrono::high_resolution_clock::now();
        
        // Calculate spans
        unsigned int shortest = very_large_span.shortestSpan();
        unsigned int longest = very_large_span.longestSpan();
        
        auto end_calculation = std::chrono::high_resolution_clock::now();
        
        // Calculate durations
        auto generation_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_generation - start);
        auto calculation_time = std::chrono::duration_cast<std::chrono::milliseconds>(end_calculation - end_generation);
        
        std::cout << "Dataset size: " << very_large_span.size() << std::endl;
        std::cout << "Shortest span: " << shortest << std::endl;
        std::cout << "Longest span: " << longest << std::endl;
        std::cout << "Generation time: " << generation_time.count() << " ms" << std::endl;
        std::cout << "Calculation time: " << calculation_time.count() << " ms" << std::endl;
        
        std::cout << GREEN << "✓ Very large dataset test passed!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ Very large dataset test failed: " << e.what() << RESET << std::endl;
    }
}

// Test copy constructor and assignment operator
void testCopyAndAssignment() {
    std::cout << BLUE << "\n=== COPY AND ASSIGNMENT TEST ===" << RESET << std::endl;
    
    try {
        // Original span
        Span original(10);
        original.addNumber(1);
        original.addNumber(5);
        original.addNumber(3);
        
        // Copy constructor
        Span copy(original);
        std::cout << "Copy - Size: " << copy.size() << ", Shortest: " << copy.shortestSpan() << std::endl;
        
        // Assignment operator
        Span assigned(20);
        assigned = original;
        std::cout << "Assigned - Size: " << assigned.size() << ", Longest: " << assigned.longestSpan() << std::endl;
        
        std::cout << GREEN << "✓ Copy and assignment test passed!" << RESET << std::endl;
    } catch (const std::exception& e) {
        std::cout << RED << "✗ Copy and assignment test failed: " << e.what() << RESET << std::endl;
    }
}

int main() {
    std::cout << CYAN << "===========================================" << RESET << std::endl;
    std::cout << CYAN << "           SPAN CLASS TESTS               " << RESET << std::endl;
    std::cout << CYAN << "===========================================" << RESET << std::endl;
    
    testRequiredExample();
    testEdgeCases();
    testRangeAddition();
    testCopyAndAssignment();
    testLargeDataset();
    testVeryLargeDataset();
    
    std::cout << CYAN << "\n===========================================" << RESET << std::endl;
    std::cout << CYAN << "           ALL TESTS COMPLETED            " << RESET << std::endl;
    std::cout << CYAN << "===========================================" << RESET << std::endl;
    
    return 0;
}
