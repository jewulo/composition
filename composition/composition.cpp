// composition.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <numeric>
#include <string>

// https://www.youtube.com/watch?v=AGRWRwi7rD0
template <class It, class Pred>
bool all_of(It first, It last, Pred p)
{
    return std::accumulate(
        first, last, true,
        [&](auto lhs, auto rhs) {
            return lhs && p(rhs);
        });
}

template <class It, class Pred>
bool none_of(It first, It last, Pred p)
{
    return std::accumulate(
        first, last, true,
        [&](auto lhs, auto rhs) {
            return lhs && !p(rhs);
        });
}

template <class It, class Pred>
bool any_of(It first, It last, Pred p)
{
    return std::accumulate(
        first, last, false,
        [&](auto lhs, auto rhs) {
            return lhs || p(rhs);
        });
}

// std::accumulate can be used implicitly via variadic operations and templates
auto sum_fun(auto&&... ts)
{
    return (ts + ...);
}

int main()
{
    std::vector<int> v{ 1, 2, 3, 4, 5, 6, 7, 8, 9, 10 };

    int sum = std::accumulate(std::begin(v), std::end(v), 0);
    std::cout << sum << std::endl;

    int product = std::accumulate(std::begin(v), std::end(v), 1, std::multiplies<>());
    std::cout << product << std::endl;

    std::vector<std::string> strs{ "Hello", " CppCon" };
    auto joined = std::accumulate(std::begin(strs), std::end(strs), std::string());
    std::cout << joined << std::endl;

    std::vector<int> v2{ 1, 2, 3, 4, 5, 6, 7, 8 };
    auto is_even = [](int x) {return x % 2 == 0; };

    std::cout << std::boolalpha;
    std::cout << all_of(std::begin(v2), std::end(v2), is_even) << std::endl;
    std::cout << none_of(std::begin(v2), std::end(v2), is_even) << std::endl;
    std::cout << any_of(std::begin(v2), std::end(v2), is_even) << std::endl;
    std::cout << std::boolalpha;

    std::cout << sum_fun(1, 2, 3, 4) << std::endl;

    int sum2 = std::accumulate(std::begin(v2), std::end(v2), 0, std::plus<>());
    int mul1 = std::accumulate(std::begin(v2), std::end(v2), 1, std::multiplies<>());

    std::vector<int> v3{ 7, 2, 3, 1,  8, 5, 6, 4 };
    int max_int = std::accumulate(
                            std::begin(v3),
                            std::end(v3), 0,
                            [](auto a, auto b){
                                return a > b ? a : b;
                            });
    std::cout << max_int << std::endl;
    
    std::cin.get();
}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
