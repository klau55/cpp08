#include <iostream>
#include <vector>
#include <list>
#include <deque>
#include <exception>
#include "easyfind.hpp"

template<typename T>
void testContainer(T& container, const std::string& containerName, int searchValue)
{
    std::cout << "\n--- Testing " << containerName << " ---" << std::endl;
    
    // Print container contents
    std::cout << "Container contents: ";
    for (typename T::const_iterator it = container.begin(); it != container.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test searching for the value
    std::cout << "Searching for value: " << searchValue << std::endl;
    
    try {
        typename T::iterator result = easyfind(container, searchValue);
        std::cout << "✓ Found value " << *result << " at position " 
                  << std::distance(container.begin(), result) << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "✗ " << e.what() << std::endl;
    }
}

// Test const version
template<typename T>
void testConstContainer(const T& container, const std::string& containerName, int searchValue)
{
    std::cout << "\n--- Testing const " << containerName << " ---" << std::endl;
    std::cout << "Searching for value: " << searchValue << std::endl;
    
    try {
        typename T::const_iterator result = easyfind(container, searchValue);
        std::cout << "✓ Found value " << *result << " in const container" << std::endl;
    }
    catch (const std::exception& e) {
        std::cout << "✗ " << e.what() << std::endl;
    }
}

int main()
{
    std::cout << "=== EASYFIND FUNCTION TESTS ===" << std::endl;
    
    // Test with std::vector
    std::cout << "\n=================== VECTOR TESTS ===================" << std::endl;
    std::vector<int> vec;
    vec.push_back(10);
    vec.push_back(20);
    vec.push_back(30);
    vec.push_back(40);
    vec.push_back(50);
    
    testContainer(vec, "std::vector", 30);  // Should find at position 2
    testContainer(vec, "std::vector", 10);  // Should find at position 0
    testContainer(vec, "std::vector", 50);  // Should find at position 4
    testContainer(vec, "std::vector", 99);  // Should not find
    
    // Test const vector
    const std::vector<int> constVec(vec);
    testConstContainer(constVec, "std::vector", 20);
    
    // Test with std::list
    std::cout << "\n=================== LIST TESTS ===================" << std::endl;
    std::list<int> lst;
    lst.push_back(100);
    lst.push_back(200);
    lst.push_back(300);
    lst.push_back(400);
    
    testContainer(lst, "std::list", 200);   // Should find
    testContainer(lst, "std::list", 400);   // Should find
    testContainer(lst, "std::list", 150);   // Should not find
    
    // Test with std::deque
    std::cout << "\n=================== DEQUE TESTS ===================" << std::endl;
    std::deque<int> deq;
    deq.push_back(1);
    deq.push_back(2);
    deq.push_back(3);
    deq.push_back(4);
    deq.push_back(5);
    
    testContainer(deq, "std::deque", 3);    // Should find
    testContainer(deq, "std::deque", 1);    // Should find
    testContainer(deq, "std::deque", 7);    // Should not find
    
    // Test edge cases
    std::cout << "\n=================== EDGE CASES ===================" << std::endl;
    
    // Empty container
    std::vector<int> emptyVec;
    testContainer(emptyVec, "empty std::vector", 42);
    
    // Single element container
    std::vector<int> singleVec;
    singleVec.push_back(42);
    testContainer(singleVec, "single-element std::vector", 42);
    testContainer(singleVec, "single-element std::vector", 24);
    
    // Container with duplicate values
    std::vector<int> duplicateVec;
    duplicateVec.push_back(5);
    duplicateVec.push_back(3);
    duplicateVec.push_back(5);
    duplicateVec.push_back(7);
    duplicateVec.push_back(5);
    testContainer(duplicateVec, "duplicate-values std::vector", 5);  // Should find first occurrence
    
    std::cout << "\n=================== TESTS COMPLETE ===================" << std::endl;
    
    return 0;
}
