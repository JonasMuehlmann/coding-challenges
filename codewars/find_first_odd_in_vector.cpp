#include <algorithm>
#include <iostream>
#include <map>
#include <numeric>
#include <vector>

int
findOdd(const std::vector<int>& numbers)
{
    std::map<int, int> occurrences;

    // clang-format off
    std::for_each(numbers.begin(), numbers.end(),
        [&occurrences, &numbers](const auto& item){occurrences[item]++;});

    return *std::find_if(numbers.begin(), numbers.end(),
        [&occurrences](const auto& item) {return occurrences.at(item) % 2 == 1;});
    // clang-format on
}

int
findOdd2(const std::vector<int>& numbers)
{
    // Accumulates a value resulting of an operation (XOR in this case) applied to the accumulation and each element
    //
    // Starting at 0, as indicated with the third parameter, we XOR it with each element in numbers
    //
    // XORing a number an even amount of times gives you 0 and does not increase the accumulation
    //
    // XORing a number an odd amount of times gives you the number itself,
    // since there is only one number occurring an odd amount of times,
    // it will be the only one increasing the accumulation's value and will be the one returned

    return std::accumulate(numbers.cbegin(), numbers.cend(), 0, std::bit_xor<>());
}

// int
// main()
// {
//     std::cout << findOdd2(
//         std::vector<int>{20, 1, -1, 2, -2, 3, 3, 5, 5, 1, 2, 4, 20, 4, -1, -2, 5})
//               << '\n';
//     std::cout << findOdd2(std::vector<int>{1, 1, 2, -2, 5, 2, 4, 4, -1, -2, 5}) << '\n';
//     std::cout << findOdd2(std::vector<int>{20, 1, 1, 2, 2, 3, 3, 5, 5, 4, 20, 4, 5})
//               << '\n';
//     std::cout << findOdd2(std::vector<int>{10}) << '\n';
//     std::cout << findOdd2(std::vector<int>{1, 1, 1, 1, 1, 1, 10, 1, 1, 1, 1}) << '\n';
//     return 0;
// }
