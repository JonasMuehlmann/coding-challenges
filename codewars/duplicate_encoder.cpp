
#include <iostream>
#include <map>
#include <string>

std::string
duplciate_encoder(const std::string& str)
{
    std::map<char, int> occurrences;
    std::string         new_str;

    for (const auto& c : str)
        {
            occurrences[::tolower(c)]++;
        }
    for (const auto& c : str)
        {
            if (occurrences[::tolower(c)] > 1)
                {
                    new_str.append(")");
                }
            else
                {
                    new_str.append("(");
                }
        }

    return new_str;
}

// int
// main()
// {
//     std::cout << duplciate_encoder("din") << '\n';
//     std::cout << duplciate_encoder("recede") << '\n';
//     std::cout << duplciate_encoder("Success") << '\n';
//     std::cout << duplciate_encoder("(( @") << '\n';
//     return 0;
// }