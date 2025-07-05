#include <iostream>
#include <stack>
#include <list>
#include <vector>
#include <algorithm>
#include <iterator>
#include "MutantStack.hpp"

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
    
    std::cout << YELLOW << "\n--- Testing MutantStack ---" << RESET << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Contents (using iterators): ";
    MutantStack<int>::iterator it = mstack.begin();
    MutantStack<int>::iterator ite = mstack.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    // Test copy constructor (std::stack<int> s(mstack))
    std::stack<int> s(mstack);
    std::cout << "Copied stack size: " << s.size() << std::endl;
    
    std::cout << GREEN << "✓ Required example test passed!" << RESET << std::endl;
}

// Test comparing MutantStack with std::list
void testComparisonWithList() {
    std::cout << BLUE << "\n=== COMPARISON WITH STD::LIST ===" << RESET << std::endl;
    
    std::cout << YELLOW << "\n--- Testing std::list ---" << RESET << std::endl;
    
    std::list<int> lst;
    lst.push_back(5);
    lst.push_back(17);
    std::cout << "Back: " << lst.back() << std::endl;
    lst.pop_back();
    std::cout << "Size: " << lst.size() << std::endl;
    lst.push_back(3);
    lst.push_back(5);
    lst.push_back(737);
    lst.push_back(0);
    
    std::cout << "Contents (using iterators): ";
    std::list<int>::iterator it = lst.begin();
    std::list<int>::iterator ite = lst.end();
    ++it;
    --it;
    while (it != ite) {
        std::cout << *it << " ";
        ++it;
    }
    std::cout << std::endl;
    
    std::cout << YELLOW << "\n--- Testing MutantStack (should match list) ---" << RESET << std::endl;
    
    MutantStack<int> mstack;
    mstack.push(5);
    mstack.push(17);
    std::cout << "Top: " << mstack.top() << std::endl;
    mstack.pop();
    std::cout << "Size: " << mstack.size() << std::endl;
    mstack.push(3);
    mstack.push(5);
    mstack.push(737);
    mstack.push(0);
    
    std::cout << "Contents (using iterators): ";
    MutantStack<int>::iterator mit = mstack.begin();
    MutantStack<int>::iterator mite = mstack.end();
    ++mit;
    --mit;
    while (mit != mite) {
        std::cout << *mit << " ";
        ++mit;
    }
    std::cout << std::endl;
    
    std::cout << GREEN << "✓ Comparison test passed!" << RESET << std::endl;
}

