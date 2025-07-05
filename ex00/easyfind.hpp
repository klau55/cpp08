#pragma once
#include <algorithm>
#include <stdexcept>

/**
 * Template function to find the first occurrence of a value in a container
 * @param container The container to search in (type T)
 * @param value The integer value to find
 * @return Iterator to the first occurrence of the value
 * @throws std::runtime_error if the value is not found
 */
template<typename T>
typename T::iterator easyfind(T& container, int value)
{
    typename T::iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    
    return it;
}

/**
 * Const version of easyfind for const containers
 * @param container The const container to search in (type T)
 * @param value The integer value to find
 * @return Const iterator to the first occurrence of the value
 * @throws std::runtime_error if the value is not found
 */
template<typename T>
typename T::const_iterator easyfind(const T& container, int value)
{
    typename T::const_iterator it = std::find(container.begin(), container.end(), value);
    
    if (it == container.end())
        throw std::runtime_error("Value not found in container");
    
    return it;
}
