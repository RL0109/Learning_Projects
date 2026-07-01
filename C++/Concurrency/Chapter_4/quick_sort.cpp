#include <iostream>
#include <thread>
#include <list>
#include <algorithm>

// A sequential implementation of Quicksort

template<typename T>
std::list<T> sequential_quick_sort(std::list<T> input)
{
    if (input.empty())
    {
        return input;
    }

    std::list<T> result;
    result.splice(result.begin(), input, input.begin());
    T const& pivot= *result.begin();

    auto divide_point=std::partition(input.begin(), input.end(),[&](T const& t) {return t<pivot;});
    std::list<T> lower_part;
    lower_part.splice(lower_part.end(), input, input.begin(), divide_point);
    auto new_lower (
        sequential_quick_sort(std::move(lower_part)));
    auto new_higher(
        sequential_quick_sort(std::move(input)));
    result.splice(result.end(), new_higher);
    result.splice(result.begin(), new_lower);
    return result;
    
    
}


int main() {

    std::list numList = {1,6,8,2,5,9,10,26,14,3,4};

    std::cout << "Original number list \n";
    for (auto nL: numList) {
        std::cout << nL << " ";
    }
    std::cout << "\n";

    std::list sortedList = sequential_quick_sort(numList);
    std::cout << "Sequential quick sort output \n";
    for (auto sL : sortedList) {
        std::cout << sL << " ";
    }
    std::cout << "\n"; 


}