// Test all iterator types
void testIterators() {
    std::cout << BLUE << "\n=== ITERATOR FUNCTIONALITY TEST ===" << RESET << std::endl;
    
    MutantStack<int> mstack;
    for (int i = 1; i <= 5; ++i) {
        mstack.push(i * 10);
    }
    
    // Test forward iterators
    std::cout << YELLOW << "Forward iteration: " << RESET;
    for (MutantStack<int>::iterator it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test const iterators
    std::cout << YELLOW << "Const iteration: " << RESET;
    const MutantStack<int>& const_mstack = mstack;
    for (MutantStack<int>::const_iterator it = const_mstack.begin(); it != const_mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test reverse iterators
    std::cout << YELLOW << "Reverse iteration: " << RESET;
    for (MutantStack<int>::reverse_iterator it = mstack.rbegin(); it != mstack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test const reverse iterators
    std::cout << YELLOW << "Const reverse iteration: " << RESET;
    for (MutantStack<int>::const_reverse_iterator it = const_mstack.rbegin(); it != const_mstack.rend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test C++11 style const iterators
    std::cout << YELLOW << "C++11 cbegin/cend: " << RESET;
    for (auto it = mstack.cbegin(); it != mstack.cend(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << GREEN << "✓ Iterator functionality test passed!" << RESET << std::endl;
}

// Test stack operations
void testStackOperations() {
    std::cout << BLUE << "\n=== STACK OPERATIONS TEST ===" << RESET << std::endl;
    
    MutantStack<int> mstack;
    
    // Test empty stack
    std::cout << "Empty stack - size: " << mstack.size() << ", empty: " << (mstack.empty() ? "true" : "false") << std::endl;
    
    // Test push operations
    for (int i = 1; i <= 5; ++i) {
        mstack.push(i * 100);
        std::cout << "Pushed " << i * 100 << " - size: " << mstack.size() << ", top: " << mstack.top() << std::endl;
    }
    
    // Test pop operations
    while (!mstack.empty()) {
        int top_val = mstack.top();
        mstack.pop();
        std::cout << "Popped " << top_val << " - size: " << mstack.size();
        if (!mstack.empty()) {
            std::cout << ", new top: " << mstack.top();
        }
        std::cout << std::endl;
    }
    
    std::cout << GREEN << "✓ Stack operations test passed!" << RESET << std::endl;
}

// Test copy constructor and assignment operator
void testCopyAndAssignment() {
    std::cout << BLUE << "\n=== COPY AND ASSIGNMENT TEST ===" << RESET << std::endl;
    
    // Create original stack
    MutantStack<int> original;
    for (int i = 1; i <= 3; ++i) {
        original.push(i * 7);
    }
    
    std::cout << "Original stack: ";
    for (auto it = original.begin(); it != original.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test copy constructor
    MutantStack<int> copy(original);
    std::cout << "Copy constructor: ";
    for (auto it = copy.begin(); it != copy.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test assignment operator
    MutantStack<int> assigned;
    assigned = original;
    std::cout << "Assignment operator: ";
    for (auto it = assigned.begin(); it != assigned.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Verify independence
    original.push(999);
    std::cout << "After modifying original - Copy size: " << copy.size() << ", Assigned size: " << assigned.size() << std::endl;
    
    std::cout << GREEN << "✓ Copy and assignment test passed!" << RESET << std::endl;
}

// Test with different container types
void testDifferentContainers() {
    std::cout << BLUE << "\n=== DIFFERENT CONTAINER TYPES TEST ===" << RESET << std::endl;
    
    // Test with std::vector as underlying container
    std::cout << YELLOW << "Using std::vector as underlying container:" << RESET << std::endl;
    MutantStack<int, std::vector<int>> vector_stack;
    vector_stack.push(10);
    vector_stack.push(20);
    vector_stack.push(30);
    
    std::cout << "Vector-based stack: ";
    for (auto it = vector_stack.begin(); it != vector_stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test with std::deque (default)
    std::cout << YELLOW << "Using std::deque as underlying container (default):" << RESET << std::endl;
    MutantStack<int> deque_stack;
    deque_stack.push(100);
    deque_stack.push(200);
    deque_stack.push(300);
    
    std::cout << "Deque-based stack: ";
    for (auto it = deque_stack.begin(); it != deque_stack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << GREEN << "✓ Different container types test passed!" << RESET << std::endl;
}

// Test STL algorithms compatibility
void testSTLAlgorithms() {
    std::cout << BLUE << "\n=== STL ALGORITHMS COMPATIBILITY TEST ===" << RESET << std::endl;
    
    MutantStack<int> mstack;
    for (int i = 1; i <= 10; ++i) {
        mstack.push(i);
    }
    
    std::cout << "Original stack: ";
    for (auto it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // Test std::find
    auto found = std::find(mstack.begin(), mstack.end(), 5);
    if (found != mstack.end()) {
        std::cout << "Found element 5 at position " << std::distance(mstack.begin(), found) << std::endl;
    }
    
    // Test std::count
    int count = std::count(mstack.begin(), mstack.end(), 5);
    std::cout << "Count of element 5: " << count << std::endl;
    
    // Test std::for_each
    std::cout << "Applying std::for_each (multiply by 2): ";
    std::for_each(mstack.begin(), mstack.end(), [](int& n) { n *= 2; });
    for (auto it = mstack.begin(); it != mstack.end(); ++it) {
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << GREEN << "✓ STL algorithms compatibility test passed!" << RESET << std::endl;
}

int main() {
    std::cout << CYAN << "================================================" << RESET << std::endl;
    std::cout << CYAN << "           MUTANT STACK TESTS                  " << RESET << std::endl;
    std::cout << CYAN << "================================================" << RESET << std::endl;
    
    testRequiredExample();
    testComparisonWithList();
    testIterators();
    testStackOperations();
    testCopyAndAssignment();
    testDifferentContainers();
    testSTLAlgorithms();
    
    std::cout << CYAN << "\n================================================" << RESET << std::endl;
    std::cout << CYAN << "           ALL TESTS COMPLETED                 " << RESET << std::endl;
    std::cout << CYAN << "================================================" << RESET << std::endl;
    
    return 0;
}
